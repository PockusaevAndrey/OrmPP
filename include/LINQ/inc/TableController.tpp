#pragma once
//
// Created by pokys on 25.05.2022.
//


#include <utility>


template<typename T>
linq::db::Column<T> linq::db::TableController::addColumn(std::string name) {
    columns.push_back(name);
    auto result = linq::db::Column<T>(name);
    result.tableName = tableName;
    return result;
}

