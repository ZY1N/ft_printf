/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinzhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:18:04 by yinzhang          #+#    #+#             */
/*   Updated: 2019/05/18 17:04:05 by yinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>

# define H				1
# define HH				2
# define L				3
# define LL				4
# define J				5
# define Z				6
# define BIGL			7

# define POSITIVE	 	66
# define NEGATIVE		88

# define CCONVERSIONS 	"cspdiouxXf%"
# define CFLAGS 		"#-+ .*0123456789hljz"
# define ALLSYMBOLS 	"cspdiouxXfyb%#-+ .*0123456789hLljz"

typedef struct			s_struct
{
	char				*format;

	int					nprinted;

	int					i;
	int					len;

	int					minus;
	int					plus;
	int					space;
	int					zero;
	int					hash;

	int					width;
	int					precisiontf;
	int					precision;
	int					length;
}						t_struct;

typedef	struct			s_fstruct
{
	char				*s1;
	char				*s2;
	int					precision;
	long double			i;
	long double			fl;
	int					zeros;
	int					precisionaddon;
	int					padding;
	int					beforedecimalnbr;
	char				c;
	char				sign;
	int					signint;
	int					hash;
	int					dot;
}						t_fstruct;

void					modifiers();
void					conversions(char c, va_list ap, t_struct *f);
void					ifchar(t_struct *f, va_list ap);
void					ifpercent();
void					ifstring();
void					writeblanks(int n);
void					ifpointer();
void					ifint(t_struct *f, va_list ap, int sign, intmax_t n);
char					*ft_itoa_base(uintmax_t value, uintmax_t base);
void					ifoctal();
int						unsigned_nbr_len(uintmax_t n, int base);
void					ifhex(t_struct *f, va_list ap, char c);
void					writezeros(int n);
void					ifudecint(t_struct *f, va_list ap);
void					ifloat(t_struct *f, va_list ap);
char					*ft_stradd(char *a, char *b);
void					error();
void					widthstar(const char *format, t_struct *f, va_list ap);
char					*ft_itoa_base_upper(intmax_t value, intmax_t base);
int						signed_nbr_len(intmax_t n, int base);
char					findchar(t_struct *f);
void					rightalignedf(t_struct *f, t_fstruct g);
void					leftalignedf(t_struct *f, t_fstruct g);
int						ft_printf(const char *format, ...);
void					ifcat();
void					ifbinary(t_struct *f, va_list ap);
#endif
