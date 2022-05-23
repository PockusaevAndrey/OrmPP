//
// Created by eldar on 21.05.22.
//

#include "LINQ/Sort.h"


linq::db::Sort::Sort(std::string sort)
{
    _sortedRow += sort;
}

linq::db::Sort &
linq::db::Sort::operator&(Sort sort)
{
    this->_sortedRow += ", " + sort.get();
    return *this;
}

std::string linq::db::Sort::get()
{
    return _sortedRow;
}

linq::db::Sort::Sort() = default;
