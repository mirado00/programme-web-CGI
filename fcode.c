#include "code.h"

char **declaration2D(int dim1, int dim2){
    char **var=malloc(sizeof(char *)*dim1);
    for(int i=0;i<dim1;i++){
        var[i]=malloc(dim2);
    }
    return var;
}
void showCode(char *chemin){
    FILE *file=NULL;
    char *tmp=malloc(1000);
    file=fopen(chemin, "r");
    if(file!=NULL){
        while(!feof(file)){
            fgets(tmp, 1000, file);
            printf("%s", tmp);
        }
        fclose(file);
    }
}
void getInfoUser(char **user, char **script, int *nbr){
    FILE *file=NULL;
    char *test=malloc(400);
    char *test1=malloc(400);
    char *test2=malloc(400);
    int i=0;
    char *tmp=malloc(400);
    file=fopen("/etc/passwd", "r");
    while(!feof(file)){
        fgets(tmp, 400, file);
        sscanf(tmp, "%[^:]:%*[^:]:%[^:]:%*[^:]:%*[^:]:%*[^:]:%[^\n]", test, test1, test2);
        
        if(atoi(test1)>=1000 && atoi(test1)<=60000){
            strcpy(user[i], test);
            strcpy(script[i], test2);
            i++;
        }
    }
    *nbr=i-1;
}
void getInfoAuthlog(char **date, char **time, char **session, char **user, int *nbr){
    FILE *file=NULL;
    int i=0;
    char *tmp=malloc(400);
    file=fopen("/var/log/auth.log", "r");
    while(!feof(file)){
        fgets(tmp, 400, file);
        if(strstr(tmp, "session") && strstr(tmp, "for user")){
            sscanf(tmp, "%[^T]T%[^.].%*[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %[^ ] %*[^ ] %*[^ ] %[^\n]", date[i], time[i], session[i], user[i]);
            sscanf(user[i], "%[^()]", user[i]);
            i++;
        }     

    }
    *nbr=i-1;
}
char **split(char *chaine, char *delimiter, int *nbr){
    char **result=declaration2D(200, 400);
    char *separed=malloc(400);
    int i=0;
    separed=strtok(chaine ,delimiter);
    while(separed!=NULL){
        strcpy(result[i], separed);
        separed=strtok(NULL, delimiter);
        i++;
    }
    *nbr=i-1;
    return result;
}
char *getRequet(char *requet){
    char **get=declaration2D(10, 400);
    int nbr=0;
    get=split(requet, "=", &nbr);
    strcpy(requet, get[1]);
    return requet;
}