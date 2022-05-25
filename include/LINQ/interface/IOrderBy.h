//
// Created by eldar on 23.05.22.
//

#ifndef LINQ_IORDERBY_H
#define LINQ_IORDERBY_H

#include <string>
#include <vector>
#include "../../Linq.h"
#include "LINQ/components/SqlQuery.hpp"
#include "../exception/InvalidColumn.hpp"
#include "../exception/InvalidQuery.hpp"

using namespace linq::db;
using namespace linq::abstraction;
using namespace std;


namespace linq::interface
{
    class OrderBy : public SqlQuery
    {
    public:
        OrderBy(string query, Sort sort) : SqlQuery(query), _sort(sort)
        {
        }

        std::string validateQuery() override
        {
            _sqlQuery += "\nORDER BY " + _sort.get();

            if (!contains("ORDER BY "))
            {
                throw InvalidQuery();
            }

            return _sqlQuery;
        }

    private:
        Sort _sort;
    };
}

#endif //LINQ_IORDERBY_H
