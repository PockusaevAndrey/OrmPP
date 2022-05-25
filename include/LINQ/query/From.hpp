//
// Created by pokys on 25.05.2022.
//

#ifndef LINQ_FROM_HPP
#define LINQ_FROM_HPP

#include "LINQ/components/Table.h"
#include "LINQ/components/SqlQuery.hpp"
#include "LINQ/query//Where.hpp"

namespace linq::query{
    class From : abstraction::SqlQuery {
        db::Table _table;
        std::vector <std::string> _columnName;
    public:
        From(std::string query, db::Table table, std::vector <std::string> columnName);
        std::string validateQuery() override;
        Where where(Condition condition);
    };
}



#endif //LINQ_FROM_HPP