//
// Created by pokys on 26.05.2022.
//
#include "orm/components/TableController.hpp"

orm::db::TableController::TableController(std::string table) : tableName(std::move(table)) {

}

size_t orm::db::TableController::getColumnSize() const {
    return columns.size();
}

std::string orm::db::TableController::getTableName() const {
    return tableName;
}

std::string orm::db::TableController::at(int i) {
    return columns.at(i);
}

void orm::db::TableController::setTable(std::string table) {
    tableName = std::move(table);

}

void orm::db::TableController::joinColumns(std::vector<std::string> cols) {
    columns.insert(columns.end(), cols.begin(), cols.end());
}

std::vector<std::string> orm::db::TableController::getColumns() {
    return columns;
}


