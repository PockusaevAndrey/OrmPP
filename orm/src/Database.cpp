//
// Created by pokys on 30.05.2022.
//

#include "orm/components/Database.hpp"

#include <utility>

orm::db::Database::Database(const std::string& name) {
    controller.setDatabase(name);
}

orm::db::Database::operator std::string() {
    return controller.getDatabase();
}
