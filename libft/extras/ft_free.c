/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tryfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:21:52 by thantoni          #+#    #+#             */
/*   Updated: 2025/12/15 09:37:32 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

int	ft_free(void *ptr)
{
	if (ptr != NULL)
		return (free(ptr), TRUE);
	return (FALSE);
}