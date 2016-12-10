/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:00:42 by mpinson           #+#    #+#             */
/*   Updated: 2016/12/06 13:09:22 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 9999

typedef	struct		s_fd
{
	int				fd;
	char			*lne;
	struct s_fd		*next;
	struct s_fd		*srt;
}					t_fd;

int					get_next_line(int const fd, char **line);

#endif
