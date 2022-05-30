#pragma once
//
// Created by pokys on 25.05.2022.
//


#include <utility>


template<typename T>
orm::db::Column<T> orm::db::TableController::addColumn(std::string name) {
    columns.push_back(tableName+"."+name);
    auto result = orm::db::Column<T>(tableName+"."+name);
    result.tableName = tableName;
    return result;
}

