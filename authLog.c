#include "code.h"
int main(){
    char **date=declaration2D(1500, 400);
    char **time=declaration2D(1500, 400);
    char **session=declaration2D(1500, 400);
    char **user=declaration2D(1500, 400);
    int nbr=0;
    getInfoAuthlog(date, time, session, user, &nbr);
    for (int i=0;i<nbr;i++){
        printf("%s\t%s\t%s\t\t%s\n", date[i], time[i], session[i], user[i]);
    }
    return 0;
}