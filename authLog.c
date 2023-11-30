#include "code.h"
int main(){
    char **date=declaration2D(1500, 400);
    char **time=declaration2D(1500, 400);
    char **session=declaration2D(1500, 400);
    char **user=declaration2D(1500, 400);
    char *requet=malloc(1000);
    char **requetSepared=declaration2D(50, 400);
    int nbr=0, page=3 , a=0;
    
    requet=getenv("QUERY_STRING");
    
    printf("Content-type:text/html\n\n");
    showCode("./menu.html");
    
    getInfoAuthlog(date, time, session, user, &nbr);
    printf("<div>"
            "<div class='table-title flex'>"
            "<h1>Authentification d'Utilisateur</h1>"
            "<div class='pagination flex'>");
    
    /* ----pagination de 10 ligne */
    if(requet!=NULL){
        if(strstr(requet, "page=")){
            getRequet(requet);
            page=(atoi(requet)<=3)?4:atoi(requet);
            
        }
    }
    for(int i=page-3;i<page+3;i++){
        printf("<form action='http://www.webc.com/cgi-bin/authLog.cgi' method='get'><input class='button-page' type='submit' name='page' value='%d'></form>", i+1);
    }

    printf("<form action='http://www.webc.com/cgi-bin/authLog.cgi' method='get'><input class='button-page1' type='submit' name='affichage' value='afficher toute'></form>");
    printf("</div></div><table>");
    
    printf("<tr><th>Date</th><th>Heure</th><th>Session(opened/closed)</th><th>Utilisateur</th></tr>\n");
    
    requet=getenv("QUERY_STRING");
    if(requet!=NULL){
        /* ----pagination de 10 ligne */
        if(strstr(requet, "page=")){
            getRequet(requet);
            a=atoi(requet);
            for (int i=(a-1)*10;i<a*10;i++){
                printf("<tr style='color: %s;'><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n", (strcmp(session[i], "opened")==0)?"green":"black",  time[i], date[i], session[i], user[i]);

            }
        }
        /*  afficher toute ligne */
        if(strstr(requet, "affichage=")){
            for (int i=0;i<nbr;i++){
                printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n", time[i], date[i], session[i], user[i]);
            }
        }
        if(strstr(requet, "search=")){
            getRequet(requet);
            for(int i=0;i<nbr;i++){
                if(strcmp(requet, user[i])==0){
                    printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n", time[i], date[i], session[i], user[i]);
                }
            }
        }
    }
    else{
        for (int i=0;i<nbr;i++){
            printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n", time[i], date[i], session[i], user[i]);
        }
    }
    printf("</table>\n</div>\n");
    printf(" </div>"
            "</div>"
            "</div>"
        "</body>"
        "</html>");
    return 0;
}