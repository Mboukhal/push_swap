/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:21:49 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/13 13:22:07 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	ft_revers(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (len > i)
	{
		ft_swap (&s[i], &s[len]);
		i++;
		len--;
	}
}

static int	int_count(long int r)
{	
	int	i;

	i = 0;
	if (r < 0)
	{
		r *= -1;
		i++;
	}
	while (r > 9)
	{
		r /= 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long int	r;
	int			i;
	char		*str;

	r = n;
	i = int_count (r);
	str = malloc((i + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	i = 0;
	if (n < 0)
		r *= -1;
	while (r > 9)
	{
		str[i] = (r % 10) + 48;
		r /= 10;
		i++;
	}
	str[i++] = r + 48;
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_revers(str);
	return (str);
}
