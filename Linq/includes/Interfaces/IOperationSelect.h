//
// Created by eldar on 13.05.22.
//

#ifndef LINQ_IOPERATIONSELECT_H
#define LINQ_IOPERATIONSELECT_H

#include "IOperation.h"

namespace etd::linq
{

    template<typename T>
    interface IOperationSelect : public IOperation
    {
        virtual T &select(std::string) = 0;

        virtual T &from(std::string) = 0;

        virtual T &where(std::string) = 0;

        virtual T &orderBy(std::string) = 0;

        virtual T &groupBy(std::string) = 0;

        virtual T &having(std::string) = 0;

        virtual T &limit(std::string) = 0;

        virtual T &offset(std::string) = 0;

        virtual T &whereAnd() = 0;

        virtual T &whereOr() = 0;

        virtual T &closeScope() = 0;

        virtual ~IOperationSelect() = default;
    };

}
#endif //LINQ_IOPERATIONSELECT_H
