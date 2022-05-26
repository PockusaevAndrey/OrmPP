//
// Created by eldar on 21.05.22.
//

#ifndef orm_SORT_HPP
#define orm_SORT_HPP

#include <string>

namespace orm::db {
    enum class OrderSort : int {
        ASC,
        DESC
    };


    class Sort {
    public:

        Sort();

        Sort(std::string sort);

        Sort &operator&(Sort sort);

        std::string get();

    private:
        std::string _sortedRow{};
    };
}
#endif //orm_SORT_HPP
