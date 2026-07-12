/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrousa <aalrousa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:53:09 by aalrousa          #+#    #+#             */
/*   Updated: 2026/02/10 13:53:13 by aalrousa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_bench(char **argv)
{
	if (strncmp(argv[1], "--bench", 7) == 0)
		return (1);
	if (argv[2] && strncmp(argv[2], "--bench", 7) == 0)
		return (1);
	return (0);
}

static void	bench_line_4(t_bench bench)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(bench.sa, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("sb: ", 2);
	ft_putnbr_fd(bench.sb, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("ss: ", 2);
	ft_putnbr_fd(bench.ss, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("pa: ", 2);
	ft_putnbr_fd(bench.pa, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("pb: ", 2);
	ft_putnbr_fd(bench.pb, 2);
	ft_putstr_fd(" ", 2);
}

static void	bench_line_5(t_bench bench)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(bench.ra, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("rb: ", 2);
	ft_putnbr_fd(bench.rb, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("rr: ", 2);
	ft_putnbr_fd(bench.rr, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("rra: ", 2);
	ft_putnbr_fd(bench.rra, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("rrb: ", 2);
	ft_putnbr_fd(bench.rrb, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd("rrr: ", 2);
	ft_putnbr_fd(bench.rrr, 2);
}

void	print_bench(t_bench bench)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	putnbr_float_fd(bench.disorder, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench.algo, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench.total, 2);
	ft_putstr_fd("\n", 2);
	bench_line_4(bench);
	ft_putstr_fd("\n", 2);
	bench_line_5(bench);
	write(2, "\n", 1);
}

void	putnbr_float_fd(float num, int fd)
{
	int	int_num;
	int	dec_num;

	num = num * 100;
	int_num = (int)num;
	dec_num = (int)((num - int_num) * 100);
	ft_putnbr_fd(int_num, fd);
	write(fd, ".", 1);
	if (dec_num < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(dec_num, fd);
}
