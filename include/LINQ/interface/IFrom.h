//
// Created by eldar on 23.05.22.
//

#ifndef LINQ_IFROM_H
#define LINQ_IFROM_H


#include <string>
#include <vector>
#include "../../Linq.h"
#include "LINQ/SqlQuery.hpp"
#include "IWhere.h"
#include "../exception/InvalidColumn.hpp"
#include "../exception/InvalidQuery.hpp"

using namespace linq::db;
using namespace linq::abstraction;
using namespace std;


namespace linq::interface
{
    class From : public SqlQuery
    {
    public:
        From() = default;

        From(string query, Table table, vector <string> columnName)
                : SqlQuery(query), _table(table), _columnName(columnName)
        {
        }

        std::string validateQuery() override
        {
            auto isRow = [&](string row) -> bool
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
                    throw invalid_column();
                }
            }

            _sqlQuery += "\nFROM " + _table.getTableName();

            if (!contains("FROM "))
            {
                throw InvalidQuery();
            }

            return _sqlQuery;
        }

        Where where(Condition condition)
        {
            return Where(validateQuery(), condition);
        }

    private:
        Table _table;
        vector <string> _columnName;
    };
}

#endif //LINQ_IFROM_H
