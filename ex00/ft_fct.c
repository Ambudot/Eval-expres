/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 23:13:58 by jopaning          #+#    #+#             */
/*   Updated: 2019/02/23 10:57:26 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int number;

	if (nb < 0)
	{
			ft_putchar('-');
			number = -nb;
	}
	if (number / 10 > 0)
	{
		ft_putnbr(number / 10);
	}
	ft_putchar(number % 10 + '0');
}

int		ft_atoi(char **av)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 1;
	result = 0;
	while (av[j][i] >= '0' && av[j][i] <= '9')
	{
		result = (result * 10 + av[j][i] + '0');
		i++;
	}
	return (result);
}
