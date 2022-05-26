//
// Created by eldar on 21.05.22.
//

#ifndef orm_COLUMN_HPP
#define orm_COLUMN_HPP

#include "Condition.hpp"
#include "Sort.hpp"
#include "ToString.hpp"
#include <any>



namespace orm::db {
    template<typename T>
    class Column final {
    public:
        std::string name{}, tableName{};

        Column() = default;

        Column(std::string name);

        Condition operator>(std::any value);

        Condition operator<(std::any value);

        Condition operator==(std::any value);

        Condition operator!=(std::any value);

        Sort operator<<(OrderSort order) {
            return {name + " " + ((order == OrderSort::ASC) ? "ASC" : "DESC")};
        }

    };
}
#include "orm/template_definition/Column.tpp"
#endif //orm_COLUMN_HPP
