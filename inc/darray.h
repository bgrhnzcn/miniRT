/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:34:51 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 19:32:36 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARRAY_H
# define DARRAY_H

# include "libft.h"

typedef struct s_darray
{
	void	*data;
	int		type_size;
	int		capacity;
	int		size;
}	t_darray;

t_darray	*init_darray(int capacity, int type_size);
int			push_darray(t_darray *darray, void *data);
void		free_darray(t_darray *darray);

#endif
