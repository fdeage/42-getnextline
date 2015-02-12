/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 21:20:58 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/12 15:20:34 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"


static void find_leaks(void)
{
	system("leaks `ps | grep ./$1 | head -n 1 | cut -d' ' -f1`");
	return ;
}

static void ft_put_string_nbr(int nbr, char *dest)
{
    if (nbr >= 0)
    {
        if (nbr < 10)
        {
            while (*dest)
                ++dest;
            *dest = (char)nbr + '0';
        }
        else
        {
            ft_put_string_nbr(nbr / 10, dest);
            ft_put_string_nbr(nbr % 10, dest);
        }
    }
    else
    {
        dest[0] = '-';
        ft_put_string_nbr(-nbr, dest);
    }
}

char        *ft_itoatab(int nbr, char *tab)
{
    bzero(tab, 12);
    if (nbr == -2147483648)
    {
        ft_put_string_nbr(nbr / 10, tab);
        (tab)[10] = '8';
    }
    else
        ft_put_string_nbr(nbr, tab);
    return (tab);
}

int     main(int ac, char **av)
{
	int			fds[40];
	int			ret[41];
	int			i;
	int			all_empty;
	char		color_string[100] = {0};
	char		tab[15] = {0};
	char		*line;

	if (ac < 2)
	{
		printf("Please type at least 1 filename as params: %s file1 [file2] ... [leaks]\n", av[0]);
		return (EXIT_FAILURE);
	}
	else if (ac >= 40)
	{
		printf("Error: 40 parameters max.\n");
		return (EXIT_FAILURE);
	}
	else
	{

		/*
		** reads all the files sequentially
		*/

		i = 1;
		while (i < ac)
		{
			if (strcmp(av[i], "stdin") == 0)
			{
				ret[i] = 1;
				fds[i] = 0;
				++i;
				continue ;
			}
			else if (i == ac - 1 && strcmp(av[i], "leaks") == 0)
			{
				ret[i] = 2;
				++i;
				continue ;
			}

			fds[i] = open(av[i], O_RDONLY);
			if (fds[i] == -1)
			{
				printf("no file matching %s.\n", av[i]);
				ret[i] = -1;
				++i;
				continue ;
			}
			else if (fds[i] != 0)
			{
				line = (char *)malloc(50000);
				ret[40] = (int)read(fds[i], line, 50000);
				if (line[ret[40] -1] == '\n')
				{
					line[ret[40] - 1] = ' ';
					line[ret[40] + 0] = '+';
					line[ret[40] + 1] = '\\';
					line[ret[40] + 2] = 'n';
					line[ret[40] + 3] = '\0';
				}

				strcpy(color_string, "MAIN:  test file= %s\n.\033[");
				strcat(color_string, ft_itoatab(31 + i % 7, tab));
				strcat(color_string, "m%s\033[0m.\nnb_car(file) = %d\n\n");

				printf(color_string, av[i], line, (int)strlen(line));
				lseek(fds[i], 0, SEEK_SET);
				(void)memset(line, '\0', strlen(line));
				free(line);
				ret[i] = 1;
				++i;
			}
		}
	}

	/*
	** reads one line of each file sequentially
	*/

	while (1)
	{
		i = 1;
		all_empty = 1;
		while (i < ac)
		{
			if (ret[i] == 1)
			{
				all_empty = 0;
				ret[i] = get_next_line(fds[i], &line);

				strcpy(color_string, "MAIN%d:  ret=\033[33m%d\033[0m, line=.\033[");
                strcat(color_string, ft_itoatab(31 + i % 7, tab));
				strcat(color_string, "m%s\033[0m. len=%d\n");

				printf(color_string, i, ret[i], line, (int)strlen(line));
				if (ret[i] > 0)
					free(line);
				line = NULL;
			}
			++i;
		}
		if (all_empty == 1)
			break ;
	}

	/*
	** if "leaks" is typed, check the memory leaks with /usr/bin/leaks
	** using the "system()" function
	*/

	if (!strcmp(av[ac - 1], "leaks"))
		find_leaks();

	return (EXIT_SUCCESS);
}
