
//
// Created by pokys on 01.06.2022.
//

#include "orm/query/Offset.hpp"

orm::query::Offset::Offset(std::string query, int count) : orm::abstraction::SqlQuery(query), count(count){}

std::string orm::query::Offset::validateQuery() {
    return _sqlQuery + "\n OFFSET "+std::to_string(count);
}
