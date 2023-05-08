/****************************************************************************
 * Data Versao: Maio 2023
 Responsavel: Daniel Abratte
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_MATCHES 15

//Declaro a funcao funcaourl, funcao que valida a URL
void funcaourl(
  char *url
);


int main() {

    char cad[100], *url;

    printf("Digite URL para validar: \n");
    scanf("%s",cad);

    url = (char *)malloc(((strlen(cad)+1)) * sizeof(char));
    strcpy(url,cad);

    //Chamada a funcao que valida URL
    funcaourl(url);    

    //libera memoria do ponteiro url
    free(url);

    return 0;
}

void funcaourl(char *url)
{
    regex_t regex;
    regmatch_t grupo[MAX_MATCHES];
    int control, len, i,g;
    char name[30];
    const char limite[2] = "/";
    char *token;

    //Padrao da expressao regular
    char *padrao = "^(https?|ftp|ssh):\\/\\/((\\w+)(:|%)?(\\w+@))?([a-zA-Z0-9_-]+\\.)*([a-zA-Z0-9_-]+\\.[a-zA-Z]{2,6})?(:[0-9]{1,5})?(\\/.*)?(\\?.*)?(#.*)?$";
 
    //Compila a expressao regular
    control = regcomp(&regex, padrao, REG_EXTENDED);
    if (control) {
        printf("Ocorreu um erro ao compilar a expressao regular \n");
        return;
    }

    unsigned int offset = 0;
    char * cursor = url;
    //Valida a URL com o padrao compilado
    control = regexec(&regex, url, MAX_MATCHES, grupo, 0);
    if (!control) {
      printf("URL VALIDA!! %s\n", url); 

      //repe
      for (i = 1; i <= MAX_MATCHES; i++)
      {
        if (grupo[i].rm_so != (size_t)-1)
        {
          memset(name, 0, sizeof(name));

          switch(i)
          {
            case 1:                             //Protocolo
            {
              len = grupo[i].rm_eo - grupo[i].rm_so;
              strncpy(name, url + grupo[i].rm_so, len);
              printf("Protocolo: %s\n", name);
              break;
            }
            case 3:                             //Usuario opcional
            {
              if ( grupo[i].rm_eo - grupo[i].rm_so > 0)
              {
                len = grupo[i].rm_eo - grupo[i].rm_so;
                strncpy(name, url + grupo[i].rm_so, len);
                printf("Usuario: %s\n", name);
              }
              break;
            }
            case 5:                             //Senha opcional
            {
              if ( grupo[i].rm_eo - grupo[i].rm_so > 0)
              {
                len = grupo[i].rm_eo - grupo[i].rm_so;
                strncpy(name, url + grupo[i].rm_so, (len-1));
                printf("Senha: %s\n", name);
              }
              break;
            }
            case 6:                            //Host
            {
              if ( grupo[i].rm_eo - grupo[i].rm_so > 0)
              {
                len = grupo[i].rm_eo - grupo[i].rm_so;
                strncpy(name, url + grupo[i].rm_so, (len-1));
                printf("Host: %s\n", name);
              }
              break;
            }
            case 7:                            //Dominio
            {
              if ( grupo[i].rm_eo - grupo[i].rm_so > 0)
              {
                len = grupo[i].rm_eo - grupo[i].rm_so;
                strncpy(name, url + grupo[i].rm_so, len);
                printf("Dominio: %s\n", name);
              }
              break;
            }
            case 8:                            //Porta
            {
              if ( grupo[i].rm_eo - grupo[i].rm_so > 0)
              {
                len = grupo[i].rm_eo - grupo[i].rm_so;
                strncpy(name, url + grupo[i].rm_so, len);
                printf("Porta: %s\n", name);
              }
              break;
            }
            case 9:                           //Path e parametros
            {
              if ( grupo[i].rm_eo - grupo[i].rm_so >= 0)
              {
                g = 1;
                
                len = grupo[i].rm_eo - grupo[i].rm_so;
                strncpy(name, url + grupo[i].rm_so, len);
                
                token = strtok(name, limite);
                
                while( (token != NULL) && (i <= MAX_MATCHES) ) {
                    if (i == 9 )
                      printf( "Path: %s\n", token );
                    else
                    {
                      printf( "Parametro %i: %s\n",g, token );
                      g++;
                    }
                    
                    i++;   
                    token = strtok(NULL, limite);
                }
              }
            }

            default:
          }
        }
      }

    } else if (control == REG_NOMATCH) {
        printf("URL nao valida!!\n");
    } else {
        printf("Nao foi possivel executar a expressao regular \n");
        return;
    }

    // Libera a memoria da expressao regular
    regfree(&regex);

}
