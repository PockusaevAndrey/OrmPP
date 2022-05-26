//
// Created by pokys on 26.05.2022.
//

#include "LINQ/components/Table.h"

#include <utility>

size_t linq::db::Table::getColumnSize() const {
    return controller.getColumnSize();
}

std::string linq::db::Table::getTableName() const {
    return controller.getTableName();
}

std::string linq::db::Table::operator[](int i) {
    return controller.at(i);
}

linq::db::Table::Table(std::string name) {
    controller.setTable(name);
};