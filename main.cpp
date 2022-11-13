#include <iostream>
#include "db.h"

using namespace std;

int main()
{
    db_login("ltfysl", "127.0.0.1", "", "", "dbs2");
    db_drop_table("hersteller");
    db_drop_table("hersteller");
}
