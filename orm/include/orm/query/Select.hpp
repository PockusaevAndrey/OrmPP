//
// Created by pokys on 25.05.2022.
//

#ifndef orm_SELECT_HPP
#define orm_SELECT_HPP
#include "orm/components/SqlQuery.hpp"
#include "orm/components/Column.hpp"
#include "vector"
#include "orm/components/Table.hpp"
#include "orm/query/From.hpp"

namespace orm::query{
    template<typename ...T>
    class Select: public abstraction::SqlQuery{
    public:
        Select(db::Column <T>... rows);
        std::string validateQuery() override;
        orm::query::From from(orm::db::Table table);
    private:
        std::vector<std::string> _columnName{};

    };

}
#include "orm/template_definition/Select.tpp"
#endif //orm_SELECT_HPP
