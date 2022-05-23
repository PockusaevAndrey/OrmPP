//
// Created by eldar on 21.05.22.
//

#include "LINQ/Condition.h"


linq::db::Condition::Condition(const std::string &condition)
{
    this->condition += condition;
}

linq::db::Condition::Condition(const linq::db::Condition &condition)
{
    this->condition = "(" + condition.getWithoutScope();
}

linq::db::Condition &
linq::db::Condition::operator&(linq::db::Condition condition)
{
    this->condition += ") AND (" + condition.getWithoutScope();
    return *this;
}

linq::db::Condition &
linq::db::Condition::operator|(linq::db::Condition condition)
{
    std::string query = condition.getWithoutScope();
    this->condition += " OR " + (query.starts_with('(') ? query.substr(1, query.length()) : query);
    return *this;
}

std::string linq::db::Condition::get() const
{
    return condition + ")";
}

std::string linq::db::Condition::getWithoutScope() const
{
    return condition;
}
