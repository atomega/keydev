
#include "/usr/include/postgresql/libpq-fe.h"

#define DB "user=kerem password=kemumu586591 dbname=multiprise"


void executeSqlCmd( PGconn *conn, char *CmdString); 
void do_exit(PGconn *conn, PGresult *res); 
void testDb(); 
