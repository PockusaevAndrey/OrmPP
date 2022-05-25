//
// Created by pokys on 25.05.2022.
//

#include "LINQ/Errors.hpp"

const char *linq::InvalidColumn::what() const noexcept {
    return "";
}

const char *linq::InvalidQuery::what() const noexcept {
    return "";
}
