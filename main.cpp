#include <iostream>
#include "TasksDb.hpp"
#include "EmployesDb.hpp"
#include "Config.hpp"
#include "etddb/MySqlClient.hpp"


int main() {
    Config conf;
    EmployesDb emp;

    etd::mysql::Client client(conf.ip, conf.port, conf.login, conf.password);
    auto cursor = client.cursor(emp);
    auto result = cursor->executeOne(
            orm::query::Select(emp.get_employees_f(R"('{"id": 1}')").as("result"))
    );
    for (auto &[key, rows]: result) {
        std::cout << key << ": ";
        for (auto &row: rows) {
            std::cout << row << ", ";
        }
        std::cout << std::endl;
    }

/*    std::cout << (std::string) orm::query::Select(empl.tEmployees.company_id, empl.tEmployees.name)
            .from(tdb.tAllTaskInfo)
            .join(orm::query::LEFT, empl.tEmployees, tdb.tAllTaskInfo.owner_name == empl.tEmployees.name)
            .where(
                    tdb.tAllTaskInfo.id.in({1, 2, 3, 4, 5, 6, 7})
                    & tdb.tAllTaskInfo.company_id.in({1, 2})
            )
            .orderBy(
                    (tdb.tAllTaskInfo.id << orm::db::OrderSort::DESC)
            ).limit(10).offset(10)
              << std::endl;*/
    return 0;
}
