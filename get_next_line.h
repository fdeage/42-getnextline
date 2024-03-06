/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 18:00:23 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/05 13:15:00 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE		1024
# define MALLOC_SIZE	4096
# define MAX_FD			512

typedef struct s_buf	t_buf;

struct					s_buf
{
	char				is_init;
	size_t				rem_len;
	size_t				buf_len;
	size_t				malloc_size;
	size_t				search_index;
	char				*rem;
	char				buf[BUF_SIZE + 1];
};

int						get_next_line(int const fd, char **line);

#endif
