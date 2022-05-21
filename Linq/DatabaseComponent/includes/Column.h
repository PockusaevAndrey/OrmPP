//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_COLUMN_H
#define LINQ_COLUMN_H

#include "Condition.h"
#include "Sort.h"

namespace etd::linq::databaseComponent
{
    std::string to_string(const std::string &value)
    {
        return value;
    }

    template<typename T>
    class Column final
    {
    public:
        std::string name;
        T type{};


        Column() = default;
        explicit Column(std::string name);


        template<class V = Condition>
        Condition operator>(V value);

        template<class V = Condition>
        Condition operator<(V value);

        template<class V = Condition>
        Condition operator==(V value);

        template<class V = Condition>
        Condition operator!=(V value);

        Sort operator-(OrderSort order);


        virtual ~Column() = default;
    };
}

#endif //LINQ_COLUMN_H
