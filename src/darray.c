/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:39:23 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 16:50:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"

t_darray	*init_darray(size_t capacity, size_t type_size)
{
	t_darray	*darray;

	darray = (t_darray *)malloc(sizeof(t_darray));
	if (!darray)
		return (NULL);
	darray->data = malloc(capacity * type_size);
	if (!darray->data)
		return (free(darray), NULL);
	darray->type_size = type_size;
	darray->capacity = capacity;
	darray->size = 0;
	return (darray);
}

int	push_darray(t_darray *darray, void *data, size_t type_size)
{
	void	*tmp;

	if (darray->size == darray->capacity)
	{
		tmp = darray->data;
		darray->data = malloc(darray->capacity * 2 * type_size);
		if (!darray->data)
			return (free(tmp), 1);
		ft_memcpy(darray->data, tmp, darray->size * type_size);
	}
	ft_memcpy(darray->data + (darray->size * type_size), data, type_size);
	darray->size++;
	return (0);
}

void	free_darray(t_darray *darray)
{
	free(darray->data);
	free(darray);
}
