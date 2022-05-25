//
// Created by pokys on 25.05.2022.
//

#include "LINQ/query/From.hpp"

#include <utility>
#include "LINQ/components/Table.h"
#include "LINQ/Errors.hpp"

linq::query::From::From(std::string query, linq::db::Table table, std::vector<std::string> columnName) : SqlQuery(
        std::move(query)), _table(std::move(table)), _columnName(std::move(columnName)) {
}

std::string linq::query::From::validateQuery()
{
    auto isRow = [&](const std::string& row) -> bool
    {
        for (int i = 0; i < _table.getColumnSize(); i++)
        {
            if (row == _table[i])
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
            throw InvalidColumn();
        }
    }

    _sqlQuery += "\nFROM " + _table.getTableName();

    if (!contains("FROM "))
    {
        throw InvalidQuery();
    }

    return _sqlQuery;
}

linq::query::Where linq::query::From::where(Condition condition)
{
    return linq::query::Where(validateQuery(), condition);
}
