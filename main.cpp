#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sqlite3.h>
#include <string.h>
#include <string>

using namespace std;

/*
class Main{

static void main (int args[]){

}
};
*/
string get_env_var(string const &key) {
    char * val;
    val = getenv(key.c_str());
    string retval = "";
    if (val != NULL) {
        retval = val;
    }

    return retval;
}

int main(int, char**){

    sqlite3*        db;
    char            queue[999];
    sqlite3_stmt*    stmt;
    int             row = 0;
    int             bytes;
    const unsigned char*          text;
    string db_path = get_env_var("DB_PATH");

    queue[sizeof queue - 1] = '\0';
    snprintf(queue, sizeof queue - 1, "SELECT * FROM country");

    if (sqlite3_open(db_path.c_str(), &db) != SQLITE_OK) {
        cout << "Error opening database.";
        return 2;
    };

    printf("Query: %s\n", queue);

    sqlite3_prepare(db, queue, sizeof queue, &stmt, NULL);

    bool done = false;
    while (!done){
        cout << printf("In select while\n");
        switch (sqlite3_step(stmt)) {
            case SQLITE_ROW:
                bytes = sqlite3_column_bytes(stmt, 0);
                text = sqlite3_column_text(stmt, 1);
                cout << printf ("count %d: %s (%d bytes)\n", row, text, bytes);
                row++;
                break;

            case SQLITE_DONE:
                done = true;
                break;
            
            default:
                cout << fprintf(stderr, "Failed.\n");
                return 1;
        }

    }
   // sqlite3_exec(db, "SELECT ALL FROM country;");
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}