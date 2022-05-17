//
// Created by eldar on 13.05.22.
//

#ifndef LINQ_IOPERATION_H
#define LINQ_IOPERATION_H

#include <iostream>

#define interface struct

namespace etd::linq
{

    interface IOperation
    {
        virtual std::string execute() = 0;
    };

}
#endif //LINQ_IOPERATION_H
