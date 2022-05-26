//
// Created by pokys on 26.05.2022.
//

#ifndef LINQ_TABLECONTROLLER_HPP
#define LINQ_TABLECONTROLLER_HPP
#define getName(variable) #variable


#include <string>
#include <utility>
#include <vector>
#include "LINQ/components/Column.h"
namespace linq::db {
    class TableController {
        std::string tableName;
        std::vector<std::string> columns;
    public:
        TableController(std::string table);
        TableController() = default;
        void setTable(std::string table);
        template<typename T>
        Column<T> addColumn(std::string name);
        size_t getColumnSize() const;
        std::string getTableName() const;
        std::string at(int i);
    };


}
#include "LINQ/inc/TableController.tpp"


#endif //LINQ_TABLECONTROLLER_HPP
