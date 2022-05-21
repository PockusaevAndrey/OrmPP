//
// Created by eldar on 21.05.22.
//

#include "../includes/Condition.h"


etd::linq::databaseComponent::Condition::Condition(const std::string &condition)
{
    this->condition += condition;
}

etd::linq::databaseComponent::Condition::Condition(const etd::linq::databaseComponent::Condition &condition)
{
    this->condition = "(" + condition.getWithoutScope();
}

etd::linq::databaseComponent::Condition &
etd::linq::databaseComponent::Condition::operator&(etd::linq::databaseComponent::Condition condition)
{
    this->condition += ") AND (" + condition.getWithoutScope();
    return *this;
}

etd::linq::databaseComponent::Condition &
etd::linq::databaseComponent::Condition::operator|(etd::linq::databaseComponent::Condition condition)
{
    std::string query = condition.getWithoutScope();
    this->condition += " OR " + (query.starts_with('(') ? query.substr(1, query.length()) : query);
    return *this;
}

std::string etd::linq::databaseComponent::Condition::get() const
{
    return condition + ")";
}

std::string etd::linq::databaseComponent::Condition::getWithoutScope() const
{
    return condition;
}
