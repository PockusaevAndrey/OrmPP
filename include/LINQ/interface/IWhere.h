//
// Created by eldar on 23.05.22.
//

#ifndef LINQ_IWHERE_H
#define LINQ_IWHERE_H

#include <string>
#include <vector>
#include "../../Linq.h"
#include "LINQ/SqlQuery.hpp"
#include "IOrderBy.h"
#include "../exception/InvalidColumn.hpp"
#include "../exception/InvalidQuery.hpp"

using namespace linq::db;
using namespace linq::abstraction;
using namespace std;

namespace linq::interface
{
    class Where : public SqlQuery
    {
    public:
        Where(string query, Condition condition)
                : SqlQuery(query), _condition(condition)
        {
        }

        OrderBy orderBy(Sort sort)
        {
            return OrderBy(validateQuery(), sort);
        }

        std::string validateQuery() override
        {
            _sqlQuery += "\nWHERE " + _condition.get();

            if (!contains("WHERE "))
            {
                throw InvalidQuery();
            }

            return _sqlQuery;
        }

    private:
        Condition _condition;
    };
}
#endif //LINQ_IWHERE_H
