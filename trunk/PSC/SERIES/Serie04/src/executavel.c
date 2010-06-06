#include "Common.h"
#include "UniCurr.h"
#include "Teacher.h"
#include "CDB_Builder.h"
#include <cdb.h>

int main()
{
	 UniCurr * t1 = t1;
	 UniCurr * t2 = t2;
	 UniCurr * t3 = t3;
	 UniCurr * t4 = t4;
	 UniCurr * t5 = t5;
	 Teacher * tt1 = 0;
	 Teacher * tt2 = 0;

	 char string1[]="PDSI|P|32|Com||Processamento Digital de Sinal e Imagem|690";
	 char string2[]="LIC|B|2|Pg;LSD||Laborat�rio de Inform�tica e Computadores|564";
	 char string3[]="AVE|B|8||PSC;AED|Ambientes Virtuais de Execu��o|697";
	 char string4[]="LS|B|8|POO;SI1|PSC;AED|Laborat�rio de Software|889";
	 char string5[]="819|Acilina Nascimento Caneco|d819@deetc.isel.pt";
	 char search[]="AVE";
	 char filename[]="CDB_TESTE_UC";
     int fd;
     struct cdb_make cdbm;
     struct cdb cdb;
        char *data;
        unsigned datalen;

	 
	 
	t1 = UniCurr_new("EICARAMBA","EIC","XPTO;ABRA",NULL,123,'B',1);
	t2 = UniCurr_new_fromString(string1,'|');
	t3 = UniCurr_new_fromString(string2,'|');
	t4 = UniCurr_new_fromString(string3,'|');
	t5 = UniCurr_new_fromString(string4,'|');
	tt1 = Teacher_new("Adolfo","Dias",123);
	tt2 = Teacher_new_FromString(string5,'|');



        fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0666);
        if (cdb_make_start(&cdbm, fd) < 0) {
			puts("Aconteceu um erro na cria��o do ficheiro!");
			exit(-1);
		}

		CDB_insert_UniCurr_by_acronimo(t1, &cdbm);
		CDB_insert_UniCurr_by_acronimo(t2, &cdbm);
		CDB_insert_UniCurr_by_acronimo(t3, &cdbm);
		CDB_insert_UniCurr_by_acronimo(t4, &cdbm);
		CDB_insert_UniCurr_by_acronimo(t5, &cdbm);
		
        

        /* finalize and close the database */
    if (cdb_make_finish(&cdbm) == -1)
		puts("cdb_make_finish failed");
    close(fd);



        fd = open(filename, O_RDONLY);
        cdb_init(&cdb, fd);
        /* initialize key and keylen here */

        /* single-record search. */
        if (cdb_find(&cdb, search, strlen(search)) > 0) {
          datalen = cdb_datalen(&cdb);
          data = malloc(datalen + 1);
          cdb_read(&cdb, data, datalen, cdb_datapos(&cdb));
          data[datalen] = '\0';
          printf("key=%s data=%s\n", search, data);
          free(data);
        }
        else
          printf("key=%s not found\n", search);





	UniCurr_destroyer(t1);
	UniCurr_destroyer(t2);
	UniCurr_destroyer(t3);
	UniCurr_destroyer(t4);
	UniCurr_destroyer(t5);
	Teacher_destroy(tt2);
	Teacher_destroy(tt1);

return 0;	
}
