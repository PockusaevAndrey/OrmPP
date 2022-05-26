//
// Created by pokys on 26.05.2022.
//
#include "LINQ/components/TableController.hpp"

linq::db::TableController::TableController(std::string table) : tableName(std::move(table)) {

}

size_t linq::db::TableController::getColumnSize() const {
    return columns.size();
}

std::string linq::db::TableController::getTableName() const {
    return tableName;
}

std::string linq::db::TableController::at(int i) {
    return columns.at(i);
}

void linq::db::TableController::setTable(std::string table) {
    tableName = std::move(table);

}


