//
// Created by pokys on 19.04.2022.
//

#ifndef ETDMYSQL_MYSQLCLIENT_HPP
#define ETDMYSQL_MYSQLCLIENT_HPP

#include "MySqlCursor.hpp"
#include <mysql/mysql.h>
#include <mysql++/mysql++.h>


namespace etd::mysql {
    class Client : public iface::IClient {
    public:

        Client(const std::string &host, int port, std::string user, std::string password);

        void refresh() override;

        etd::Answer send(const std::string &data, const std::string &database) override;
        void send(std::shared_ptr<iface::IQueryCollector> collector) override;
        void close() override;

        std::unique_ptr<etd::iface::ICursor> cursor(std::string database) override;

    protected:
        std::unique_ptr<mysqlpp::Connection> connection;
        const std::string &host, user, password;
        int port;
        std::shared_ptr<iface::IClient> this_ptr;
    };
}


#endif //ETDMYSQL_MYSQLCLIENT_HPP
