/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:32:55 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/23 16:44:32 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

				/* main get_next_line {1} */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_buff(fd, save);
	if (!save)
		return (NULL);
	line = ft_allocat_line(save);
	save = ft_save(save);
	return (line);
}

					/* allocating return line {2} */
char	*ft_allocat_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i - 1] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

					/* save the new buffer after last (\n) {3} */
char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

					/* read buffer from and add 
						to last saved to (\n) {4} */
char	*ft_read_buff(int fd, char *save)
{
	char	*buffer;
	int		status;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	status = 1;
	while (!ft_strchr(save, '\n') && status != 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status == _EOF || status == 1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[status] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}
