//
// Created by pokys on 25.05.2022.
//

#ifndef LINQ_SELECT_HPP
#define LINQ_SELECT_HPP
#include "LINQ/components/SqlQuery.hpp"
#include "LINQ/components/Column.h"
#include "vector"
#include "LINQ/components/Table.h"
#include "LINQ/query/From.hpp"

namespace linq::query{
    class Select: public abstraction::SqlQuery{
    public:
        template<typename ...T>
        Select(db::Column <T>... rows);
        std::string validateQuery() override;
        linq::query::From from(linq::db::Table table);
    private:
        std::vector<std::string> _columnName;

    };
}



#endif //LINQ_SELECT_HPP
