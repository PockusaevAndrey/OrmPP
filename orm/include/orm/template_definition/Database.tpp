//
// Created by pokys on 30.05.2022.
//

#include "orm/components/Database.hpp"
#include "orm/components/DatabaseController.hpp"


template<class T>
T orm::db::DatabaseController::addTable(const std::string& tableName) {
    return {_name + "." + tableName};
}

template<typename T, typename... Args>
orm::db::Function<T, Args...> orm::db::DatabaseController::addFunction(const std::string& name) {
    return {_name+"."+name};
}


