//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_TABLE_H
#define LINQ_TABLE_H

#include <vector>
#include "Column.h"

namespace etd::linq::databaseComponent
{
    class Table
    {
    public:
        Table() = default;

        template<class ...T>
        Table(std::string tableName, Column<T>... columns);

        template<class ...T>
        void Initialization(Column<T>... columns);

        size_t getColumnSize() const;

        std::string getTableName() const;

        std::string operator[](int i);

        virtual ~Table() = default;

    protected:
        std::vector <std::string> _columnName;
        std::string _tableName;
    };
}
#endif //LINQ_TABLE_H
