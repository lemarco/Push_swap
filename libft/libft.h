/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:41:36 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/27 14:41:37 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# define ENDL '\n'
# define ENDO '\0'
# define BUFF_SIZE 50
# define MAX(a, b) a > b ? a : b
# define MIN(a, b) a < b ? a : b
# define ABS(a)	(a < 0) ? -a : a
# define PURPLE 		"\033[35m"
# define CYAN			"\033[36m"
# define RED			"\033[31m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define EOC			"\033[0m"
# define GREEN			"\033[32m"
# define FL_SHP			0x1
# define FL_SPACE		0x2
# define FL_PLUS		0x4
# define FL_MINUS		0x8
# define FL_ZERO		0x10
# define FL_WILDCARD	0x20
# define FL_UPLETTER	0x40
# define FL_SHORT		0x80
# define FL_SHORT2		0x100
# define FL_LONG		0x200
# define FL_LONG2		0x400
# define FL_INTMAX		0x800
# define FL_SIZE_T		0x1000
# define FL_MIN_LEN		0x2000
# define FL_DF_PREC		0x4000
# define FL_PTR			0x8000
# define BUF_SIZE 		256
# define SPACE			' '
# define HEX			16
# define DEC			10
# define OCT			8

typedef struct		s_gnl
{
	int				fd;
	struct s_gnl	*next;
	char			*content;
}					t_gnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_e
{
	short			n;
	short			fl;
	char			*f;
	va_list			ap;
	int				iter;
	int				printf_len;
	int				a_len;
	int				precision;
	int				padding;
	int				buffer_index;
	char			buff[BUF_SIZE];
	unsigned		c;
	int				printed;
}					t_env;
t_env				g_e;

int					get_next_line(const int fd, char **line);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_putnbr(int n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strnstr(const char *haystack,
	const char *needle, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strtrim(char const *s);
char				*ft_strdup(const char *s1);
char				*ft_strnew(size_t size);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, char c);
int					ft_printf(const char *format, ...);
void				ft_printf_format_parser(void);
void				ft_printf_writer(void *elem, size_t size);
void				ft_printf_width(int n);
void				ft_printf_putwstr(void);
void				ft_printf_putchar(unsigned c);
void				ft_printf_putstr_helper(void);
void				ft_printf_put_pointer(void);
void				ft_printf_color(void);
void				ft_printf_no_spec(void);
int					ft_printf_str_chr_iter(char *s, int c, int i);
int					ft_printf_strchr_iter_all(char *s, int c, int i);
size_t				ft_printf_wcharlen(unsigned wc);
size_t				ft_printf_wstrlen(unsigned *s);
void				ft_printf_putnb_base(int base);
void				ft_printf_putnbr(void);
void				ft_printf_itoa_base(uintmax_t n, int b);
#endif
