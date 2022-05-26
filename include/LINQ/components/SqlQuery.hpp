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

        SqlQuery(std::string query);

        std::string getQuery();

        bool contains(std::string value);

        virtual std::string validateQuery() = 0;

        operator std::string();

    protected:
        std::string _sqlQuery;
    };
}

#endif //LINQ_SQLQUERY_HPP
