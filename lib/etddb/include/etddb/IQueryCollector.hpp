//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_IQUERYCOLLECTOR_HPP
#define ETDMYSQL_IQUERYCOLLECTOR_HPP

//
// Created by pokys on 19.04.2022.
//

#include <any>
#include <utility>
#include <memory>
#include <iostream>
#include "Connector.hpp"


namespace etd::iface {
    class IQueryCollector {

    public:

        virtual void add(const std::string &query) = 0;

        virtual std::vector<std::string> get() = 0;

        virtual void use(const std::string &db) = 0;

        virtual std::string database() = 0;
    };
}
#endif //ETDMYSQL_IQUERYCOLLECTOR_HPP
