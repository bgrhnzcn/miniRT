/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:39:23 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 18:19:10 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"

t_darray	*init_darray(int capacity, int type_size)
{
	t_darray	*darray;

	darray = (t_darray *)malloc(sizeof(t_darray));
	if (!darray)
		return (NULL);
	darray->data = ft_calloc(capacity, type_size);
	if (!darray->data)
		return (free(darray), NULL);
	darray->type_size = type_size;
	darray->capacity = capacity;
	darray->size = 0;
	return (darray);
}

int	push_darray(t_darray *darray, void *data)
{
	void	*tmp;

	if (darray->size == darray->capacity)
	{
		tmp = darray->data;
		darray->capacity = 2 * darray->capacity;
		darray->data = malloc(darray->capacity * darray->type_size);
		if (!darray->data)
			return (free(tmp), 1);
		ft_memcpy(darray->data, tmp, darray->size * darray->type_size);
	}
	ft_memcpy(darray->data + (darray->size * darray->type_size),
		data, darray->type_size);
	darray->size++;
	return (0);
}

void	free_darray(t_darray *darray)
{
	free(darray->data);
	free(darray);
}

void		*get_darray(t_darray *darray, unsigned int index)
{
	if ((int)index >= darray->size)
		return (NULL);
	return (darray->data + (darray->type_size * index));
}
