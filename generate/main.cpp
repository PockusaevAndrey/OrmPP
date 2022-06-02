//
// Created by pokys on 02.06.2022.
//
#include <etddb/MySqlClient.hpp>
#include <fstream>
#include "filesystem"

int main(int argc, char** argv) {
    if (argc < 5) return 11;
    std::filesystem::create_directory("./db/");
    std::ofstream out;
    etd::mysql::Client cli(argv[1], atoi(argv[2]), argv[3], argv[4]);
    auto cursor = cli.cursor("mysql");
    auto result = cursor->executeOne("SHOW DATABASES");

    for (auto &value: result["Database"]) {
        if (
                value == "information_schema" ||
                value == "mysql" ||
                value == "performance_schema" ||
                value == "sys"
                )
            continue;
        out.open("./db/" + value + ".hpp");
        out << "#ifndef ORM_GENERATE_" + value << std::endl;
        out << "#define ORM_GENERATE_" + value << std::endl;
        out << "#include \"orm.hpp\"" << std::endl;
        out << "OrmDatabase(" + value + "," << std::endl;
        cursor = cli.cursor(value);
        auto tables = cursor->executeOne("SHOW TABLES FROM " + value);
        for (auto &[key, table]: tables) {
            for (auto &t: table) {
                out << "OrmTable(" + t + "," << std::endl;
                auto columns = cursor->executeOne("show columns from " + t);
                for (int i = 0; i < columns["Field"].size(); i++) {
                    out << "OrmColumn(" + columns["Type"][i] + ", " + columns["Field"][i] + ")" << std::endl;
                }
                out << ")" << std::endl;
            }
            // todo add function generating
            auto request = (std::string)"select SPECIFIC_NAME as NAME,\n"
                           "       ROUTINES.DTD_IDENTIFIER as DTD_TYPE,\n"
                           "       ROUTINE_DEFINITION AS DEFINITION\n"
                           "from information_schema.ROUTINES\n"
                           "where ROUTINE_TYPE = 'FUNCTION'\n"
                           "  and ROUTINE_SCHEMA = '" + value + "'";
            auto functions = cursor->executeOne(request);
            for (int i = 0; i < functions["NAME"].size(); i++) {
                out << "OrmFunction(" + functions["DTD_TYPE"][i] + ", " + functions["NAME"][i];
                auto func_params = cursor->executeOne(
                        "select DTD_IDENTIFIER from information_schema.PARAMETERS where PARAMETERS.ORDINAL_POSITION > 0 and SPECIFIC_NAME = '"+functions["NAME"][i]+
                "'");
                for (int j = 0; j < func_params["DTD_IDENTIFIER"].size(); j++){
                    out << ", " + func_params["DTD_IDENTIFIER"][j];
                }
                out << ")" << std::endl;
            }
            break;
        }
        out << ")" << std::endl << "#endif //ORM_GENERATE_" + value << std::endl;
        out.close();
    }


    return 0;
}

