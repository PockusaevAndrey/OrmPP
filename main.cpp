#include <iostream>
// Include generating database files
#include "NewObjectsDB.hpp"
#include "EmployesDb.hpp"
#include "Config.hpp"
#include "etddb/MySqlClient.hpp"


int main() {
    Config conf;
    EmployesDb emp;
    NewObjectsDB obj;
    orm::db::Function<int, std::string> count("count");

    etd::mysql::Client client(conf.ip, conf.port, conf.login, conf.password);
    auto cursor = client.cursor(emp);
    std::string request =
            orm::query::Select(emp.tEmployees.id,
                               ((orm::db::Column<std::string>) orm::query::Select(count(obj.tObjects.company_id))
                                       .from(obj.tObjects)
                                       .where(obj.tObjects.company_id == emp.tEmployees.company_id)).as("object_count")
            ).from(emp.tEmployees);
    auto result = cursor->executeOne(
            request
    );
    for (auto &[key, rows]: result) {
        std::cout << key << ": ";
        for (auto &row: rows) {
            std::cout << row << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
