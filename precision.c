#include "ft_printf.h"

char    *pre_str(char *str, t_flag flags)
{
    char    *out;
    int     i;

    i = 0;
    if (flags.pre == -1)
        return (NUULL);
    if ((out = ft_strnew(flags.pre)) == NULL)
        return (NULL);
    while (i < flags.pre)
    {
        out[i] = str[i];
        i++;
    }
    return (out);
}
