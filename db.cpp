#include <iostream>
#include <string>
#include "db.h"
#include <libpq-fe.h>

using namespace std;
#define cstr(str) str.c_str()

PGconn *conn;
PGresult *res;

// Check for fails or errors
int hasErrors()
{
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        cerr << "command failed: " << PQerrorMessage(conn) << endl;
        db_rollback();
        throw;
        PQclear(res);
        PQfinish(conn);
        return 1;
    }
    return -1;
}

// Datenbank-Login
// rc: 0 = ok, -1 = error
int db_login(const string &user, const string &password, const string &host, const string &port, const string &dbname)
{
    cout << user << " "
         << " " << password << " "
         << " " << host << " "
         << " " << port << " "
         << " " << dbname << " " << endl;

    conn = PQsetdbLogin(cstr(host), cstr(port), NULL, NULL, cstr(dbname), cstr(user), cstr(password));

    if (PQstatus(conn) != CONNECTION_OK)
    {
        cerr << "Connection to database failed: " << PQerrorMessage(conn) << endl;
        PQfinish(conn);
        return -1;
    }
    return 0;
}

// Datenbank-Logout
void db_logout()
{
    PQfinish(conn);
    cout << "Logged out of Database " << endl;
}

// -------------------
// Transaktionsbefehle
// -------------------

// rc: 0 = ok, -1 = error
int db_begin()
{
}

int db_commit()
{
}

int db_rollback()
{
}

// ----------------------------------
// DB-Schema anlegen und zurücksetzen
// ----------------------------------

int db_flush()
{
    const char *statement = "DROP TABLE IF EXISTS hersteller CASCADE; DROP TABLE IF EXISTS produkt CASCADE;";
    res = PQexec(conn, statement);

    if (hasErrors)
        return -1;

    return 0;
    cout << "Table hersteller created" << endl;
}

// Hersteller-Tabelle anlegen
// rc: 0 = ok, -1 = error
int db_create_table_hersteller()
{
    const char *statement = "CREATE TABLE hersteller(hn varchar(4), name varchar(30), stadt varchar(30));";
    res = PQexec(conn, statement);

    if (hasErrors())
        return -1;

    cout << "Table hersteller created" << endl;
    return 0;
}

// Produkt-Tabelle anlegen
// rc: 0 = ok, -1 = error
int db_create_table_produkt()
{
    const char *statement = "CREATE TABLE produkt(pnr varchar(4), name varchar(30), preis numeric(8, 2), hnr varchar(4), FOREIGN KEY (hnr) REFERENCES hersteller (hnr) ON DELETE CASCADE );";
    res = PQexec(conn, statement);

    if (hasErrors())
        return -1;

    cout << "Table produkt created" << endl;
    return 0;
}

// Tabelle tablename löschen und aus DB-Schema entfernen
// rc: 0 = ok, -1 = error
int db_drop_table(const string &tablename)
{
    string statement = "DROP TABLE IF EXISTS " + tablename + " CASCADE;";
    res = PQexec(conn, cstr(statement));
    if (hasErrors())
        return -1;

    cout << "Table gelöscht" << endl;
    return 0;
}

// -------------------------------------
// Existenz/Anzahl von Tupel zurückgeben
// -------------------------------------

// Prüfen, ob hnr in Hersteller schon vorhanden ist?
// rc: 0 = noch nicht da, 1 = schon da, -1 = error
int db_check_hnr(const string &hnr)
{
}

// Prüfen, ob pnr in Produkt schon vorhanden ist?
// rc: 0 = noch nicht da, 1 = schon da, -1 = error
int db_check_pnr(const string &pnr)
{
}

// Anzahl der Tupel in der Tabelle tablename zurückgeben
// rc: n = Anzahl der Tupel (n>=0), -1 = error
int db_count(const string &tablename)
{
}

// -------------------------------
// Tupel einfügen, ändern, löschen
// -------------------------------

// Einfuegen Produkt
// rc: 0 = ok, -1 = error
int db_insert_produkt(const string &pnr, const string &name, const string &preis, const string &hnr)
{
}

// Einfuegen Hersteller
// rc: 0 = ok, -1 = error
int db_insert_hersteller(const string &hnr, const string &name, const string &stadt)
{
}

// Ändern Produkt
// rc: 0 = ok, -1 = error
int db_update_produkt(const string &pnr, const string &name, const string &preis, const string &hnr)
{
}

// Ändern Hersteller
// rc: 0 = ok, -1 = error
int db_update_hersteller(const string &hnr, const string &name, const string &stadt)
{
}

// Löschen Produkt
// rc: 0 = ok, -1 = error
int db_delete_produkt(const string &pnr)
{
}

// Löschen Hersteller und aller abhängigen Produkte
// rc: 0 = ok, -1 = error
int db_delete_hersteller(const string &hnr)
{
}

// Loeschen des kompletten Tabelleninhalts beider Tabellen
// rc: 0 = ok, -1 = error
int db_delete()
{
}
