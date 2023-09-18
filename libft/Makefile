NAME = libft.a
BNAME = .bonus
LIBRARY = libft.h
CFLAGS= -Wall -Wextra -Werror -I.
CC = cc

SRC = ft_isalpha.c ft_memchr.c	ft_memset.c\
	ft_strncmp.c ft_isascii.c	ft_memcmp.c\
	ft_strchr.c	ft_strrchr.c	ft_bzero.c\
	ft_isdigit.c ft_memcpy.c	ft_strlcpy.c\
	ft_tolower.c ft_isalnum.c ft_isprint.c ft_memmove.c\
	ft_toupper.c ft_strlcat.c\
	ft_atoi.c ft_strnstr.c ft_calloc.c\
	ft_strdup.c ft_striteri.c ft_strmapi.c\
	ft_itoa.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putendl_fd.c
OBJS = $(SRC:.c=.o)

BONUSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUSOBJS = $(BONUSRC:.c=.o)


%.o: %.c $(LIBRARY) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBRARY)
	ar -crs $(NAME) $(OBJS)

bonus: $(BNAME)
$(BNAME): $(BONUSOBJS) $(OBJS)
	ar -crs $(NAME) $(BONUSOBJS) $(OBJS)
	touch $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus