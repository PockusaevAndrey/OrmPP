//
// Created by eldar on 13.05.22.
//

#ifndef LINQ_IOPERATIONINSERT_H
#define LINQ_IOPERATIONINSERT_H

#include "IOperation.h"

namespace etd::linq
{

    template<typename T>
    interface IOperationInsert : public IOperation
    {
        virtual T &insert(std::string) = 0;

        virtual T &values(std::string) = 0;

        virtual ~IOperationInsert() = default;
    };

}

#endif //LINQ_IOPERATIONINSERT_H
