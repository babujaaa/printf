#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
size_t			ft_strlen(const char *str);
int				ft_putstr(char *s);
int				ft_putnbr_base(long int n, char *base);
int				ft_putptr(va_list args);
int				ft_putptr_base(size_t n, char *base);

#endif
