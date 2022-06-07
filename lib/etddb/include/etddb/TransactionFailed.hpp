//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_TRANSACTIONFAILED_HPP
#define ETDMYSQL_TRANSACTIONFAILED_HPP


#include <exception>
#include "Connector.hpp"


namespace etd::error{

    class TransactionFailed: public std::runtime_error {
    public:
        TransactionFailed(const char* what);
    };
}


#endif //ETDMYSQL_TRANSACTIONFAILED_HPP
