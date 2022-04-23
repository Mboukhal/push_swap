/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:36:02 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/23 14:29:56 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

					/* length of the string {1} */
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

				/* join a s1 and s2 into a string and  {2}
					return new altocated string
					i[0] = (s1 to str)
					i[1] = (s2 to str)
					i[2] = (len s1)
					i[3] = (len s2)*/
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i[4];
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i[2] = ft_strlen(s1);
	i[3] = ft_strlen(s2);
	str = malloc((i[2] + i[3] + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i[0] = -1;
	i[1] = 0;
	if (s1)
		while (s1[++i[0]])
			str[i[0]] = s1[i[0]];
	while (s2[i[1]])
		str[i[0]++] = s2[i[1]++];
	str[i[2] + i[3]] = '\0';
	free(s1);
	return (str);
}

				/* return first char founed equil to c {3} */
char	*ft_strchr(char *s, int c)
{
	size_t		i;

	i = 0;
	if (s)
		while (s[i++])
			if (s[i] == (char)c)
				return ((char *)&s[i]);
	return (NULL);
}
