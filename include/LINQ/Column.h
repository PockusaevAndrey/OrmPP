//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_COLUMN_H
#define LINQ_COLUMN_H

#include "LINQ/Condition.h"
#include "LINQ/Sort.h"
#include "ToString.hpp"

namespace linq::db
{

    template<typename T>
    class Column final
    {
    public:
        std::string tableName{};
        std::string name{};
        T type{};

        Column() = default;

        Column(std::string name) : name(std::move(name))
        {
        }

        template<typename V>
        Condition operator>(V value);

        template<typename V>
        Condition operator<(V value);

        template<typename V>
        Condition operator==(V value);

        template<typename V>
        Condition operator!=(V value);

        Sort operator-(OrderSort order)
        {
            return {name + " " + ((order == OrderSort::ASC) ? "ASC" : "DESC")};
        }

    };
}

//std::string to_string(const std::string &value)
//{
//    return value;
//}


template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator>(V value)
{
    using namespace std;
    return {name + " > " + to_string(value)};
}
template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator<(V value)
{
    using namespace std;
    return {name + " < " + to_string(value)};
}
template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator==(V value)
{
    using namespace std;
    return {name + " == " + to_string(value)};
}
template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator!=(V value)
{
    using namespace std;
    return {name + " != " +to_string(value)};
}

#endif //LINQ_COLUMN_H
