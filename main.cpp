#include <iostream>
#include "orm/query/Select.hpp"


#define OrmTable(name, realization) \
class name : public orm::db::Table { \
public:                \
name(): Table(#name){};             \
realization                                    \
};

#define OrmColumn(type, name) \
orm::db::Column<type> name = controller.addColumn<type>(#name);

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

OrmTable(Employees, OrmColumn(int, id)
        OrmColumn(std::string, name)
        OrmColumn(int, company_id)
        OrmColumn(int, role_id)
        OrmColumn(std::string, position)
        OrmColumn(bool, deleted)
)

int main() {
    AllTaskInfo task;
    Employees empl;
    std::cout << (std::string) orm::query::Select(task.id, empl.name)
            .from(task)
            .join(orm::query::LEFT, empl, task.owner_name == empl.name)
            .where(
                    task.id.in({1, 2, 3, 4, 5, 6, 7})
                    & task.company_id.in({1, 2})
                    )
            .orderBy(
                    (task.id << orm::db::OrderSort::DESC)
                    )
              << std::endl;

    return 0;
}
