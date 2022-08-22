/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:46:39 by gsever            #+#    #+#             */
/*   Updated: 2022/08/22 21:19:39 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mark.c
 * @author Görkem SEVER (gsever)
 * @brief We are indexing number's values start 0 to up.
 * Min, Max, Mid values indexing. 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../includes/push_swap.h"

/**
 * @brief max_value + 1 cikartiyoruz, 0'dan baslatiyoruz.
 * 
 * Sayilarimiz 0'dan baslayarak kucukten buyuge olacak sekilde degerler
 * 	verildikten sonra burada hepsinden max_value + 1 cikartiliyor ki sayilarimiz
 * 	0'dan baslayarak siralansin.
 * 	Yani --> 16 12 10 13 15 14 11 --> 6 2 0 3 5 4 1 olarak siralamis oluyoruz.
 * @param size : Number's size(count).
 * @param base* : Main structure.
 * @return void
 * @bug Not know bugs.
 */
void	remark(int size, t_base *base)
{
	int		i;

	i = 0;
	while (i < size)
	{
		base->a[i] -= (base->start.max + 1);
		++i;
	}
	return ;
}

/**
 * @brief markup()'a sigmadigi icin buradan devam ediyoruz.
 * 
 * Geriye dogru giderek en kucuk sayiyi bulacak, buldugunda;
 * 	bu 'min' sayiyi index yani 'max + 1' yapacak.
 * 
 * 9 1 -2 3 8 4 -14124 0 16
 * 
 * Tersten geliyoruz.	<----- ve buldugumuz en kucuk sayida
 * max + 1'i atayip cikiyoruz.
	0 16 0 -14124
	0 16 0 17 4 8 3 -2
	0 16 0 17 4 8 3 18 1 9
	19 16 19 17 4 8 3 18 1
	19 16 19 17 4 8 3
	19 16 19 17 4
	19 16 19 17 22 8
	19 16 19 17 22 23 21 18 20 9
 * 
 * &i, &index, &tmp, base
 * @param i* : &i -> Number's size(count).
 * @param index* : &index -> 
 * @param tmp* : &tmp
 * @param base* : 
 * @return void
 * @bug Clear.
 */
void	markup_norme(int *i, int *index, int *tmp, t_base *base)
{
	while (*i >= 0)
	{
		if (*tmp == 0)
		{
			if (base->a[*i] == 0)
				base->a[*i] = *index;
		}
		if (base->a[*i] == *tmp)
		{
			base->a[*i] = *index;
			break ;
		}
		(*i)--;
	}
}

/**
 * @brief Recursive onself
 * This int index --> the max value's + 1 amount.
 * Sayilarimizi minimum sayisindan itibaren 0'dan baslayarak
 * 	siraladigi icin burada index > size + base->start.max'ini
 * 	yani -300 -25 235 1 5 8 0 --> 0 1 6 3 4 5 2 yapiyor.
 * 
 * ./push_swap 9 1 -2 3 8 4 0
	base->start.size(7), base->start.max(9) + 1, base->start.min(-2) - 1
	indeximiz --> 10
	9 1 -2 3 8 4 0
	indeximiz --> 11
	9 1 10 3 8 4 0
	indeximiz --> 12
	9 1 10 3 8 4 11
	indeximiz --> 13
	9 12 10 3 8 4 11
	indeximiz --> 14
	9 12 10 13 8 4 11
	indeximiz --> 15
	9 12 10 13 8 14 11
	indeximiz --> 16
	9 12 10 13 15 14 11
	indeximiz --> 17
	16 12 10 13 15 14 11
	index(17), size + base->start.max (16) --- size(7), base->start.max(9)
 * 
 * minimum value = max_value + 1;
 * 
 * @param size : base->start.size -> Number count.
 * @param index : base->start.max + 1 -> Number's max value + 1.
 * @param mini : base->start.min - 1 -> Number's min value - 1.
 * @param base* : base -> Main structure.
 * @fn markup_norme() : Sigmadigi icin buradan devam ediyoruz.
 * @fn markup() : Recursive markup function.
 * @return void
 * @bug Not know bugs.
 */
void	markup(int size, int index, int mini, t_base *base)
{
	int	i;
	int	tmp;

	if (index > size + base->start.max)
		return ;
	tmp = base->start.max;
	i = 0;
	while (i < size)
	{
		if (base->a[i] > mini && base->a[i] <= tmp)
			tmp = base->a[i];
		i++;
	}
	markup_norme(&i, &index, &tmp, base);
	markup(size, ++index, tmp, base);
}

/**
 * @brief Indexer = Hafizaya alma demek.
 * We are indexing ---> marking --> remarking
 * @param size : stack->start.size -> 
 * @param base* : stack -> Main structure.
 * @fn is_repeated : We are controling repeaded numbers. If found -> "Error"
 * @fn find_min : We are assigning min value to base->start.min.
 * @fn find_max : We are assigning max value to base->start.max.
 * @fn markup : Minimumdan baslayarak uzerine max + 1 deger ekliyoruz.
 * 	./push_swap 9 1 -2 3 8 4 0 --> 16 12 10 13 15 14 11
 * @fn remark : Sonra hepsinden max_value + 1 cikariyoruz, boylelikle;
 * 	16 12 10 13 15 14 11 --> 6 2 0 3 5 4 1 olarak siralamis oluyoruz.
 * @return void
 * @bug Not know bugs.
 */
void	indexer(int size, t_base *base)
{
	is_repeated(base);
	base->start.min = find_min(size, base);
	base->start.max = find_max(size, base);
	markup(base->start.size, base->start.max + 1, base->start.min - 1, base);
	remark(size, base);
	base->max = base->start.size - 1;
	base->c_a = base->start.size;
	base->c_b = 0;
	base->mid = (base->start.size + 1) / 2;
}
