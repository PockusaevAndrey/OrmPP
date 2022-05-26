//
// Created by pokys on 25.05.2022.
//

#ifndef LINQ_WHERE_HPP
#define LINQ_WHERE_HPP

#define OR |
#define AND &

#include <utility>

#include "LINQ/components/SqlQuery.hpp"
#include "LINQ/components/Condition.h"
#include "LINQ/Errors.hpp"
#include "OrderBy.hpp"


namespace linq::query {
    class Where : abstraction::SqlQuery {
        db::Condition _condition;
    public:
        Where(std::string query, db::Condition condition);

        std::string validateQuery() override;
        OrderBy orderBy(db::Sort sort);
    };
}

#endif //LINQ_WHERE_HPP
