//
// Created by pokys on 30.05.2022.
//

#include "orm/query/Join.hpp"

#include <utility>

std::string orm::query::Join::validateQuery() {
    std::string join_string = "\n";
    switch (_joinType) {
        case JoinType::INNER:
            join_string += "INNER";
            break;
        case LEFT:
            join_string += "LEFT";
            break;
        case RIGHT:
            join_string += "RIGHT";
            break;
    }

    join_string += " JOIN " + _table.getTableName() + " ON " + _condition.get();

    auto nextTableCols = _table.getColumns();
    _columnTableCols.insert(_columnTableCols.end(), nextTableCols.begin(), nextTableCols.end());

    for (auto &selected_column: _columnName) {
        if(![&](const std::string& selected_column) -> bool{
            for (auto &column: _columnTableCols)
                if (selected_column == column) return true;
            return false;
        }(selected_column) and throw_err)
            throw InvalidColumn();
    }
    return _sqlQuery + " " + join_string;
}

orm::query::Join::Join(std::string query, orm::query::JoinType joinType, orm::db::Table table,
                       const orm::db::Condition &condition, std::vector<std::string> columnName,
                       std::vector<std::string> columnTableCols)
        : SqlQuery(std::move(query)), _joinType(joinType), _table(std::move(table)), _condition(condition),
          _columnName(std::move(columnName)), _columnTableCols(std::move(columnTableCols)) {}

orm::query::Where orm::query::Join::where(orm::db::Condition condition) {
    return {validateQuery(), condition};
}

orm::query::Join
orm::query::Join::join(orm::query::JoinType joinType, orm::db::Table table, const orm::db::Condition &condition) {
    throw_err = false;
    return {validateQuery(), joinType, std::move(table), condition, _columnName, _columnTableCols};
}

