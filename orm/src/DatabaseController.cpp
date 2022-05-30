//
// Created by pokys on 30.05.2022.
//

#include "orm/components/DatabaseController.hpp"

#include <utility>

orm::db::DatabaseController::DatabaseController(std::string name): _name(std::move(name)) {}

void orm::db::DatabaseController::setDatabase(const std::string& name) {
    _name = name;
}
