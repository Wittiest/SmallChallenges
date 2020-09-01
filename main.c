#include <stdlib.h>
#include <stdio.h>

/*
**	The program will print out the prime factors separated by *s. It will also
**	end with a star no matter what because I did not add pointless lines to fix
**	a small issue since this was a learning exercise.
**	____________________________________________________________________________
**	I'm refraining from using scanf still, so I'll be creating a situation where
**	the user must enter one number while executing my program.
**	____________________________________________________________________________
*/

int		main(int argc, char **argv)
{
	int nbr;
	int i;
	int j;
	int boolean;

	if (argc != 2)
		return (0);
	nbr = atoi(argv[1]);
	i = 2;
	/* While loop until i is equal to nbr */
	while (nbr >= i)
	{
		/* If i can be multiplied by something to equal nbr */
		if (nbr % i == 0)
		{
			j = 2;
			boolean = 1;
			/* Until j is bigger than or equal to half of i */
			while ((i / 2) >= j)
            {
            	/* Spot where i % j is 0 = the current i is not prime */
				if (i % j == 0)
				{
					boolean = 0;
					break ;
				}
            	j++;
            }
            if (boolean)
                printf("%d*", i);
		}
		i++;
	}
	return (0);
}
