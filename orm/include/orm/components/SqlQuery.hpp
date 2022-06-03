//
// Created by eldar on 21.05.22.
//

#ifndef orm_SQLQUERY_HPP
#define orm_SQLQUERY_HPP

#include <string>
#include "Column.hpp"

namespace orm::abstraction
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
        operator db::Column<std::string>();

    protected:
        std::string _sqlQuery;
    };
}

#endif //orm_SQLQUERY_HPP
