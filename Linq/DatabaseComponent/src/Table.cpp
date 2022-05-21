//
// Created by eldar on 21.05.22.
//

#include "../includes/Table.h"


template<class... T>
etd::linq::databaseComponent::Table::Table(std::string tableName, etd::linq::databaseComponent::Column<T>... columns) : _tableName(tableName)
{
    Initialization(columns...);
}

template<class... T>
void etd::linq::databaseComponent::Table::Initialization(etd::linq::databaseComponent::Column<T>... columns)
{
    int i = 0;

    ([&](auto &row)
    {
        _columnName.emplace_back(static_cast<Column<T>>(row).name);
        i++;
    }(columns), ...);
}

size_t etd::linq::databaseComponent::Table::getColumnSize() const {
    return _columnName.size();
}

std::string etd::linq::databaseComponent::Table::getTableName() const
{
    return _tableName;
}

std::string etd::linq::databaseComponent::Table::operator[](int i)
{
    return _columnName.at(i);
}
