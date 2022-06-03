//
// Created by pokys on 25.05.2022.
//

#include "orm/components/SqlQuery.hpp"


orm::abstraction::SqlQuery::SqlQuery(std::string query) : _sqlQuery(query) {
}

std::string orm::abstraction::SqlQuery::getQuery() {
    return validateQuery();
}

bool orm::abstraction::SqlQuery::contains(std::string value) {
    return _sqlQuery.find(value) != std::string::npos;
}

orm::abstraction::SqlQuery::operator std::string() {
    return this->validateQuery();
}

orm::abstraction::SqlQuery::operator db::Column<std::string>() {
    return {"(" + validateQuery() + ")"};
}
