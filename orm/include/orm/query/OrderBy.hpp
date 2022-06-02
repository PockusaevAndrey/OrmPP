//
// Created by pokys on 25.05.2022.
//

#ifndef orm_ORDERBY_HPP
#define orm_ORDERBY_HPP

#include <utility>

#include "orm/components/SqlQuery.hpp"
#include "orm/components/Sort.hpp"
#include "Limit.hpp"

namespace orm::query {
    class OrderBy : public abstraction::SqlQuery {
        db::Sort _sort;
    public:
        OrderBy(std::string query, db::Sort sort);

        std::string validateQuery() override;
        Limit limit(int count);
    };
}


#endif //orm_ORDERBY_HPP
