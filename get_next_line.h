/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:34:14 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/23 14:19:21 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		42
# endif /* BUFFER_SIZE */

# define _EOF				-1

char			*get_next_line(int fd);
char			*ft_allocat_line(char *save);
char			*ft_save(char *save);
char			*ft_read_buff(int fd, char *save);
size_t			ft_strlen(char *str);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);

#endif /* GET_NEXT_LINE_H */
