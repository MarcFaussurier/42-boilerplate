/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush03.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmanojlo <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/03 13:04:06 by mmanojlo     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/03 14:06:51 by mmanojlo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

enum
{
	TOP_LEFT = 'A',
	TOP_RIGHT = 'C',
	BOTTOM_LEFT = 'A',
	BOTTOM_RIGHT = 'C',
	VERTICAL = 'B',
	HORIZONTAL = 'B',
	BLANK = ' '
};

void	display(int x, int y, int max_x, int max_y)
{
	if (y == 0)
	{
		if (x == 0)
			ft_putchar(TOP_LEFT);
		else if (x == max_x)
			ft_putchar(TOP_RIGHT);
		else
			ft_putchar(HORIZONTAL);
	}
	else if (y == max_y)
	{
		if (x == 0)
			ft_putchar(BOTTOM_LEFT);
		else if (x == max_x)
			ft_putchar(BOTTOM_RIGHT);
		else
			ft_putchar(HORIZONTAL);
	}
	else if (x == 0 || x == max_x)
		ft_putchar(VERTICAL);
	else
		ft_putchar(BLANK);
}

void	rush(int x, int y)
{
	int y_cp;
	int x_cp;
	int max_x;
	int max_y;

	y_cp = 0;
	x_cp = 0;
	max_x = x - 1;
	max_y = y - 1;
	while (y_cp < y)
	{
		x_cp = 0;
		while (x_cp < x)
		{
			display(x_cp, y_cp, max_x, max_y);
			x_cp += 1;
		}
		ft_putchar('\n');
		y_cp += 1;
	}
}
