//
// Created by eldar on 12.05.22.
//

#ifndef LINQ_LINQOPERATION_HPP
#define LINQ_LINQOPERATION_HPP

#include "IOperable.hpp"
#include "../Linq/Linq.hpp"
#include "include/etddb/ICursor.hpp"

namespace etd::linq {

    class LinqOperation : public IOperable {
    public:

        LinqOperation() = default;

        LinqOperation(unique_ptr<etd::iface::ICursor> cursor, string nameDb) {
            /// Useless variable.
            //_mySqlDb = MySQLConnection::create(nameDb);

            _isGrouped = true;
            cursor.swap(_groupDb);
        }

        string execute(Linq &linq) override {
            string sqlQuery = linq.execute();
            string queryResult = executeQuery(sqlQuery);
            return queryResult;
        }

        ~LinqOperation() override = default;

    protected:
        string executeQuery(const string &sqlQuery) override {
            std::string query;
            if (_isGrouped)
                query = _groupDb->executeOne(sqlQuery).begin()->second[0];
            else
                /// Useless SQL query.
                //query = (std::string) _mySqlDb->storeQuery(sqlQuery)[0][0];
                return query;
        }

        /// Useless variable.
        // MySQLClass *_mySqlDb = nullptr;

        unique_ptr<etd::iface::ICursor> _groupDb = nullptr;
        bool _isGrouped = false;

    };

}
#endif //LINQ_LINQOPERATION_HPP
