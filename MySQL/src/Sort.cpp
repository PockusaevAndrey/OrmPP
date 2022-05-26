//
// Created by eldar on 21.05.22.
//

#include "orm/components/Sort.hpp"


orm::db::Sort::Sort(std::string sort)
{
    _sortedRow += sort;
}

orm::db::Sort &
orm::db::Sort::operator&(Sort sort)
{
    this->_sortedRow += ", " + sort.get();
    return *this;
}

std::string orm::db::Sort::get()
{
    return _sortedRow;
}

orm::db::Sort::Sort() = default;
