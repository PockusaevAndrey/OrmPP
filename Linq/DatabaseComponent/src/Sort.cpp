//
// Created by eldar on 21.05.22.
//

#include "../includes/Sort.h"


etd::linq::databaseComponent::Sort::Sort(std::string sort)
{
    _sortedRow += sort;
}

etd::linq::databaseComponent::Sort &
etd::linq::databaseComponent::Sort::operator&(Sort sort)
{
    this->_sortedRow += ", " + sort.get();
    return *this;
}

std::string etd::linq::databaseComponent::Sort::get()
{
    return _sortedRow;
}