//
// Created by pokys on 25.05.2022.
//

#include "orm/Errors.hpp"

#include <utility>

const char *orm::InvalidColumn::what() const noexcept {
    return "С приветом по планетам 2";
}

const char *orm::InvalidQuery::what() const noexcept {
    return "";
}

const char *orm::TypeMismatch::what() const noexcept {


    return this->result.c_str();
}

orm::TypeMismatch::TypeMismatch(std::string column) : std::exception(), column(std::move(column)) {
    result = "Type mismatch in Column: " + this->column;
}
