//
// Created by eldar on 12.05.22.
//

#ifndef LINQ_LINQMYSQL_HPP
#define LINQ_LINQMYSQL_HPP

#include "../Linq/IOperation.hpp"

namespace etd::linq {

    class MySql : public etd::linq::IOperation {

    public:

        MySql() = default;

        IOperation &select(string column) override {
            _query += "SELECT " + column + " ";
            return *this;
        }

        IOperation &from(string table) override {
            _query += "\nFROM " + table + " ";
            return *this;
        }

        IOperation &where(string condition) override {
            _query += "\nWHERE " + condition + " ";
            return *this;
        }

        IOperation &orderBy(string column) override {
            _query += "\nORDER BY " + column + " ";
            return *this;
        }

        IOperation &groupBy(string column) override {
            _query += "\nGROUP BY " + column + " ";
            return *this;
        }

        IOperation &having(string condition) override {
            _query += "\nHAVING " + condition + " ";
            return *this;
        }

        IOperation &limit(string limit) override {
            _query += "\nLIMIT " + limit + " ";
            return *this;
        }

        IOperation &offset(string limit) override {
            _query += "OFFSET " + limit + " ";
            return *this;
        }

        string execute() override {
            string result = _query + ";";
            return result;
        }

//endregion
        ~MySql() override = default;

    protected:
        string _query;
    };
}
#endif //LINQ_LINQMYSQL_HPP
