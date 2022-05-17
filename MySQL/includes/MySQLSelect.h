//
// Created by eldar on 14.05.22.
//

#ifndef LINQ_MYSQLSELECT_H
#define LINQ_MYSQLSELECT_H


#include "../../Linq/includes/Interfaces/IOperationSelect.h"

using namespace etd::linq;

class MySqlSelect : public IOperationSelect<MySqlSelect>
{

public:

    MySqlSelect() = default;

    MySqlSelect &select(std::string column) override;

    MySqlSelect &from(std::string table) override;

    MySqlSelect &where(std::string condition) override;

    MySqlSelect &orderBy(std::string column) override;

    MySqlSelect &groupBy(std::string column) override;

    MySqlSelect &having(std::string condition) override;

    MySqlSelect &limit(std::string limit) override;

    MySqlSelect &offset(std::string limit) override;

    MySqlSelect &whereAnd() override;

    MySqlSelect &whereOr() override;

    MySqlSelect &closeScope() override;

    std::string execute() override;

//endregion
    ~MySqlSelect() override = default;

private:
    std::string _query;
};

#endif //LINQ_MYSQLSELECT_H
