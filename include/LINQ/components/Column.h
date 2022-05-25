//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_COLUMN_H
#define LINQ_COLUMN_H

#include "Condition.h"
#include "Sort.h"
#include "ToString.hpp"

namespace linq::db {
    template<typename T>
    class Column final {
    public:
        std::string name{};

        Column() = default;

        Column(std::string name) : name(std::move(name)) {

        }

        template<typename V>
        Condition operator>(V value);

        template<typename V>
        Condition operator<(V value);

        template<typename V>
        Condition operator==(V value);

        template<typename V>
        Condition operator!=(V value);

        Sort operator-(OrderSort order) {
            return {name + " " + ((order == OrderSort::ASC) ? "ASC" : "DESC")};
        }

    };
}
#endif //LINQ_COLUMN_H
