/* Ce module définit les fonctions de Erastosthène.
 * 
 * @author : KANG Jiale "kanngjle@gmail.com" et ZHANG Liyun "leo.zhangliyun@stu.xidian.edu.cn"
 * Creation @date : 03-Dec-2020 10:21
 * Last file update : 12-Jan-2021 21:42
 */

#include <stdio.h>
#include <stdlib.h>

/* MAXNUM : Ce programme peut trouver les numéro de 1 à MAXNUM. */

#define CAPACITEMAX 1000
typedef int ensemble[CAPACITEMAX];

/*
 * Rôle : Initialise le ensemble.
 * ens[i] = 0 : i n'est pas premier
 * ens[i] = 1 : i est premier
 * ens[0] = ens[1] = 0. (Parce que 0 et 1 ne sont pas premiers.)
 */
void init_crible(int n, ensemble ens)
{
    for (int i = 2; i <= n; i++)
    {
        ens[i] = 1;
    }
    ens[0] = 0;
    ens[1] = 0;
    return;
}

/*
 * Rôle : Trouve les premiers de 2 à n-1.
 * Si i est premier, k*i ne sont pas premiers. (k = 2, 3, …)
 * On l'enlève du ens(crible) ainsi que tous ses multiples.
 */
void trouver_premiers(int n, ensemble ens)
{
    for (int i = 2; i <= n; i++)
    {
        if (ens[i])
        {
            for (int j = 2; j * i <= n; j++)
            {
                ens[j * i] = 0;
            }
        }
    }
    return;
}

/*
 * Rôle : Ecrit sur la sortie standard le table de premires. (colonne est 5)
 */
void print_premiers(int n, ensemble ens)
{
    int col = 0;
    for (int i = 2; i <= n; i++)
    {
        if (ens[i])
        {
            printf("%5d ", i);
            col++;
            col %= 5;
            if (col == 0)
                printf("\n");
        }
    }
    printf("\n");
}

/**************************************************************
 *                 le programme principal                     *
 **************************************************************/

int main(void)
{
    int n;
    ensemble crible;
/*
 * n : le maximal numéro
 * crible : juge si le numéro est premier
 * crible[i] = 0 : i n'est pas premier
 * crible[i] = 1 : i est premier
 */

    scanf("%d", &n);

    init_crible(n - 1, crible);
    trouver_premiers(n - 1, crible);
    print_premiers(n - 1, crible);

    return EXIT_SUCCESS;
}
