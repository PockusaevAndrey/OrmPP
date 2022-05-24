#include <iostream>
#include "Linq.h"
#include "include/LINQ/interface/ISelect.h"

using namespace std;
using namespace linq::db;
using namespace linq::abstraction;
using namespace linq::interface;



class Task : public Table
{
public:
    inline static auto id = Column<int>(getName(id));
    inline static auto taskNum = Column<string>(getName(taskNum));
    inline static auto status = Column<string>(getName(status));
    inline static auto company_id = Column<int>(getName(company_id));

    Task() : Table(getName(Task), id, taskNum, status, company_id)
    {
    }
};

class Employees : public Table
{
public:
    inline static Column<int> id = Column<int>(getName(id));
    inline static Column<string> name = Column<string>(getName(name));

    Employees() : Table(getName(Employees), id, name)
    {
    }

};


int main()
{
    string simpleSelect =
            Select(Task::taskNum, Task::id, Task::company_id, Task::status)
            .from(Task())
            .getQuery();

    cout << simpleSelect << endl;
    cout << "\n" << endl;



    string middleSelect =
            Select(Task::taskNum, Task::id, Task::company_id, Task::status)
            .from(Task())
            .where(Task::taskNum > "989" OR Task::taskNum == "q" AND Task::id > 8 OR Task::id < 6)
            .getQuery();

    cout << middleSelect << endl;
    cout << "\n" << endl;



    string hardlySelect =
            Select(Task::taskNum, Task::id, Task::company_id, Task::status)
            .from(Task())
            .where(Task::taskNum > "989" OR Task::taskNum == "234235" AND Task::id > 8 OR Task::id < 6 OR
                   Task::id == 6 AND Task::company_id == 213 OR Task::company_id < 25)
            .orderBy(Task::id - OrderSort::ASC & Task::taskNum - OrderSort::DESC & Task::status - OrderSort::DESC).getQuery()
            ;

    cout << hardlySelect << endl;

    return 0;
}
