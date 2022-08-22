/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:23:41 by gsever            #+#    #+#             */
/*   Updated: 2022/08/22 13:28:27 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file sorting.c
 * @author Görkem SEVER (gsever)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/push_swap.h"

/**
 * @brief 
 * @param base* : 
 * @fn rra() : 
 * @fn ra() : 
 * @return void
 * @bug Not know bugs.
 */
void	final_sort(t_base *base)
{
	int	i;

	i = 1;
	while (base->a[i] != 0)
		i++;
	while (base->a[0] != 0)
	{
		if (i > base->c_a / 2)
			rra(1, base);
		else
			ra(1, base);
	}
}

/**
 * @brief Sorting steps and algorithms starting here.
 * @param base* : 
 * @fn sort_small() : If your numbers count < 10; running.
 * @fn keep_me() : 
 * @fn push_to_b() : Pushing
 * @fn score_init_max() : 
 * @fn compute() : 
 * @fn perform() : 
 * @fn final_sort() : 
 * @fn ft_free() : 
 * @return void
 * @bug Clear.
 */
void	sort(t_base *base)
{
	int	i;

	i = 0;
	if (base->c_a < 10)
		sort_small(base);
	else
	{
		keep_me(base);
		push_to_b(base);
		while (i < base->mid / 2)
		{
			score_init_max(base);
			compute(base->mid, base);
			perform(base);
			i++;
		}
		while (base->c_b)
		{
			score_init_max(base);
			compute(base->max, base);
			perform(base);
		}
		final_sort(base);
	}
	ft_free(base, true);
}
