/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 12:25:37 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/21 11:14:15 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 0;
	int c;
	int	count_EOL = 0;

	srand(time(NULL));
	if (argc == 1)
	{
		printf("usage: %s nb_of_char\n", argv[0]);
		return (-1);
	}
	printf("0EOL--");
	while (i < atoi(argv[1]))
	{
		c = (char)rand();
		//if ((c >= 32 && c < 127) || c == 10)
		if ((c >= 'a' && c <= 'z') || c == 10)
		{
			if (c == 10)
			{
				count_EOL++;
				printf("--EOL%c%dEOL--", c, count_EOL);
				i = i + 11;
			}
			else
			{
				printf("%c", c);
				i++;
			}
		}
	}
	printf("\n");
	return (0);
}
