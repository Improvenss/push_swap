/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:09:00 by gsever            #+#    #+#             */
/*   Updated: 2022/08/21 23:30:08 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file check_error.c
 * @author Görkem SEVER (gsever)
 * @brief Controling area here.
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/push_swap.h"

/**
 * @brief Check if a stack's numbers is sorted.
 * @fn ft_free() : Free all stacks.
 * @return void
 * @bug Not know bugs.
 */
void	is_sorted(t_base *base)
{
	int		i;

	i = 0;
	while (i + 1 < base->start.size)
	{
		if (base->a[i] < base->a[i + 1])
			i++;
		else
			return ;
	}
	ft_free(base, true);
}

/**
 * @brief Check if a stack's numbers is repeated.
 * @param base* : 
 * @fn ft_error() : If have problem, writing string and exit program.
 * @return void
 * @bug Clear.
 */
void	is_repeated(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < base->start.size)
	{
		j = i + 1;
		while (j < base->start.size)
		{
			if (base->a[i] == base->a[j])
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}

/**
 * @brief It's just writing string and start exit(1);
 * @fn ft_putstr_fd() :  Writing string on shell.
 * @fn exit() :  Exiting program.
 * @return 1
 * @bug Clear.
 */
int	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit (1);
	return (1);
}

/**
 * @brief Just check if there are only numbers.
 * @param ac : 
 * @param av** : 
 * @fn ft_error() : If have problem, writing "Error" and exit program.
 * @fn is_digit() : Scanning string, all argumans are digit.
 * @return void
 * @bug Clear.
 */
void	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			ft_error("Error\n");
		while (av[i][j])
		{
			if (av[i][j] == '-')
			{
				if (!(av[i][j + 1] >= '1' && av[i][j + 1] <= '9'))
					ft_error("Error\n");
				j++;
			}
			if (ft_isdigit(av[i][j]))
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}

/**
 * @brief We are checking if the double quotation's output is correct or not.
 * base->start.size = calc_number_count_in_string();
 * @param av* : 
 * @param base* : 
 * @fn calc_number_count_in_string() : Counts numbers seperated by spaces 
 * in a string.
 * @fn is_digit_wsm() : Scanning string, all argumans are digit.
 * @fn ft_error() : If have problem, writing "Error" and exit program.
 * @return void
 * @bug Not know bugs.
 */
void	check_num_double_quotation(char *av, t_base *base)
{
	int	i;

	i = 0;
	base->start.size = (int)calc_number_count_in_string(av, ' ');
	while (av[i])
	{
		if (ft_isdigit_wsm(av[i]))
			ft_error("Error\n");
		if (av[i] == '-')
		{
			if (!(av[i + 1] >= '0' && av[i + 1] <= '9'))
				ft_error("Error\n");
		}
		i++;
	}
}
