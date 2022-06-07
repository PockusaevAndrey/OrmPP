//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_CONNECTOR_HPP
#define ETDMYSQL_CONNECTOR_HPP

#include <iostream>
#include <memory>
#include <utility>
#include <any>
#include <vector>
#include <map>

namespace etd {
    using Answer = std::map<std::string, std::vector<std::string>>;

    namespace error{
        class TransactionFailed;
    }

    namespace iface {
        class IClient;

        class ICursor;

        class IQueryCollector;
    }

    namespace mysql {
        class Client;

        class Cursor;

        class QueryCollector;
    }

}

#endif //ETDMYSQL_CONNECTOR_HPP
