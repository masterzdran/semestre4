#include "command.h"

CmdFx cmds[] = {
  { "exit",  	0, 		"Terminate demo" },
  { "help",  	help, 	0 },
  { "exec",  	system, "Execute system command" },
  { "save",		save,	"Grava no ficheiro indicado a informa��o corrente." },
  { "load",  	load,	"Rep�e a informa��o corrente a partir do ficheiro indicado" },
  { "guess", 	guess,	"Tenta adivinhar o objecto fazendo perguntas sobre as suas caracter�sticas" },
  { "add",  	add,	"Acrescenta o objecto indicado perguntando o que o distingue do objecto proposto no �ltimo comando 'guess'" },
  { "rem",  	rem,	"Remove o objecto indicado, removendo tamb�m a caracter�stica que o distingue." },
  {0,0,0}  /*End of comands*/
};


	int save(const char *arg){
		FILE *file=fopen(arg,"w");
		if(!file){
			printf ("Erro ao abrir o ficheiro %s",arg );
			return 0
		}
		fputs("bla bla bla");
		fclose(file);
		return 1;
	}
	int load(const char *arg){
		FILE *file=fopen(arg,"r");
		if(!file){
			printf ("Erro ao abrir o ficheiro %s",arg );
			return 0
		}
		fgets(node, MAX_LINE, file);
		fclose(file);
		return 1;
	}
	int guess(const char *arg){
		return 0;
	}
	int add(const char *arg) {
		return 0;
	}
	int rem(const char *arg){
		return 0;
	}
	
