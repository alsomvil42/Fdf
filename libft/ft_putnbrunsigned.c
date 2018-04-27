/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:02:20 by alsomvil          #+#    #+#             */
/*   Updated: 2018/04/24 04:33:58 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

void	ft_putnbrunsigned(unsigned long long nb, t_save *save)
{
	unsigned long long nbr;

	nbr = (nb % 10) + '0';
	if (nb >= 10)
		ft_putnbr_return(nb / 10, save);
	ft_putchar_return(nbr, save);
}
