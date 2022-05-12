//
// Created by eldar on 12.05.22.
//

#ifndef LINQ_IOPERABLE_HPP
#define LINQ_IOPERABLE_HPP

#include "../Linq/IOperation.hpp"
#include "../Linq/Linq.hpp"

namespace etd::linq{

    interface IOperable{
    public:

        virtual string execute(Linq &linq)  = 0;

        virtual string executeQuery(const string &sqlQuery) = 0;

        virtual ~IOperable() = 0;

    };

}

#endif //LINQ_IOPERABLE_HPP
