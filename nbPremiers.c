/* Ce module définit les fonctions de Erastosthène.
 * Ce programme pour touver les premiers par une méthode de Erastosthène.
 * 
 * @author : KANG Jiale "kanngjle@gmail.com" et ZHANG Liyun ""
 * Creation @date : 03-Dec-2020 10:21
 * Last file update : 03-Dec-2020 11:31
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 10000 + 5
// MAXNUM : Ce programme peut trouver les numéro de 1 à MAXNUM.
// MAXNUM : 程序能找到的最大范围是1到MAXNUM。

/*
 * Rôle : Initialise le ensemble.
 * ens[i] = 0 : i n'est pas premier
 * ens[i] = 1 : i est premier
 * ens[0] = ens[1] = 0. (Parce que 0 et 1 ne sont pas premiers.)
 *
 * 作用 : 初始化一个集合。
 * ens[i] = 0 : 数字i不再素数集合中，即数字i不是素数。
 * ens[i] = 1 : 数字i在素数集合中，即数字i是素数。
 * ens[0] = ens[1] = 0.(因为0和1均不是素数。)
 */
void init_crible(int n, int ens[MAXNUM])
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
 * Rôle : Trouve les premiers de 2 à n - 1.
 * Si i est premier, k*i ne sont pas premiers. (k = 2, 3, …)
 * On l'enlève du ens(crible) ainsi que tous ses multiples.
 *
 * 作用 : 在2到(n - 1)内找到素数。
 * 如果i是素数，k*i便不是素数。
 * 从集合中删除i的倍数。
 */
void trouver_premiers(int n, int ens[MAXNUM])
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
 * 作用 : 输出素数。(每行输出5个素数。)
 */
void print_premiers(int n, int ens[MAXNUM])
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
    int crible[MAXNUM];
/*
 * n : le maximal numéro
 * crible : juge si le numéro est premier
 * crible[i] = 0 : i n'est pas premier
 * crible[i] = 1 : i est premier
 *
 * n : 最大数。
 * crible : 表示数字是否是素数的集合。
 * crible[i] = 0 : i不是素数。
 * crible[i] = 1 : i是素数。
 */

    scanf("%d", &n);

    init_crible(n - 1, crible);
    trouver_premiers(n - 1, crible);
    print_premiers(n - 1, crible);

    return EXIT_SUCCESS;
}
