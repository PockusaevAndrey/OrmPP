//
// Created by eldar on 06.05.22.
//

#ifndef LINQ_IOPERATION_HPP
#define LINQ_IOPERATION_HPP

#define interface struct

#include <string>

using namespace std;

namespace etd::linq {

        interface IOperation {
        public:

            virtual IOperation &select(string) = 0;

            virtual IOperation &from(string) = 0;

            virtual IOperation &where(string) = 0;

            virtual IOperation &orderBy(string) = 0;

            virtual IOperation &groupBy(string) = 0;

            virtual IOperation &having(string) = 0;

            virtual IOperation &limit(string) = 0;

            virtual IOperation &offset(string) = 0;

            virtual string execute() = 0;

            virtual ~IOperation() = default;
        };
    }
#endif //LINQ_IOPERATION_HPP
