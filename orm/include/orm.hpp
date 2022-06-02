//
// Created by eldar on 21.05.22.
//

#ifndef orm_orm_H
#define orm_orm_H
#define ORM_FUNCTION
#include "orm/components/Function.hpp"
#include "orm/components/Database.hpp"
#include "orm/query/Select.hpp"
#define json std::string
#define integer int
#define varchar(val) std::string
#define tinyint(val) int
#define datetime int
#define text std::string
#define longtext std::string
#define smallint int

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


#define OrmFunction(return_type, name, ...) \
orm::db::Function<return_type, ##__VA_ARGS__> name = controller.addFunction<return_type, ##__VA_ARGS__>(#name);
#endif //orm_orm_H
