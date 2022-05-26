#pragma once
//
// Created by pokys on 25.05.2022.
//


#include <utility>
#include "LINQ/Errors.hpp"

template<typename... T>
linq::query::Select<T...>::Select(db::Column <T>... rows) {
    int i = 0;

    ([&](auto &row) {
        _columnName.emplace_back(static_cast<db::Column<T>>(row).name);
        i++;
    }(rows), ...);
}

template<typename... T>
std::string linq::query::Select<T...>::validateQuery() {
    _sqlQuery = "SELECT " + _columnName[0];
    for (int i = 1; i < _columnName.size(); ++i) {
        _sqlQuery += ", " + _columnName[i];
    }

    if (!contains("SELECT ")) {
        throw linq::InvalidQuery();
    }

    return _sqlQuery;
}

template<typename... T>
linq::query::From linq::query::Select<T...>::from(linq::db::Table table) {
    return {validateQuery(), std::move(table), _columnName};
}
