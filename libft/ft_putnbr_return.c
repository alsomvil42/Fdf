/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:33:53 by alsomvil          #+#    #+#             */
/*   Updated: 2018/04/24 04:34:56 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "../ft_printf.h"

void	ft_putnbr_return(long long nb, t_save *save)
{
	long long		nbr;

	if (nb == -2147483648)
	{
		ft_putnbr_return(-2, save);
		ft_putnbr_return(147483648, save);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar_return('-', save);
		nbr = (nb % 10) + '0';
		if (nb >= 10)
			ft_putnbr_return(nb / 10, save);
		ft_putchar_return(nbr, save);
		return ;
	}
	if (nb >= 0)
	{
		nbr = (nb % 10) + '0';
		if (nb >= 10)
			ft_putnbr_return(nb / 10, save);
		ft_putchar_return(nbr, save);
	}
}

void	ft_putnbrunsigned(unsigned long long nb, t_save *save)
{
	unsigned long long	nbr;

	nbr = (nb % 10) + '0';
	if (nb >= 10)
		ft_putnbr_return(nb / 10, save);
	ft_putchar_return(nbr, save);
}
