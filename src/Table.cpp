//
// Created by pokys on 25.05.2022.
//

#include "LINQ/components/Table.h"

template<class... T>
linq::db::Table::Table(std::string tableName, Column<T>... columns) : _tableName(tableName) {
    Initialization(columns...);
}

template<class ...T>
void linq::db::Table::Initialization(Column<T>... columns) {
    int i = 0;

    ([&](auto &row) {
        static_cast<Column<T>>(row).tableName = _tableName;
        _columnName.emplace_back(static_cast<Column<T>>(row).name);
        i++;
    }(columns), ...);
}

size_t linq::db::Table::getColumnSize() const {
    return _columnName.size();
}

std::string linq::db::Table::getTableName() const {
    return _tableName;
}

std::string linq::db::Table::operator[](int i) {
    return _columnName.at(i);
}
