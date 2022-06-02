//
// Created by pokys on 01.06.2022.
//

#ifndef ORM_TEST_FUNCTION_HPP
#define ORM_TEST_FUNCTION_HPP

#include "Column.hpp"

namespace orm::db {
    template<typename T, typename ...Args>
    class Function : public Column<T> {
    public:
        Function(std::string name);
        Function operator() (Args... args);
    };
}
#include "orm/template_definition/Function.tpp"

#endif //ORM_TEST_FUNCTION_HPP
