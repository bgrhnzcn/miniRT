/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:34:51 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 16:50:01 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_darray
{
	void	*data;
	size_t	type_size;
	size_t	capacity;
	size_t	size;
}	t_darray;

t_darray	*init_darray(size_t capacity, size_t type_size);
int			push_darray(t_darray *darray, void *data, size_t type_size);
void		free_darray(t_darray *darray);
