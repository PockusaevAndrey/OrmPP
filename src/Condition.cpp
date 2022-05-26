//
// Created by eldar on 21.05.22.
//

#include "LINQ/components/Condition.h"


linq::db::Condition::Condition(const std::string &condition) {
    this->condition = "(" + condition;
}

linq::db::Condition::Condition(const linq::db::Condition &condition) {
    this->condition = "(" + condition.get();
}

linq::db::Condition &
linq::db::Condition::operator&(linq::db::Condition condition) {
    this->condition += " AND " + condition.get();
    return *this;
}

linq::db::Condition &
linq::db::Condition::operator|(linq::db::Condition condition) {
    this->condition += " OR " + condition.get();
    return *this;
}

std::string linq::db::Condition::get() const {
    return condition + ")";
}

