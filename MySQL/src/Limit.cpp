//
// Created by pokys on 31.05.2022.
//

#include "../../orm/include/orm/query/Limit.hpp"

std::string orm::query::Limit::validateQuery() {
    _sqlQuery += "\nLIMIT " + std::to_string(count);
    return _sqlQuery;
}

orm::query::Limit::Limit(std::string query, int count) : orm::abstraction::SqlQuery(query), count(count) {}

orm::query::Offset orm::query::Limit::offset(int offset_count) {
    return {validateQuery(), offset_count};
}
