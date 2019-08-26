//////////////////////////////////////////////////////////
// Created by 	: Kerem Yollu												
//	Project 		: Multiprise conectée
// Nom			: dbcomm.c
// Header 		: dbcomm.h			
//_________________________Info_________________________
// 
// Libraire pour communiquer avec une base de donees 
//	Postgresql. Capable d'interpreter des commande standars sql 
// Il est très painible a unclure dans un Makefile. 
//////////////////////////////////////////////////////////
// Voila ce q0'uil faut pour la Compilation 
// => -lpq lors du linkage est très important
// => -I la localisastion du include pgsql peut vrairer selon 
// 	l'installation 
//-------------------------------------------------------- 
//	CFLAGS= -Wall -pedantic  
//
//	$(EXEC): main.o dbcomm.o 
//		$(CC) -o $@ $^ $(LDFLAGS) -lpq
//	 
//	 dbcomm.o: dbcomm.c
//		$(CC) -c -I/usr/local/pgsql/include dbcomm.c
//
//////////////////////////////////////////////////////////

#include "main.h"
#include "dbcomm.h"

// fonction pour quiter en cas d'erreur avec sàcurité la connextion a la base de donée 
void do_exit(PGconn *conn, PGresult *res) 
{    
    fprintf(stderr, "%s\n", PQerrorMessage(conn));    
    PQclear(res);
    PQfinish(conn);    
    exit(1);
}



// Fontion chargéé d'éxécuter les fonction sql qui luis sont ransmise 
// ------------------------input------------------------------------ 
// PGconn *conn => descripteur de la connection à la base de données 
// cahr *cmdString => ligne de commande sql à etre éxécuté 
void executeSqlCmd( PGconn *conn, char *CmdString)
{
	PGresult * result;  
			
	// Appelle de lafonction qui vas executer la commande sql et retourne une valeur selon l'état de lexecution de la commande 	
	result = PQexec(conn, CmdString);
 
 	if (PQresultStatus(result) != PGRES_COMMAND_OK) 
	{
        do_exit(conn, result); 
   } 
	
	PQclear(result);  //trè important à executé sinon les message sont confondus par l'interpréteur de commande SQL.    
}

// Fontion de test pour voir si le code fontionne. 
void testDb() 
{ 
	PGconn *conn = PQconnectdb(DB);

   if (PQstatus(conn) == CONNECTION_BAD) 
	{     
     	fprintf(stderr, "Connection to database failed: %s\n",
      PQerrorMessage(conn));
		exit(1); 
   }
 
	executeSqlCmd(conn,"DROP TABLE IF EXISTS Cars"); 
	executeSqlCmd(conn,"CREATE TABLE Cars(Id INTEGER PRIMARY KEY, Name VARCHAR(20), Price INT)"); 
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(1,'Audi',52642)");
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(2,'Mercedes',57127)");
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(3,'Skoda',9000)");
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(4,'Volvo',29000)");
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(5,'Bentley',350000)");
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(6,'Citroen',21000)");
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(7,'Hummer',41400)");
	executeSqlCmd(conn, "INSERT INTO Cars VALUES(8,'Volkswagen',21600)");
	printf("\naccomplisher succesfully\n"); 
	
   PQfinish(conn);    
	exit(1); 
}
