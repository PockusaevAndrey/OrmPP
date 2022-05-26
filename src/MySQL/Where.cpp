//
// Created by pokys on 25.05.2022.
//

#include "LINQ/query/Where.hpp"

linq::query::Where::Where(std::string query, linq::db::Condition condition)
        : SqlQuery(query), _condition(condition) {
}

std::string linq::query::Where::validateQuery() {
    _sqlQuery += "\nWHERE " + _condition.get();

    if (!contains("WHERE ")) {
        throw InvalidQuery();
    }

    return _sqlQuery;
}

linq::query::OrderBy linq::query::Where::orderBy(linq::db::Sort sort) {
    return {validateQuery(), std::move(sort)};
}
