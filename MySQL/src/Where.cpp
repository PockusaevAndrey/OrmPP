//
// Created by pokys on 25.05.2022.
//

#include "orm/query/Where.hpp"

orm::query::Where::Where(std::string query, orm::db::Condition condition)
        : SqlQuery(query), _condition(condition) {
}

std::string orm::query::Where::validateQuery() {
    _sqlQuery += "\nWHERE " + _condition.get();

    if (!contains("WHERE ")) {
        throw InvalidQuery();
    }

    return _sqlQuery;
}

orm::query::OrderBy orm::query::Where::orderBy(orm::db::Sort sort) {
    return {validateQuery(), std::move(sort)};
}
