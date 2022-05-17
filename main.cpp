#include <iostream>
#include <memory>
#include "Linq/includes/Linq.h"
#include "MySQL/includes/MySQLSelect.h"

using namespace std;
using namespace etd::linq;

#include <iostream>
using namespace std;

int main()
{

    shared_ptr<IOperationSelect<MySqlSelect>> select = make_shared<MySqlSelect>();
    Linq linq(select);
    linq.getController<MySqlSelect>()
            .select("*")
            .from("Task");

    string aq = "32";
    for (int i = 0; i < 3; i++)
    {
        linq.getController<MySqlSelect>()
                .where("id = " + aq);

    }

    linq.getController<MySqlSelect>()
            .closeScope();

    string sq = "12";
    for (int i = 0; i < 2; i++)
    {
        linq.getController<MySqlSelect>()
                .orderBy("id = " + sq);

    }

    cout << linq.getController<MySqlSelect>()
            .execute() << endl;

    return 0;
}
