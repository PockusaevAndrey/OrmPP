#pragma once
//
// Created by pokys on 25.05.2022.
//

#include <typeindex>
#include "LINQ/Errors.hpp"
#include "LINQ/components/Column.h"


template<typename T>
linq::db::Condition
linq::db::Column<T>::operator>(std::any value) {

    using namespace std;
    if (typeid(T) == value.type())
        return {name + " > " + to_string(std::any_cast<T>(value))};
    else throw linq::TypeMismatch(tableName +"::"+name);
}

template<typename T>
linq::db::Condition
linq::db::Column<T>::operator<(std::any value) {
    using namespace std;
    if (typeid(T) == value.type())
        return {name + " < " + to_string(std::any_cast<T>(value))};
    else throw linq::TypeMismatch(tableName +"::"+name);
}

template<typename T>
linq::db::Condition
linq::db::Column<T>::operator==(std::any value) {
    using namespace std;
    if (typeid(T) == value.type())
        return {name + " == " + to_string(std::any_cast<T>(value))};
    else throw linq::TypeMismatch(tableName +"::"+name);
}

template<typename T>
linq::db::Condition
linq::db::Column<T>::operator!=(std::any value) {
    using namespace std;
    if (typeid(T) == value.type())
        return {name + " != " + to_string(std::any_cast<T>(value))};
    else throw linq::TypeMismatch(tableName +"::"+name);
}

template<typename T>
linq::db::Column<T>::Column(std::string name)  : name(std::move(name)) {

}
