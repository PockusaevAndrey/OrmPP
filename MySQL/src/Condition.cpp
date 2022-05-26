//
// Created by eldar on 21.05.22.
//

#include "orm/components/Condition.hpp"


orm::db::Condition::Condition(const std::string &condition) {
    this->condition = "(" + condition;
}

orm::db::Condition::Condition(const orm::db::Condition &condition) {
    this->condition = "(" + condition.get();
}

orm::db::Condition &
orm::db::Condition::operator&(orm::db::Condition condition) {
    this->condition += " AND " + condition.get();
    return *this;
}

orm::db::Condition &
orm::db::Condition::operator|(orm::db::Condition condition) {
    this->condition += " OR " + condition.get();
    return *this;
}

std::string orm::db::Condition::get() const {
    return condition + ")";
}

