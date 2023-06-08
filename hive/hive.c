/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsshih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:46:10 by hsshih            #+#    #+#             */
/*   Updated: 2019/07/18 22:13:25 by hsshih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_width_counter(int size)
{
	if (size == 1)
		return (7);
	else
		return ((size / 2 + 1) * 2 + ft_width_counter(size - 1) +
				(size + 2) * 2);
}

void	ft_print_fill(int type, int nb)
{
	char	print_type;

	if (type == 1)
		print_type = ' ';
	else if (type == 2)
		print_type = '*';
	else if (type == 3)
		print_type = '|';
	while (nb > 0)
	{
		ft_putchar(print_type);
		nb--;
	}
}

void	ft_print_line(int shift, int fill)
{
	ft_print_fill(1, shift);
	ft_putchar(47);
	ft_print_fill(2, fill);
	ft_putchar(92);
	ft_putchar('\n');
}

void	ft_sastantua_recursive(int shift, int size)
{
	int	count_one;

	count_one = 1;
	if (size == 1)
		while (count_one <= size + 2)
		{
			ft_print_line(shift / 2 - count_one, (count_one - 1) * 2 + 1);
			count_one++;
		}
	else
	{
		ft_sastantua_recursive(shift, size - 1);
		while (count_one <= size + 2)
		{
			ft_print_line(shift / 2 - count_one - ft_width_counter(size) /
					2 + size + 2, (ft_width_counter(size) / 2 + count_one
						- size - 3) * 2 + 1);
			count_one++;
		}
	}
}

void	sastantua(int size)
{
	int	count_one;
	int	tree_width;
	int	i;

	count_one = 1;
	i = 0;
	ft_sastantua_recursive(ft_width_counter(size), size - 1);
	if (size > 0)
	{
		tree_width = size;
		if (size % 2 == 0)
			tree_width--;
		while (count_one <= size + 2)
		{
			if (count_one + tree_width > size + 2)
			{
				ft_print_fill(1, size + 2 - count_one);
				ft_putchar(47);
				ft_print_fill(2, (ft_width_counter(size) / 2 + count_one -
							size - 3) - tree_width / 2);
				ft_print_fill(3, tree_width - 2);
				if (i == tree_width / 2)
					ft_putchar('$');
				else
					ft_putchar('|');
				ft_putchar('|');
				ft_print_fill(2, (ft_width_counter(size) / 2 + count_one -
							size - 3) - tree_width / 2);
				ft_putchar(92);
				ft_putchar('\n');
				i++;
			}
			else
				ft_print_line(size + 2 - count_one, (ft_width_counter(size) /
							2 + count_one - size - 3) * 2 + 1);
			count_one++;
		}
	}
}