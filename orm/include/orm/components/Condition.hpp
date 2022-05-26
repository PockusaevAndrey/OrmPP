//
// Created by eldar on 21.05.22.
//

#ifndef orm_CONDITION_HPP
#define orm_CONDITION_HPP

#include <string>

namespace orm::db {
    class Condition {
    public:
        Condition(const std::string &condition);

        Condition(const Condition &condition);

        Condition &operator&(Condition condition);

        Condition &operator|(Condition condition);

        std::string get() const;

    private:
        std::string condition{};
    };
}
#endif //orm_CONDITION_HPP
