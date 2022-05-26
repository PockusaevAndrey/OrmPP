#include <iostream>
#include "orm/query/Select.hpp"

using namespace std;
using namespace orm::db;
using namespace orm::abstraction;


class Task : public Table {
public:
    Column<int> id = controller.addColumn<int>(getName(id));
    Column<std::string> status = controller.addColumn<std::string>(getName(status));
    Task(): Table(getName(Task)){};

};
class Task2 : public Table {
public:
    Column<int> id = controller.addColumn<int>("hello");
    Task2(): Table(getName(Task2)){};

};


int main() {
    Task task;
    Task2 task2;
    cout << (std::string) orm::query::Select(task2.id)
            .from(task)
            .where(task.id <
    5 AND task.status == (std::string) "Выполнена")
    .orderBy((task.id << OrderSort::DESC)) << std::endl;

    return 0;
}
