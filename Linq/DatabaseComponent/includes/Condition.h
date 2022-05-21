//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_CONDITION_H
#define LINQ_CONDITION_H

#include <string>

namespace etd::linq::databaseComponent
{
    class Condition
    {
    public:
        Condition(const std::string &condition);

        Condition(const Condition &condition);

        Condition &operator&(Condition condition);

        Condition &operator|(Condition condition);

        std::string get() const;

        std::string getWithoutScope() const;

    private:
        std::string condition;
    };
}
#endif //LINQ_CONDITION_H
