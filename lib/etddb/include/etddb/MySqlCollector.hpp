//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_MYSQLCOLLECTOR_HPP
#define ETDMYSQL_MYSQLCOLLECTOR_HPP


#include "IQueryCollector.hpp"

namespace etd::mysql {
    class QueryCollector : public etd::iface::IQueryCollector {
    protected:
        std::vector<std::string> query;
        std::string _db;
    public:
        void use(const std::string &db) override;

        void add(const std::string &query) override;

        std::vector<std::string> get() override;

        std::string database() override;
    };
}


#endif //ETDMYSQL_MYSQLCOLLECTOR_HPP
