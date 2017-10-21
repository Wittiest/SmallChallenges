#include <unistd.h>
#include <stdio.h>

/*
    Completed this on my own at first, then referenced online material to 
    improve it. Works from 0 to 3999 because ASCII doesn't have the other
    fancy roman numerals
*/

char rom[20];
int pos = 0;

void    pre(char rom1, char rom2)
{
    rom[pos++] = rom1;
    rom[pos++] = rom2;
}

void    post(char c, int n)
{
    int j;

    j = 0;
    while (j++ < n)
        rom[pos++] = c;
}

int     digitize(int nbr, int range, int range2, char post, char pre1, char pre2)
{
    if (nbr < range2)
    {
        post(post, nbr / range);
        nbr -= (nbr / range) * range;
    }
    else
    {
        pre(pre1, pre2);
        nbr -= range2;
    }
    return (nbr);
}

void    romanize(int nbr)
{
    int j;

    while (nbr != 0)
    {
        if (nbr >= 1000)
        {
            post('M', nbr / 1000);
            nbr -= (nbr / 1000) * 1000;
        }
        else if (nbr >= 500)
            nbr = digitize(nbr, 500, 900, 'D', 'C', 'M');
        else if (nbr >= 100)
            nbr = digitize(nbr, 100, 400, 'C', 'L', 'D');
        else if (nbr >= 50 )
            nbr = digitize(nbr, 50, 90, 'L', 'X', 'C');
        else if (nbr >= 10)
            nbr = digitize(nbr, 10, 40, 'X', 'X', 'L');
        else if (nbr >= 5)
            nbr = digitize(nbr, 5, 9, 'V', 'I', 'X');
        else if (nbr >= 1)
            nbr = digitize(nbr, 1, 4, 'I', 'I', 'V');
    }
    for(j = 0; j < pos; j++)
        write(1, &rom[j], 1);
    write(1, "\n", 1);
}

int     main(int argc, char **argv)
{
    int j;
    int nbr;

    j = 1;
    while (j < argc)
    {
        nbr = atoi(argv[j++]);
        if (nbr > 0 && nbr < 4000)
            romanize(nbr);
    }
    return 0;
}