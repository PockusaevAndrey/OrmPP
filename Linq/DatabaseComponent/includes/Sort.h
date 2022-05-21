//
// Created by eldar on 21.05.22.
//

#ifndef LINQ_SORT_H
#define LINQ_SORT_H

#include <string>

namespace etd::linq::databaseComponent
{
    enum class OrderSort : int
    {
        ASC,
        DESC
    };

    using
    enum OrderSort;

    class Sort
    {
    public:
        Sort(std::string sort);

        Sort &operator&(Sort sort);

        std::string get();

    private:
        std::string _sortedRow;
    };
}
#endif //LINQ_SORT_H
