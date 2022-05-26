//
// Created by pokys on 25.05.2022.
//

#ifndef LINQ_ORDERBY_HPP
#define LINQ_ORDERBY_HPP

#include <utility>

#include "LINQ/components/SqlQuery.hpp"
#include "LINQ/components/Sort.h"

namespace linq::query {
    class OrderBy : public abstraction::SqlQuery {
        db::Sort _sort;
    public:
        OrderBy(std::string query, db::Sort sort);

        std::string validateQuery() override;
    };
}


#endif //LINQ_ORDERBY_HPP
