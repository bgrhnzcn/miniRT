#include "minirt.h"

int	control_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '-' && str[i] != '+' && str[i] != '.'
		&& !(str[i] >= '0' && str[i] <= '9'))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

float ft_atof(char *str)
{
	float	res;
	int		i;

	res = 0;
	res = ft_atoi(str);
	i = -1;
	while (str[++i] && str[i] != '.')
		;
	if (str[i] == '\0')
		i = 0;
	else
		i += 1;
	res += (ft_atoi(str + i) / pow(10, ft_strlen(str + i)));
	return (res);
}

void	free_dpointer(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free (str);
}

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
