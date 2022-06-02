#pragma once
//
// Created by pokys on 25.05.2022.
//


#include <utility>
#include "orm/Errors.hpp"

template<typename... T>
orm::query::Select<T...>::Select(db::Column <T>... rows) {
    int i = 0;

    ([&](auto &row) {
        _columnName.emplace_back(static_cast<db::Column<T>>(row).name);
        i++;
    }(rows), ...);
}

template<typename... T>
std::string orm::query::Select<T...>::validateQuery() {
    _sqlQuery = "SELECT " + _columnName[0];
    for (int i = 1; i < _columnName.size(); ++i) {
        _sqlQuery += ", " + _columnName[i];
    }

    if (!contains("SELECT ")) {
        throw orm::InvalidQuery();
    }

    return _sqlQuery;
}

template<typename... T>
orm::query::From orm::query::Select<T...>::from(orm::db::Table table) {
    return {validateQuery(), std::move(table), _columnName};
}

template<typename... T>
orm::query::Limit orm::query::Select<T...>::limit(int count) {
    return {validateQuery(), count};
}
