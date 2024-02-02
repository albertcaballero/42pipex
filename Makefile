NAME = pipex
LIBRARY = pipex.h
CFLAGS= -Wall -Wextra -Werror

RED     =   \033[38;5;161m
GREEN   =   \033[38;5;154m
YELLOW  =   \033[38;5;227m
BLUE	=   \033[38;5;81m
PURPLE  =   \033[38;5;93m
PINK	=	\033[38;5;219m
NC      =   \033[0m

FILES = pipex_bonus.c parseargs.c err_handling.c heredoc.c utils.c
SRCDIR = src/
SRC = $(addprefix $(SRCDIR),$(FILES))
DIR_OBJ = tmp/
OBJS = $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

all: tempdir makelib $(NAME)

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) -L./src/libft -lft -o $(NAME) #-fsanitize="address,undefined" -g
	@echo "${PURPLE}== PIPEX COMPILED SUCCESSFULLY ==${NC}"

$(DIR_OBJ)%.o: %.c Makefile $(LIBRARY) src/libft/libft.a
	@mkdir -p $(dir $@)
	@echo "${YELLOW}Compiling: ${NC}$@"
	@cc $(CFLAGS) -c $< -o $@

tempdir:
	@mkdir -p $(DIR_OBJ)

makelib:
	@$(MAKE) -C ./src/libft bonus --no-print-directory -silent
	@echo "${GREEN}Libft ok👍${NC}"

clean:
	@$(MAKE) -C ./src/libft fclean --no-print-directory -silent
	@rm -rf $(DIR_OBJ)

fclean: clean
	@echo "${RED}....EXTERMINATING....${NC}"
	@sleep 0.5
	@echo "${PINK}🧨\tLIBFT${NC}"
	@rm -f $(NAME)
	@sleep 0.5
	@echo "${PINK}🧨\tPIPEX${NC}"
	@sleep 0.5
	@echo "${RED}.......DONE.......${NC}"

re: fclean all

.PHONY: all clean fclean re