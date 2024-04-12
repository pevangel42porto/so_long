/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:45:00 by pevangel          #+#    #+#             */
/*   Updated: 2023/10/19 14:53:58 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nitoa(unsigned int a, int len)
{
	char	*nn;

	nn = ft_calloc(len + 1, sizeof(char));
	if (!nn)
		return (NULL);
	nn[len] = '\0';
	while (len > 0)
	{
		len--;
		nn[len] = a % 10 + '0';
		a = a / 10;
	}
	nn[0] = '-';
	return (nn);
}

int	ft_countnum(int a)
{
	int				i;
	unsigned int	j;

	j = a;
	i = 0;
	if (a < 0)
	{
		i++;
		j = -a;
	}
	if (a == 0)
		return (1);
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*o;
	int				nlen;
	unsigned int	nbr;

	nbr = n;
	nlen = ft_countnum(n);
	if (n < 0)
	{
		nbr = -n;
		o = ft_nitoa(nbr, nlen);
		return (o);
	}
	o = ft_calloc(nlen + 1, sizeof(char));
	if (!o)
		return (NULL);
	o[nlen] = '\0';
	while (nlen > 0)
	{
		o[nlen-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (o);
}
