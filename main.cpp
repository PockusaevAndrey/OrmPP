//#include <iostream>
#include <include/etddb/MySqlClient.hpp>
#include <utility>
#include "include/etddb/Connector.hpp"
#include "Linq/IOperation.hpp"
#include "Linq/Linq.hpp"
#include "MySQL/LinqMySQL.hpp"

using namespace std;
using namespace etd::linq;

int main() {

    shared_ptr<MySql> mySql(new MySql());
    Linq linq(mySql);
    string mySqlResult = linq.select("*")
            .from("Task")
            .where("id = 1")
            .execute();

    cout << mySqlResult << endl;


    return 0;
}
