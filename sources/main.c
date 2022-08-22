/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:55:29 by gsever            #+#    #+#             */
/*   Updated: 2022/08/22 13:28:03 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file push_swap.c
 * @brief Push_Swap program starting here.
 * 
 * ./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
 * 
 * make && ./push_swap 9 1 8 2 7 && make leaks
 * 
 * make && ./push_swap 9 1 8 2 7 3 6 4 5 && make leaks
 * 
 * make && ./push_swap 9 1 8 2 7 3 6 4 5
 * 
 * make && ./push_swap 9 1 8 2 7 3 6 4 5 && ./checker 9 1 8 2 7 3 6 4 5
 * 
 * ARG=(`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`);
 * 	./push_swap $ARG | ./checker $ARG
 * 
 * ARG=$(jot -r -s " " 100 -20000 2000000); ./push_swap $ARG | ./checker $ARG
 * 
 * arg=(`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`); ./push_swap
 $arg | ./checker $arg
 * @link https://www.doxygen.nl/manual/commands.html
 * @author Görkem SEVER (gsever)
 * @bug Clear.
 */
#include "push_swap.h"

/**
 * @brief push_swap starting here.
 * @fn arg_checker() : Checking agrumans are correct.
 * @fn malloc() : Allocating memory for stack.
 * @fn stack_fill() : Filling stack from argumans.
 * @fn stack_fill_double_quotation() : If args are string filling here.
 * @fn ft_free() : Freeing all memory.
 * @fn ft_error() : Writing str on terminal.
 * @fn indexer() : Indexing minimum value to zero(0).
 * 	Sample -> ./ps 2 8 49 -4 3 9 --> ./ps 1 3 5 0 2 4
 * 	Minimum value -4 -> doing minimum value to 0.
 * @fn is_sorted() : Checking stack's all numbers, if sorted finishing.
 * @fn sort() : Sorting algorithm starting here.
 * @return void
 * @bug Clear.
 */
void	push_swap(t_base *stack, int argc, char **argv)
{
	arg_checker(argc, argv, stack);
	stack->a = malloc(sizeof(int) * stack->start.size);
	stack->b = malloc(sizeof(int) * stack->start.size);
	stack->c = malloc(sizeof(int) * stack->start.size);
	if (argc > 2)
		stack_fill(argc, argv, stack);
	else if (argc == 2)
		stack_fill_double_quotation(ft_split(argv[1], ' '), stack);
	else
		ft_free(stack, true);
	if (!stack->a || !stack->b || !stack->c)
		ft_error("Error\n");
	indexer(stack->start.size, stack);
	is_sorted(stack);
	sort(stack);
	ft_free(stack, true);
}

/**
	@brief PUSH_SWAP

	This program will sort random integers on a stack, with a limited set of
instructions, trying to use the least stack_ops to get a sorted stack.

	The input is given by starting the program with additional arguments.
	Possible Arguments:
	- integers (4 Bytes), positive or negative without any duplicates
	- every number seperated by a single space
	- formatted in a single string or given as multiple arguments

	Sample command to launch the program with 500 random values:
	./push_swap `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`

Steps;
	1. - Check is numbers are sorted.
	2. - Stack a, b, c icin yer actik.
	3. - Fill stack with arguman's numbers.
	4. - 
	5. - 

 */
int	main(int argc, char **argv)
{
	t_base	stack;

	push_swap(&stack, argc, argv);
	exit(0);
}
