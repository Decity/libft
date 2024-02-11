/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:33:48 by elie              #+#    #+#             */
/*   Updated: 2024/02/11 18:33:50 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_array( size_t i, char **array)
{
	while (i--)
	{
		free(array[i]);
		array[i] = NULL;
		}
	free(array);
	array = NULL;
}
