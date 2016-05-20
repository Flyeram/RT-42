/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblondea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 17:49:52 by jblondea          #+#    #+#             */
/*   Updated: 2015/12/03 15:17:16 by jblondea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int sqrt;

	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	sqrt = nb / 2;
	if (sqrt > 46340)
		sqrt = 46340;
	while (nb != sqrt * sqrt && sqrt > 0)
	{
		if (sqrt * sqrt < nb)
			return (sqrt + 1);
		sqrt--;
	}
	return (sqrt);
}
