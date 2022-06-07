//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_ICURSOR_HPP
#define ETDMYSQL_ICURSOR_HPP

#include "Connector.hpp"

namespace etd::iface{
    class ICursor {
    public:
        virtual void execute(const std::string &query) = 0;

        virtual etd::Answer executeOne(const std::string &query) = 0;

        virtual void accept() = 0;

    };
}


#endif //ETDMYSQL_ICURSOR_HPP
