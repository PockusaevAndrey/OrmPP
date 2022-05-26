//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_COLUMN_H
#define LINQ_COLUMN_H

#include "Condition.h"
#include "Sort.h"
#include "ToString.hpp"
#include <any>



namespace linq::db {
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
#include "LINQ/inc/Column.tpp"
#endif //LINQ_COLUMN_H
