/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 10:53:59 by jopaning          #+#    #+#             */
/*   Updated: 2019/02/23 13:09:23 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fct.h"
#include "eval_expr.h"

int		ft_detect_number(char **strnb)
{
	int number;
	int i;
	int j;

	i = 0;
	j = 1;
	while (strnb[j][i] == ' ')
		i++;
	if (strnb[j][i] == '(')
	{
		i++;
		number = ft_detect_sum(strnb);
		if (strnb[j][i] == ')')
			i++;
		return (number);
	}
	return (ft_atoi(strnb));
}

int		ft_detect_operators(char **strnb)
{
	int		i;
	int		j;
	int		number;
	int		number_2;
	char		operator;

	i = 0;
	j = 1;
	number = ft_detect_number(strnb);
	while(strnb[j][i])
	{
		while (strnb[j][i] == ' ')
			i++;
		operator = strnb[j][i];
		if (operator != '/' && operator != '*' && operator != '%')
			return (number);
		i++;
		number_2 = ft_detect_number(strnb);
		if (operator == '/')
			number = number / number_2;
		else if (operator == '*')
			number = number * number_2;
		else
			number = number % number_2;
	}
	return (number);
}

int		ft_detect_sum(char **strnb)
{
	int		i;
	int		j;
	int		number;
	int		number_2;
	char		operator;

	i = 0;
	j = 1;
	number = ft_detect_operators(strnb);
	while (strnb[i])
	{
		while (strnb[j][i] == ' ')
			i++;
		operator = strnb[j][i];
		if (operator != '+' && operator != '-')
			return (number);
		i++;
		number_2 = ft_detect_operators(strnb);
		if (operator == '+')
			number = number + number_2;
		else
			number = number - number_2;
	}
	return (number);
}

int		eval_expr(char *expr)
{
	return (ft_detect_sum(&expr));
}
