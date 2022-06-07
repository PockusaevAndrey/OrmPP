//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_MYSQLQUERYCOLLECTOR_HPP
#define ETDMYSQL_MYSQLQUERYCOLLECTOR_HPP

#include "MySqlCollector.hpp"
#include "ICursor.hpp"
#include "IClient.hpp"

namespace etd::mysql {
    class Cursor : public etd::iface::ICursor {
    public:
        Cursor(std::string database, std::shared_ptr<etd::iface::IClient> connection);

        etd::Answer executeOne(const std::string &query) override;

        void execute(const std::string &query) override;

        void accept() override;


    protected:
        std::string database;
        std::shared_ptr<etd::iface::IClient> connection;
        std::shared_ptr<iface::IQueryCollector> collector;

    };
}


#endif //ETDMYSQL_MYSQLQUERYCOLLECTOR_HPP
