//
// Created by pokys on 01.06.2022.
//

#ifndef ORM_TEST_OFFSET_HPP
#define ORM_TEST_OFFSET_HPP

#include "orm/components/SqlQuery.hpp"

namespace orm::query {
    class Offset : public abstraction::SqlQuery {
        int count;
    public:
        Offset(std::string query, int count);
        std::string validateQuery() override;
    };
}

#endif //ORM_TEST_OFFSET_HPP
