//
// Created by eldar on 23.05.22.
//

#ifndef LINQ_ISELECT_H
#define LINQ_ISELECT_H

#include <string>
#include <vector>
#include "../../Linq.h"
#include "LINQ/components/SqlQuery.hpp"
#include "IFrom.h"
#include "../exception/InvalidColumn.hpp"
#include "../exception/InvalidQuery.hpp"

using namespace linq::db;
using namespace linq::abstraction;


namespace linq::interface {
    class Select : public SqlQuery {
    public:
        template<typename ...T>
        explicit Select(Column<T>... rows)

        std::string validateQuery() override {
            _sqlQuery = "SELECT " + _columnName[0];
            for (int i = 1; i < _columnName.size(); ++i) {
                _sqlQuery += ", " + _columnName[i];
            }

            if (!contains("SELECT ")) {
                throw InvalidQuery();
            }

            return _sqlQuery;
        }

        From from(Table table) {
            return From(validateQuery(), table, _columnName);
        }

    private:
        vector<string> _columnName;
    };
}

#endif //LINQ_ISELECT_H
