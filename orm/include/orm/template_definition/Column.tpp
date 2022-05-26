#pragma once
//
// Created by pokys on 25.05.2022.
//

#include <typeindex>
#include "orm/Errors.hpp"
#include "orm/components/Column.hpp"


template<typename T>
orm::db::Condition
orm::db::Column<T>::operator>(std::any value) {

    if (typeid(T) == value.type())
        return {name + " > " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName +"::"+name);
}

template<typename T>
orm::db::Condition
orm::db::Column<T>::operator<(std::any value) {
    if (typeid(T) == value.type())
        return {name + " < " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName +"::"+name);
}

template<typename T>
orm::db::Condition
orm::db::Column<T>::operator==(std::any value) {
    if (typeid(T) == value.type())
        return {name + " == " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName +"::"+name);
}

template<typename T>
orm::db::Condition
orm::db::Column<T>::operator!=(std::any value) {
    if (typeid(T) == value.type())
        return {name + " != " + std::to_string(std::any_cast<T>(value))};
    else throw orm::TypeMismatch(tableName +"::"+name);
}

template<typename T>
orm::db::Column<T>::Column(std::string name)  : name(std::move(name)) {

}
