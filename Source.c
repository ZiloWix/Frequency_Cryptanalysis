#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

char text[100000], rus[100], cript[100], j, s[100], rusa[] = "оеаинтсрвлкмдпу€ыьгзбчйхжшюцщэфъЄ";;
int y = 0, len;

void key()
{
    int i = 0;
    for (i = 0; cript[i] != '\0'; i++) printf("%c = %c\n", rus[i], cript[i]);
}

void reset()
{
    int i, j;
    for (i = 0; i < 1000; i++) text[i] = '\0';

    for (i = 0; i < 100; i++)
    {
        rus[i] = '\0';
        cript[i] = '\0';
        s[i] = '\0';
    }
}

void zumotsor(int len, int vu)
{
    int i = 0, j = 0, v = 0, w = 0, k, max = 0, ind, q, nword;
    char msimb[1000][100];
    int nsimb[1000];
    if (vu == 5)
    {
        for (i = 0; i < 1000; i++)
        {
            for (j = 0; j < 100; j++) msimb[i][j] = '\0';
        }

        for (i = 0; i < 1000; i++) nsimb[i] = '\0';

        for (i = 0; i < len; i++)
        {
            if (text[i] == ' ')
            {
                if (j > 0) nsimb[v] = j;
                v++;
                w = 0;
                j = 0;
            }
            else
            {
                msimb[v][w] = text[i];
                j++;
                for (q = 0; q < 33; q++)
                {
                    if (msimb[v][w] == rusa[q]) j--;
                }
                w++;
            }
            if ((i == len - 1) && (j > 0)) nsimb[v] = j;
        }

        nword = v + 1;

        for (k = 0; k < nword; k++)
        {
            for (i = k; i < nword; i++)
            {
                if (nsimb[i] >= max)
                {
                    max = nsimb[i];
                    strcpy(s, msimb[i]);
                    ind = i;
                }
            }

            nsimb[ind] = nsimb[k];
            strcpy(msimb[ind], msimb[k]);

            nsimb[k] = max;
            strcpy(msimb[k], s);

            max = 0;
        }

        for (i = nword - 1; i >= 0; i--) puts(msimb[i]);
    }

    if (vu == 3)
    {
        printf("¬ведите букву, которую нужно заменить: ");
        getchar();
        scanf("%c", &cript[y]);
        printf("¬ведите букву, на которую нужно заменить: ");
        getchar();
        scanf("%c", &rus[y]);

        for (i = 0; i < len; i++)
        {
            if (text[i] == cript[y]) text[i] = rus[y];
            printf("%c", text[i]);
        }
        printf("\n");
        y++;
    }

    if (vu == 4)
    {
        if (y == 0) printf("error\n");
        else
        {
            y--;
            for (i = 0; i < len; i++)
            {
                if (text[i] == rus[y]) text[i] = cript[y];
                printf("%c", text[i]);
            }
            printf("\n");
        }
    }
}

void analitika(int len, int vu)
{
    int i = 0, j, z, k = 0, o = 0, nz = 0, sum = 0, krai = 0, kl;
    char rusalf[] = " оеаинтсрвлкмдпу€ыьгзбчйхжшюцщэфъЄ";
    char a, zn, bkrai, bmax, c;
    char simbol[100] = { 0 };
    double n[100] = { 0 }, zkrai, zmax;
    int nn[100] = { 0 }, max = 0, ind = 0;

    for (i = 0; i < len; i++)
    {
        a = text[i];
        kl = a;
        if (((kl < -32) && (kl > -65)) || (kl == 32))
        {
            for (z = 0; z < o; z++)
            {
                if (a == simbol[z]) k++;
            }
            if (k == 0)
            {
                simbol[o] = a;
                o++;
            }
            else k = 0;
        }
    }

    for (i = 0; i < o; i++)
    {
        a = simbol[i];
        for (j = 0; j < len; j++)
        {
            zn = text[j];
            if (a == zn) nz++;
        }
        n[i] = nz;
        nn[i] = nz;
        sum += nz;
        nz = 0;
    }

    for (k = 0; k < o; k++)
    {
        for (i = k; i < o; i++)
        {
            if (nn[i] > max)
            {
                max = nn[i];
                zmax = n[i];
                bmax = simbol[i];
                ind = i;
            }
        }
        krai = nn[k];
        zkrai = n[k];
        bkrai = simbol[k];

        nn[ind] = krai;
        n[ind] = zkrai;
        simbol[ind] = bkrai;

        nn[k] = max;
        n[k] = zmax;
        simbol[k] = bmax;

        max = 0;
    }
    if (vu == 1)
    {
        for (i = 1; i < o; i++)
        {
            printf("'%c' - %.3lf  можно заменить на  '%c'\n", simbol[i], n[i] / sum, rusalf[i]);
        }
    }
    if (vu == 6)
    {
        int zxc = 0;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < o; j++)
            {
                if (text[i] == simbol[j])
                {
                    printf("%c", rusalf[j]);
                    zxc = 1;
                }
            }
            if (zxc == 0) printf("%c", text[i]);
            zxc = 0;
        }
        printf("\n");
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char c;
    int vu;
    reset();
    FILE* input = fopen("TextFile1.txt", "r");
    int i = 0, len = 0, j = 0, v = 0, w = 0, paint;
    for (c = fgetc(input); c != EOF; c = fgetc(input))
    {
        if (c != '?')
        {
            text[i] = c;
            i++;
        }
        else i++;
    }
    fclose(input);
    len = i;

    for (i = 0; i < len; i++)
    {
        if (text[i] == '.')
        {
            while (text[i + 1] == ' ' || text[i + 1] == '\n' || text[i + 1] == '\t' || text[i + 1] == '2' || text[i + 1] == '.')
            {
                i++;
            }
            text[i + 1] = text[i + 1] + 32;
        }
    }

    for (;;)
    {
        printf(" 1 - анализ текста\n");
        printf(" 2 - вывести текст\n");
        printf(" 3 - замена буквы\n");
        printf(" 4 - отменить замену\n");
        printf(" 5 - вывод слов в пор€дке возрастани€ нерасшифрованных букв в слове\n");
        printf(" 6 - автозамена\n");
        printf(" 7 - ключ\n");
        printf(" 8 - завершить работу\n");
        scanf("%d", &vu);


        if (vu == 1 || vu == 6) analitika(len, vu);

        if (vu == 2)
        {
            for (i = 0; i < len; i++)
            {
                printf("%c", text[i]);
            }
            printf("\n");
        }

        if (vu == 3 || vu == 4 || vu == 5) zumotsor(len, vu);

        if (vu == 7) key();

        if (vu == 8) return 0;
    }
}




