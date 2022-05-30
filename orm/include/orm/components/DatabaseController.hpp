//
// Created by pokys on 30.05.2022.
//

#ifndef ORM_TEST_DATABASECONTROLLER_HPP
#define ORM_TEST_DATABASECONTROLLER_HPP


#include <vector>
#include <string>
#include <memory>
#include "Table.hpp"

namespace orm::db {
    class DatabaseController {
        std::string _name;
    public:
        DatabaseController(std::string name);
        DatabaseController() = default;
        void setDatabase(const std::string& name);
        template<class T>
        T addTable(const std::string& tableName);
    };
}
#include "orm/template_definition/Database.tpp"

#endif //ORM_TEST_DATABASECONTROLLER_HPP
