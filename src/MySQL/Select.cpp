//
// Created by pokys on 25.05.2022.
//

#include "LINQ/query/Select.hpp"

#include <utility>
#include "LINQ/Errors.hpp"

template<typename... T>
linq::query::Select::Select(linq::db::Column <T>... rows){
    int i = 0;

    ([&](auto &row) {
        _columnName.emplace_back(static_cast<linq::db::Column<T>>(row).name);
        i++;
    }(rows), ...);
}

std::string linq::query::Select::validateQuery() {
    _sqlQuery = "SELECT " + _columnName[0];
    for (int i = 1; i < _columnName.size(); ++i) {
        _sqlQuery += ", " + _columnName[i];
    }

    if (!contains("SELECT ")) {
        throw linq::InvalidQuery();
    }

    return _sqlQuery;
}

linq::query::From linq::query::Select::from(linq::db::Table table) {
    return {validateQuery(), std::move(table), _columnName};
}
