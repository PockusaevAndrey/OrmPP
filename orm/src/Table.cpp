//
// Created by pokys on 26.05.2022.
//

#include "orm/components/Table.hpp"

#include <utility>

size_t orm::db::Table::getColumnSize() const {
    return controller.getColumnSize();
}

std::string orm::db::Table::getTableName() const {
    return controller.getTableName();
}

std::string orm::db::Table::operator[](int i) {
    return controller.at(i);
}

orm::db::Table::Table(std::string name) {
    controller.setTable(name);
};