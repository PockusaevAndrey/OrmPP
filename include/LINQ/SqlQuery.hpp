//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_SQLQUERY_HPP
#define LINQ_SQLQUERY_HPP

#include <string>

namespace linq::abstraction
{
    class SqlQuery
    {
    public:
        SqlQuery() = default;

        SqlQuery(std::string query) : _sqlQuery(query)
        {
        }

        std::string getQuery()
        {
            return validateQuery();
        }

        bool contains(std::string value)
        {
            return _sqlQuery.find(value) != std::string::npos;
        }

        virtual std::string validateQuery() = 0;

    protected:
        std::string _sqlQuery;
    };
}

#endif //LINQ_SQLQUERY_HPP
