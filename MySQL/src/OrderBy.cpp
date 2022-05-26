//
// Created by pokys on 25.05.2022.
//

#include "orm/query/OrderBy.hpp"
#include "orm/Errors.hpp"

std::string orm::query::OrderBy::validateQuery() {
    _sqlQuery += "\nORDER BY " + _sort.get();

    if (!contains("ORDER BY "))
        throw orm::InvalidQuery();

    return _sqlQuery;
}

orm::query::OrderBy::OrderBy(std::string query, orm::db::Sort sort) : SqlQuery(query), _sort(std::move(sort)) {
}