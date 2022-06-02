//
// Created by pokys on 25.05.2022.
//

#include "orm/query/From.hpp"

#include <utility>
#include "orm/components/Table.hpp"
#include "orm/Errors.hpp"

orm::query::From::From(std::string query, orm::db::Table table, std::vector<std::string> columns) : SqlQuery(
        std::move(query)), _table(std::move(table)), _columnName(columns) {
}

std::string orm::query::From::validateQuery() {

    auto isRow = [&](const std::string &row) -> bool {
        for (int i = 0; i < _table.getColumnSize(); i++) {
            if (row == _table[i]) {
                return true;
            }
        }
        return false;
    };
    for (auto &i: _columnName) {
        if (!isRow(i) && throw_err) {
//            throw InvalidColumn();
        }
    }

    _sqlQuery += "\nFROM " + _table.getTableName();

    if (!contains("FROM ")) {
        throw InvalidQuery();
    }

    return _sqlQuery;
}

orm::query::Where orm::query::From::where(orm::db::Condition condition) {
    return {validateQuery(), condition};
}

orm::query::Join
orm::query::From::join(orm::query::JoinType joinType, orm::db::Table table, const orm::db::Condition &condition) {
    throw_err = false;
    return {validateQuery(), joinType, std::move(table), condition, _columnName, _table.getColumns()};
}

orm::query::Limit orm::query::From::limit(int count) {
    return {validateQuery(), count};
}

