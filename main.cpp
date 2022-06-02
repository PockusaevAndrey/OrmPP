#include <iostream>
#define ORM_FUNCTION
#include "orm/query/Select.hpp"
#include "orm.hpp"
#include "orm/components/Function.hpp"


OrmDatabase(TasksDb,
            OrmTable(AllTaskInfo, OrmColumn(int, id)
                    OrmColumn(int, task_num)
                    OrmColumn(int, company_id)
                    OrmColumn(std::string, company_name)
                    OrmColumn(std::string, description)
                    OrmColumn(int, status_id)
                    OrmColumn(int, task_types_id)
                    OrmColumn(bool, deleted)
                    OrmColumn(std::string, phone)
                    OrmColumn(int, apartment)
                    OrmColumn(int, entrance)
                    OrmColumn(int, house_id)
                    OrmColumn(int, floor)
                    OrmColumn(int, system)
                    OrmColumn(std::string, contact_citizen_info)
                    OrmColumn(int, creation_date)
                    OrmColumn(int, finish_date)
                    OrmColumn(int, planning_date)
                    OrmColumn(int, received_date)
                    OrmColumn(int, payed_date)
                    OrmColumn(int, orderedDate)
                    OrmColumn(std::string, owner_name)
                    OrmColumn(std::string, user_name)
                    OrmColumn(std::string, finished_user_name)
            )
)

OrmDatabase(EmployesDb,
            OrmTable(Employees, OrmColumn(int, id)
                    OrmColumn(std::string, name)
                    OrmColumn(int, company_id)
                    OrmColumn(int, role_id)
                    OrmColumn(std::string, position)
                    OrmColumn(bool, deleted)
            )
)

int main() {
    TasksDb tdb;
    EmployesDb empl;
    orm::db::Function<int, std::string, int, bool> now("now");
    std::cout << (std::string) orm::query::Select(now(tdb.tAllTaskInfo.id.name, 1, true), empl.tEmployees.name)
            .from(tdb.tAllTaskInfo)
            .join(orm::query::LEFT, empl.tEmployees, tdb.tAllTaskInfo.owner_name == empl.tEmployees.name)
            .where(
                    tdb.tAllTaskInfo.id.in({1, 2, 3, 4, 5, 6, 7})
                    & tdb.tAllTaskInfo.company_id.in({1, 2})
            )
            .orderBy(
                    (tdb.tAllTaskInfo.id << orm::db::OrderSort::DESC)
            ).limit(10)
              << std::endl;
    return 0;
}
