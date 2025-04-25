/*CHACHALO CHACHALO EDISON JAVIER
Desarrollar un programa que me permita conocer las estadísticas de 5 jugadores de basket. Durante 4 partidos. 
Se debe ingresar los puntos anotados por cada jugador durante cada partido y 
obtener el mejor jugador con base al promedio de los puntos ingresados.
Ingresar nombres de los jugadores y validar entradas
Se debe imprimir una tabla con los resultados
y Mostrar: El mejor es …
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char jugador[5][30];
    float promedio[5];
    int puntos[5][4];
    int len, val;
    int nombre_valido, partido_valido;
    float tpuntos;
    printf("\n== JUGADOR DEL CAMPEONATO ==\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\nJUGADOR %d\n", i + 1);

        // Validación del nombre
        do
        {
            nombre_valido = 1;
            printf("Ingrese el nombre del jugador: ");
            fflush(stdin);
            fgets(jugador[i], 30, stdin);

            // Eliminar salto de línea
            len = strlen(jugador[i]);
            if (len > 0 && jugador[i][len - 1] == '\n') {
                jugador[i][len - 1] = '\0';
            }

            if (strlen(jugador[i]) == 0)
            {
                printf("Error: No ha ingresado el nombre del jugador.\n");
                nombre_valido = 0;
            }

            for (int j = 0; jugador[i][j] != '\0'; j++)
            {
                if (!((jugador[i][j] >= 'A' && jugador[i][j] <= 'Z') || 
                      (jugador[i][j] >= 'a' && jugador[i][j] <= 'z') || 
                       jugador[i][j] == ' '))
                {
                    printf("Error: El nombre no puede contener numeros.\n");
                    nombre_valido = 0;
                    break;
                }
            }

        } while (!nombre_valido);

        tpuntos = 0;

        // Registro de puntos por partido
        for (int j = 0; j < 4; j++)
        {
            do
            {
                partido_valido = 1;
                printf("Ingrese los puntos del partido %d: ", j + 1);
                val = scanf("%d", &puntos[i][j]);

                if (val != 1)
                {
                    printf("Error: Solo puede ingresar numeros.\n");
                    while (getchar() != '\n'); // Limpiar buffer de entrada correctamente
                    partido_valido = 0;
                    continue;
                }

                if (puntos[i][j] < 0)
                {
                    printf("Error: No puede ingresar numeros negativos.\n");
                    partido_valido = 0;
                    continue;
                }

                tpuntos += puntos[i][j];

            } while (!partido_valido);
        }

        promedio[i] = tpuntos / 4.0;
        printf("\nSu promedio es: %.2f\n", promedio[i]);
    }

    // Mostrar la tabla de resultados
    printf("\n== TABLA DE RESULTADOS ==\n");
    printf("#\tNombre\t\tP1\tP2\tP3\tP4\tPromedioPts\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%-15s\t%d\t%d\t%d\t%d\t%.2f\n", 
            i + 1, jugador[i], puntos[i][0], puntos[i][1], puntos[i][2], puntos[i][3], promedio[i]);
    }

    // Buscar al mejor jugador con el mayor promedio
    int mejorJugador = 0;
    for (int i = 1; i < 5; i++)
    {
        if (promedio[i] > promedio[mejorJugador])
        {
            mejorJugador = i;
        }
    }

    // Mostrar el mejor jugador
    printf("\nEl mejor jugador es: %s\n", jugador[mejorJugador]);
    printf("Promedio: %.2f\n", promedio[mejorJugador]);

    return 0;
}