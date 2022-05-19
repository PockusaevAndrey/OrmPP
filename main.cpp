//region Logic

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <memory>
#include "any"

#define getName(variable) #variable
using namespace std;

//region Table
class Table
{
public:
    Table() = default;

    Table(string tableName) : _tableName(tableName)
    {
    }


    template<class ...T>
    void InitializationMetadata(string tableName, T... rows)
    {
        string args[]{rows...};
        for (auto &value: args)
        {
            _columnName.emplace_back(value);
        }

        _tableName = std::move(tableName);
        _length = _columnName.size();
    }


    size_t getColumnSize() const
    {
        return _length;
    }

    string getTableName() const
    {
        return _tableName;
    }

    string operator[](int i)
    {
        return _columnName.at(i);
    }

    virtual ~Table() = default;

    template<typename T>
    string operator>(T q)
    {

    }

protected:
    vector<string> _columnName;
    string _tableName;
    size_t _length;
};
//endregion

class Condition
{
public:
    std::string cond;

    Condition(const std::string &cond);

    Condition(const Condition &cond);

    Condition &operator&(Condition cond);

    Condition &operator|(Condition cond);

    std::string get() const;
};


template<typename T>
class Column final
{
public:
    string name;
    T type{};


    Column() = default;

    explicit Column(string name) : name(name)
    {
    }

    Condition operator> (T a){
        return {name + " > " + std::to_string(a)};
    }
    Condition operator< (T a){
        return {name + " < " + std::to_string(a)};
    }

    Condition operator== (std::any a){
        return {name + " == " + std::any_cast<T>(a)};
    }

    virtual ~Column() = default;
};

class invalid_column : public exception {};



Condition::Condition(const std::string &cond)
{
    this->cond = "(" + cond;
};

Condition::Condition(const Condition &cond)
{
    this->cond = "(" + cond.get();
}

Condition &Condition::operator&(Condition cond)
{
    this->cond += " AND " + cond.get();
    return *this;
}

Condition &Condition::operator|(Condition cond)
{
    this->cond += " OR " + cond.get();
    return *this;
}

std::string Condition::get() const
{
    return cond + ")";
}


class Select
{
public:
    template<typename ...T>
    explicit Select(Column<T>... rows)
    {
        int i = 0;

        ([&](auto &row)
        {
            _columnName.emplace_back(static_cast<Column<T>>(row).name);
            i++;
        }(rows), ...);
    }

    Select *from(Table table)
    {
        auto isRow = [&](string row) -> bool
        {
            for (int i = 0; i < table.getColumnSize(); i++)
            {
                if (row == table[i])
                {
                    return true;
                }
            }
            return false;
        };
        for (auto &i: _columnName)
        {
            if (!isRow(i))
            {
                throw invalid_column();
            }
        }
        createQuery(table.getTableName());
        return this;
    }

    string getQuery()
    {
        return _sqlQuery;
    }

    void createQuery(string tableName)
    {

        _sqlQuery = "SELECT " + _columnName[0];
        for (int i = 1; i < _columnName.size(); i++)
        {
            _sqlQuery += ", " + _columnName[i];
        }
        _sqlQuery += "\nFROM " + tableName;
    }

    Select *where(Condition condition)
    {
        _sqlQuery += "\nWHERE " + condition.get();
        return this;
    }

private:
    vector<string> _columnName;
    string _sqlQuery;

};

//class Condition
//{
//public:
//    string delimiter;
//    vector<string> values;
//};
//

//endregion

class Task : public Table
{
public:

    inline static Column<int> id = Column<int>(getName(id));
    inline static Column<std::string> taskNum = Column<string>(getName(taskNum));

    // Initialization table's metadata.
    Task()
    {
        InitializationMetadata(getName(Task),
                               getName(id),
                               getName(taskNum));
    };
};

class Employees : public Table
{
public:

    inline static Column<int> id = Column<int>(getName(id));
    inline static Column<std::string> em = Column<string>(getName(em));

    // Initialization table's metadata.
    Employees()
    {
        InitializationMetadata(getName(Employees),
                               getName(id),
                               getName(em));
    };

};

int main()
{
    int a = 5;
    string q = Select(Task::taskNum, Task::id)
            .from(Task())
            ->where(Task::id == 4 | Task::taskNum == "hello" & Task::id > 5)
            ->getQuery();


    cout << q << endl;



//    string q = Select(Task::taskNum, Task::id)
//            .from(Task())
//            .where(Task::id > 5 | Task::id == 1)
//            ->getQuery();


    return 0;
}
