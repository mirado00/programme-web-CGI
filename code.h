#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **declaration2D(int dim1, int dim2);
void getInfoUser(char **user, char **script, int *nbr);
void getInfoAuthlog(char **date, char **time, char **session, char **user, int *nbr);
char **split(char *chaine, char *delimiter, int *nbr);
void showCode(char *code);