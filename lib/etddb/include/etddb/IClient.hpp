//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_ICLIENT_HPP
#define ETDMYSQL_ICLIENT_HPP

#include "Connector.hpp"

namespace etd::iface {
    class IClient {
    public:
        virtual void refresh() = 0;

        virtual void close() = 0;

        virtual etd::Answer send(const std::string &, const std::string &database) = 0;

        virtual void send(std::shared_ptr<IQueryCollector> collector) = 0;

        virtual std::unique_ptr<etd::iface::ICursor> cursor(std::string database) = 0;
    };
}


#endif //ETDMYSQL_ICLIENT_HPP
