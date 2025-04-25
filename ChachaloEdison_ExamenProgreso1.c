#include <stdio.h>
#include <string.h>
/*CHACHALO CHACHALO EDISON JAVIER
Desarrollar un programa que me permita conocer las estadísticas de 5 jugadores de basket. Durante 4 partidos. Se debe ingresar los puntos anotados por cada jugador durante cada partido y obtener el mejor jugador con base al promedio de los puntos ingresados.

Se debe imprimir una tabla con los resultados
Ingresar nombres de los jugadores y validar entradas

El mejor es …
*/
int main(int argc, char *argv[])
{

    char jugador[5][30];
    float promedio[5];
    int partidos[4];
    int len, val;
    int nombre_valido, partido_valido;
    int contP = 0;
    float tpuntos;
    char aux_nombre[30];
    float aux_partido;
    printf("\n==JUGADOR DEL CAMPEONATO==\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\nJUGADOR %d\n", i + 1);
        do
        {
            nombre_valido = 1;
            printf("Ingrese el nombre del jugador : ");
            fflush(stdin);
            fgets(jugador[i], 30, stdin);

            len = strlen(jugador[i]) - 1;
            jugador[i][len] = '\0';

            len = strlen(jugador[i]);
            if (len > 0 && jugador[i][len - 1] == '\n')
            {
                jugador[i][len - 1] = '\0';
            }
            if (strlen(jugador[i]) == 0)
            {
                printf("Error: No ha ingresado el nombre del jugador\n");
                // getchar();
                nombre_valido = 0;
            }

            for (int j = 0; jugador[i][j] != '\0'; j++)
            {
                if (!((jugador[i][j] >= 'A' && jugador[i][j] <= 'Z') || (jugador[i][j] >= 'a' && jugador[i][j] <= 'z') || (jugador[i][j] == ' ')))
                {
                    printf("Error: El nombre no puede contener numeros\n");
                    nombre_valido = 0;
                    break;
                }
            }
        } while (!nombre_valido);
        contP=0;
        do
        {
            tpuntos = 0;
            partido_valido = 1;
            
            do
            
            {
                printf("Ingrese los puntos del partido %d: ", contP + 1);
                val = scanf("%f", &partidos[contP]);
                if (val != 1)
                {
                    printf("Error: Solo puede ingresar numeros\n");
                    fgetchar();
                    partido_valido = 0;
                    continue;
                }
                if (partidos[contP] < 0)
                {
                    printf("Error: No puede ingesar numeros negativos\n");
                    partido_valido = 0;
                    continue;
                }
                contP++;
                tpuntos += partidos[contP];
            } while (contP < 4);


        } while (!partido_valido);
        promedio[i] = tpuntos / 4;
        printf("\nSu promedio es: %.2f\n", promedio[i]);

        for (int i = 0; i < 5; i++)
        {
            for (int j = i; j < 5; j++)
            {
                if (partidos[i] > partidos[j])
                {
                    aux_partido = partidos[i];
                    partidos[i] = partidos[j];
                    partidos[j] = aux_partido;

                    for (int k = 0; k < 30; k++)
                    {
                        aux_nombre[k] = jugador[i][k];
                        jugador[i][k] = jugador[j][k];
                        jugador[j][k] = aux_nombre[k];
                    }
                }
            }
        }
    
    }

    printf("\n== PODIO ==\n");
    for (int i = 0; i < 5; i++)
    {
        printf("#\t\tNombre\t\tPromedioPts\n");
        printf("%d",i+1,jugador[i],promedio[i]);
    }
    

    return 0;
}