#include "code.h"

int main(){
    printf("Content-type:text/html\n\n");
    showCode("./menu.html");
    int nbr=0;
    char **user=declaration2D(50, 200);
    char **script=declaration2D(50, 200);
    getInfoUser(user, script, &nbr);
    printf("<div>"
            "<div class='table-title'>"
            "<h1>List d'Utilisateur</h1>"
            "</div>"
            "<table>");
    printf("<tr><th>Utilisateur</th><th>Dossier personnel</th><th>Interpreteur du Commande</th></tr>\n");
    for (int i=0;i<nbr;i++){
       printf("<tr><td>%s</td><td>/home/%s</td><td>%s</td></tr>", user[i], user[i], script[i]);
    }
    printf("</table>\n</div>\n");
    printf(" </div>"
            "</div>"
            "</div>"
        "</body>"
        "</html>");
    return 0;
}