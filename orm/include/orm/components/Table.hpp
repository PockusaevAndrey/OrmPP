#pragma once
//
// Created by eldar on 21.05.22.
//

#include <vector>
#include "Column.hpp"
#include "TableController.hpp"

namespace orm::db {
    class Table {
    protected:
        TableController controller;
    public:
        Table() = default;
        Table(std::string name);
        [[nodiscard]] size_t getColumnSize() const;

        [[nodiscard]] std::string getTableName() const;

        std::string operator[](int i);

    };
}

