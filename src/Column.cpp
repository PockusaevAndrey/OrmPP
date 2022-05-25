//
// Created by pokys on 25.05.2022.
//
#include "LINQ/components/Column.h"

template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator>(V value) {
    using namespace std;
    return {name + " > " + to_string(value)};
}

template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator<(V value) {
    using namespace std;
    return {name + " < " + to_string(value)};
}

template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator==(V value) {
    using namespace std;
    return {name + " == " + to_string(value)};
}

template<typename T>
template<typename V>
linq::db::Condition
linq::db::Column<T>::operator!=(V value) {
    using namespace std;
    return {name + " != " + to_string(value)};
}
