#include "minirt.h"

int count_dpointer(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int string_compare(char *str, char *str1)
{
	if (!ft_strncmp(str, str1, ft_strlen(str))
		&& !ft_strncmp(str, str1, ft_strlen(str1)))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
