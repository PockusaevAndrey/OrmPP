//
// Created by pokys on 25.05.2022.
//

#include "LINQ/query/OrderBy.hpp"
#include "LINQ/Errors.hpp"

std::string linq::query::OrderBy::validateQuery() {
    _sqlQuery += "\nORDER BY " + _sort.get();

    if (!contains("ORDER BY "))
        throw linq::InvalidQuery();

    return _sqlQuery;
}

linq::query::OrderBy::OrderBy(std::string query, linq::db::Sort sort) : SqlQuery(query), _sort(std::move(sort)) {
}