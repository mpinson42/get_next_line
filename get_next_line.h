/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:55:50 by mpinson           #+#    #+#             */
/*   Updated: 2017/03/12 18:55:55 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 16

typedef struct		s_env
{
	int				fd;
	char			*str;
	int				bol;
	int				bol2;
	struct s_env	*next;
	struct s_env	*presed;
}					t_env;

int					get_next_line(const int fd, char **line);

#endif
