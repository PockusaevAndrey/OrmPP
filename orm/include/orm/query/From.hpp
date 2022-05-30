//
// Created by pokys on 25.05.2022.
//

#ifndef orm_FROM_HPP
#define orm_FROM_HPP

#include "orm/components/Table.hpp"
#include "orm/components/SqlQuery.hpp"
#include "orm/query/Where.hpp"
#include "Join.hpp"

namespace orm::query {
    class From : public abstraction::SqlQuery {
        db::Table _table;
        std::vector <std::string> _columnName{};
        bool throw_err = true;

    public:
        From(std::string query, db::Table table, std::vector <std::string> columns);

        std::string validateQuery() override;

        Join join(JoinType joinType, db::Table table, const db::Condition& condition);

        Where where(db::Condition condition);
    };
}


#endif //orm_FROM_HPP
