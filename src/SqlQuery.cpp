//
// Created by pokys on 25.05.2022.
//

#include "LINQ/components/SqlQuery.hpp"


linq::abstraction::SqlQuery::SqlQuery(std::string query) : _sqlQuery(query) {
}

std::string linq::abstraction::SqlQuery::getQuery() {
    return validateQuery();
}

bool linq::abstraction::SqlQuery::contains(std::string value) {
    return _sqlQuery.find(value) != std::string::npos;
}

linq::abstraction::SqlQuery::operator std::string() {
    return this->validateQuery();
}
