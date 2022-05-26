//
// Created by pokys on 25.05.2022.
//

#ifndef orm_WHERE_HPP
#define orm_WHERE_HPP

#define OR |
#define AND &

#include <utility>

#include "orm/components/SqlQuery.hpp"
#include "orm/components/Condition.hpp"
#include "orm/Errors.hpp"
#include "OrderBy.hpp"


namespace orm::query {
    class Where : abstraction::SqlQuery {
        db::Condition _condition;
    public:
        Where(std::string query, db::Condition condition);

        std::string validateQuery() override;
        OrderBy orderBy(db::Sort sort);
    };
}

#endif //orm_WHERE_HPP
