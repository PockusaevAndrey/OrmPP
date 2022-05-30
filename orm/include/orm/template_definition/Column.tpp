#pragma once
//
// Created by pokys on 25.05.2022.
//

#include <typeindex>
#include "orm/Errors.hpp"
#include "orm/components/Column.hpp"
#include "iostream"
#include "vector"

template<typename T>
orm::db::Condition
orm::db::Column<T>::operator>(std::any value) {

    if (typeid(T) == value.type())
        return {name + " > " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName + "::" + name);
}

template<typename T>
orm::db::Condition
orm::db::Column<T>::operator<(std::any value) {
    if (typeid(T) == value.type())
        return {name + " < " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName + "::" + name);
}

template<typename T>
orm::db::Condition
orm::db::Column<T>::operator==(std::any value) {
    if (typeid(T) == value.type())
        return {name + " = " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName + "::" + name);
}

template<typename T>
orm::db::Condition
orm::db::Column<T>::operator!=(std::any value) {
    if (typeid(T) == value.type())
        return {name + " != " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName + "::" + name);
}

template<typename T>
orm::db::Column<T>::Column(std::string name)  : name(std::move(name)) {

}

template<typename T>
orm::db::Condition orm::db::Column<T>::in(const std::vector<std::any> &vals) {
    std::string result = name + " in (";
    for (int i = 0; i < vals.size(); i++)
        if (typeid(T) == vals[i].type()) {
            result += std::to_string(std::any_cast<T>(vals[i]));
            if (i != vals.size()-1)
                result += ", ";
        }
        else throw orm::TypeMismatch(tableName + "::" + name);
    result += ")";
    return {result};
}

template<typename T>
orm::db::Sort orm::db::Column<T>::operator<<(orm::db::OrderSort order) {
    return {name + " " + ((order == OrderSort::ASC) ? "ASC" : "DESC")};
}

template<typename T>
orm::db::Condition orm::db::Column<T>::operator>(orm::db::Column<T> value) {
    return {name + " > " + value.name};
}

template<typename T>
orm::db::Condition orm::db::Column<T>::operator<(orm::db::Column<T> value) {
    return {name + " < " + value.name};
}

template<typename T>
orm::db::Condition orm::db::Column<T>::operator==(orm::db::Column<T> value) {
    return {name + " = " + value.name};
}

template<typename T>
orm::db::Condition orm::db::Column<T>::operator!=(orm::db::Column<T> value) {
    return {name + " != " + value.name};
}
