//
// Created by pokys on 25.05.2022.
//

#include "LINQ/Errors.hpp"

#include <utility>

const char *linq::InvalidColumn::what() const noexcept {
    return "";
}

const char *linq::InvalidQuery::what() const noexcept {
    return "";
}

const char *linq::TypeMismatch::what() const noexcept {


    return this->result.c_str();
}

linq::TypeMismatch::TypeMismatch(std::string column) : std::exception(), column(std::move(column)) {
    result = "Type mismatch in Column: " + this->column;
}
