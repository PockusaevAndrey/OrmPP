//
// Created by pokys on 30.05.2022.
//

#ifndef ORM_TEST_DATABASE_HPP
#define ORM_TEST_DATABASE_HPP


#include <string>
#include <memory>
#include "DatabaseController.hpp"


namespace orm::db {
    class Database {
    public:
        DatabaseController controller;
        Database(const std::string& name);
    };

}


#endif //ORM_TEST_DATABASE_HPP
