//
// Created by eldar on 21.05.22.
//

#ifndef orm_orm_H
#define orm_orm_H

#include "orm/components/Database.hpp"
#define OrmDatabase(name, realization) \
class name : public orm::db::Database {public: \
name() : Database(#name){}           \
realization                            \
};

#define OrmTable(name, realization) \
class name : public orm::db::Table { \
public:                \
name(std::string table): Table(table){};             \
realization                                    \
};                                  \
name t##name = controller.addTable<name>(#name);

#define OrmColumn(type, name) \
orm::db::Column<type> name = controller.addColumn<type>(#name);
#endif //orm_orm_H
