/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   libjr.h                                   \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#ifndef LIBJR_H
# define LIBJR_H
# include <strings.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

void	*jr_memset(void *s, int c, size_t n);
void	jr_bzero(void *s, size_t n);
void	*jr_memcpy(void *dst, void *src, size_t n);
void	*jr_memccpy(void *dst, void *src, int c, size_t n);
void	*jr_memmove(void *dst, void *src, size_t n);
void	*jr_memchr(void *s, int c, size_t n);
int		jr_memcmp(const void *s1, const void *s2, size_t n);
size_t	jr_strlen(char *str);
char	*jr_strdup(char *str);
char	*jr_strcpy(char *dst, char *src);
char	*jr_strncpy(char *dst, const char *src, size_t dsize);
char	*jr_strcat(char *dst, const char *src);
char	*jr_strncat(char *dst, const char *src, size_t ssize);
char	*jr_strchr(const char *str, int c);
char	*jr_strrchr(const char *str, int c);
char	*jr_strstr(const char *s1, const char *s2);
char	*jr_strnstr(const char *big, const char *little, size_t len);
int		jr_strcmp(const char *s1, const char *s2);
int		jr_strncmp(const char *s1, const char *s2, size_t n);
int		jr_atoi(char *nptr);
int		jr_isalpha(int c);
int		jr_isdigit(int c);
int		jr_isalnum(int c);
int		jr_isascii(int c);
int		jr_isprint(int c);
int		jr_toupper(int c);
int		jr_tolower(int c);
void	jr_memdel(void **ap);
char	*jr_strnew(size_t size);
void	jr_strdel(char **as);
void	jr_strclr(char *s);
void	jr_striter(char *s, void (*f)(char *));
void	jr_striteri(char *s, void (*f)(unsigned int, char *));
char	*jr_strmap(const char *s, char (*f)(char));
char	*jr_strmapi(const char *s, char (*f)(unsigned int, char));
int		jr_strequ(const char *s1, const char *s2);
char	*jr_strsub(const char *s, unsigned int start, size_t len);
char	*jr_strjoin(const char *s1, const char *s2);
char	*jr_strtrim(const char *s);
char	**jr_strsplit(const char *s, char c);
char	*jr_itoa(int n);
void	jr_putchar(char c);
void	jr_putstr(const char *s);
void	jr_putendl(const char *s);
void	jr_putnbr(int n);
void	jr_putchar_fd(char c, int fd);
void	jr_putstr_fd(const char *s, int fd);
void	jr_putendl_fd(const char *s, int fd);
t_list	*jr_lstnew(const void *content);
void	jr_lstdelone(t_list *lst, void (*del)(void *));
void	jr_lstclear(t_list **alst, void (*del)(void *));
void	jr_lstadd_front(t_list **alst, t_list *new);
void	jr_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	jr_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void	*jr_calloc(size_t nmemb, size_t size);

#endif
