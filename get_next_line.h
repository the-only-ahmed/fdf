/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 10:19:54 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/09 01:44:27 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <libft.h>

# define BUFF_SIZE 10000

typedef struct	s_ahmed
{
	int				fd;
	char			*str;
	struct s_ahmed	*next;
}	t_ahmed;

int			get_next_line(int fd, char **line);
t_ahmed		*files(int fd, t_ahmed *eng);
int			buffering(int ret, t_ahmed *tmp, char **line, char *buff);
int			fn_buffer(t_ahmed *tmp, char **line);
void		supression(t_ahmed *del);

#endif /* GET_NEXT_LINE_H  */
