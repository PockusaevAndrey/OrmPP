//
// Created by eldar on 13.05.22.
//

#ifndef LINQ_IOPERATIONDELETE_H
#define LINQ_IOPERATIONDELETE_H

#include "IOperation.h"

namespace etd::linq
{

    template<typename T>
    interface IOperationDelete : public IOperation
    {
        virtual T &deleted(std::string) = 0;

        virtual T &from(std::string) = 0;

        virtual T &where(std::string) = 0;

        virtual T &orderBy(std::string) = 0;

        virtual T &limit(std::string) = 0;

        virtual T &offset(std::string) = 0;

        virtual ~IOperationDelete() = default;
    };

}

#endif //LINQ_IOPERATIONDELETE_H
