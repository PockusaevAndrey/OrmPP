//
// Created by pokys on 30.05.2022.
//

#ifndef ORM_TEST_JOIN_HPP
#define ORM_TEST_JOIN_HPP

#include "orm/components/SqlQuery.hpp"
#include "orm/query/Where.hpp"
#include "orm/components/Table.hpp"
#include "Limit.hpp"

namespace orm::query {
    enum JoinType {
        INNER = 0,
        LEFT,
        RIGHT
    };

    class Join : public abstraction::SqlQuery {
        db::Table _table;
        std::vector <std::string> _columnName{};
        std::vector <std::string> _columnTableCols{};
        db::Condition _condition;
        JoinType _joinType;
#ifdef ORM_FUNCTION
        bool throw_err = false;
#else
        bool throw_err = true;
#endif

    public:
        Join(std::string query, orm::query::JoinType joinType, orm::db::Table table,
             const orm::db::Condition &condition, std::vector<std::string> columnName,
             std::vector<std::string> columnTableCols);

        Where where(db::Condition condition);
        Join join(JoinType joinType, db::Table table, const db::Condition& condition);

        std::string validateQuery() override;
        Limit limit(int count);
    };
}


#endif //ORM_TEST_JOIN_HPP
