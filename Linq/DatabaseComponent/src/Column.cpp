//
// Created by eldar on 21.05.22.
//

#include "../includes/Column.h"
#include "../includes/Condition.h"

std::string to_string(const std::string &value)
{
    return value;
}

template<typename T>
etd::linq::databaseComponent::Column<T>::Column(std::string name) : name(name)
{
}

template<typename T>
template<class V>
etd::linq::databaseComponent::Condition
etd::linq::databaseComponent::Column<T>::operator>(V value)
{
    using namespace std;
    return {name + " > " + to_string(value)};
}

template<typename T>
template<class V>
etd::linq::databaseComponent::Condition
etd::linq::databaseComponent::Column<T>::operator<(V value)
{
    using namespace std;
    return {name + " < " + to_string(value)};
}

template<typename T>
template<class V>
etd::linq::databaseComponent::Condition
etd::linq::databaseComponent::Column<T>::operator==(V value)
{
    using namespace std;
    return {name + " == " + to_string(value)};
}

template<typename T>
template<class V>
etd::linq::databaseComponent::Condition
etd::linq::databaseComponent::Column<T>::operator!=(V value)
{
    using namespace std;
    return {name + " != " +to_string(value)};
}

template<typename T>
etd::linq::databaseComponent::Sort
etd::linq::databaseComponent::Column<T>::operator-(databaseComponent::OrderSort order)
{
    return {name + " " + ((order == OrderSort::ASC) ? "ASC" : "DESC")};
}

