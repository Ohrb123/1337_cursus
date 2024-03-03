
#include "fractol.h"

int check_decimal(char *str, int i)
{
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '.')
        {
            while (str[i + 2] >= '0' && str[i + 2] <= '9')
            {
                i++;
                if (!str[i + 2])
                    return (1);
                else if (str[i + 2] <= '0' && str[i + 2] <= '9')
                    return (0);
            }
            return (0);
        }
        else if (str[i] >= '0' && str[i] <= '9' && !str[i + 1])
            return (1);
        i++;
    }
    return (0);
}

int ft_parse(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
    {
        if (str[i] == '.' && check_decimal(str, i))
            return (1);
        i++;
    }
    return (0);
}