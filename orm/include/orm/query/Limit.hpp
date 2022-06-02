//
// Created by pokys on 31.05.2022.
//

#ifndef ORM_TEST_LIMIT_HPP
#define ORM_TEST_LIMIT_HPP


#include "orm/components/SqlQuery.hpp"
#include "Offset.hpp"

namespace orm::query {
    class Limit : public abstraction::SqlQuery {
        int count;
    public:
        Limit(std::string query, int count);
        std::string validateQuery() override;
        Offset offset(int offset_count);
    };
}


#endif //ORM_TEST_LIMIT_HPP
