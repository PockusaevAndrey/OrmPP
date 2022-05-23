//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_TABLE_H
#define LINQ_TABLE_H

#include <vector>
#include "Column.h"

#define getName(variable) #variable

namespace linq::db
{
    class Table
    {
    public:
        Table() = default;

        template<class ...T>
        Table(std::string tableName, Column<T>... columns) : _tableName(tableName)
        {
            Initialization(columns...);
        }

        template<class ...T>
        void Initialization(Column<T>... columns)
        {
            int i = 0;

            ([&](auto &row)
            {
                static_cast<Column<T>>(row).tableName = _tableName;
                _columnName.emplace_back(static_cast<Column<T>>(row).name);
                i++;
            }(columns), ...);
        }

        size_t getColumnSize() const
        {
            return _columnName.size();
        }

        std::string getTableName() const
        {
            return _tableName;
        }

        std::string operator[](int i)
        {
            return _columnName.at(i);
        }

    protected:
        std::vector<std::string> _columnName{};
        std::string _tableName{};
    };
}
#endif //LINQ_TABLE_H
