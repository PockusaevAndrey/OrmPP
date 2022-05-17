//
// Created by eldar on 13.05.22.
//

#ifndef LINQ_IOPERATIONUPDATE_H
#define LINQ_IOPERATIONUPDATE_H

#include "IOperation.h"

namespace etd::linq
{

    template<typename T>
    interface IOperationUpdate : public IOperation
    {
        virtual T &update(std::string) = 0;

        virtual T &set(std::string) = 0;

        virtual T &where(std::string) = 0;

        virtual T &orderBy(std::string) = 0;

        virtual T &limit(std::string) = 0;

        virtual T &offset(std::string) = 0;

        virtual ~IOperationUpdate() = default;
    };

}

#endif //LINQ_IOPERATIONUPDATE_H
