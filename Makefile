NAME = pipex
LIBRARY = pipex.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

RED     =   \033[38;5;161m
GREEN   =   \033[38;5;154m
YELLOW  =   \033[38;5;227m
BLUE	=   \033[38;5;81m
PURPLE  =   \033[38;5;93m
PINK	=	\033[38;5;219m
NC      =   \033[0m

SRC = pipex.c parseargs.c

all: makelib $(NAME)

$(NAME): $(LIBRARY) Makefile $(SRC) libft/libft.a
	@$(CC) $(CFLAGS) $(SRC) -L./libft -lft -L./printf -lftprintf -o $(NAME) #-fsanitize="address,undefined" -g
	@printf "${PURPLE}== PIPEX COMPILED SUCCESSFULLY ==\n${NC}"

makelib:
	@$(MAKE) -C ./libft bonus --no-print-directory -silent
	@printf "${GREEN}Libft ok👍\n${NC}"
	@$(MAKE) -C ./printf all --no-print-directory -silent
	@printf "${GREEN}Printf ok👍\n${NC}"

clean:
	@$(MAKE) -C ./libft clean --no-print-directory -silent

fclean: clean
	@printf "${RED}....EXTERMINATING....\n${NC}"
	@$(MAKE) -C ./libft fclean --no-print-directory -silent
	@sleep 0.5
	@printf "${PINK}🧨\tLIBFT\n${NC}"
	@$(MAKE) -C ./printf fclean --no-print-directory -silent
	@sleep 0.5
	@printf "${PINK}🧨\tPRINTF\n${NC}"
	@rm -f $(NAME)
	@sleep 0.5
	@printf "${PINK}🧨\tPIPEX\n${NC}"
	@sleep 0.5
	@printf "${RED}.......DONE.......\n${NC}"

re: fclean all

PRINT_N = $(shell grep "printf" $(SRC) | wc -l)
DEL_N = $(shell grep "//DELETE" $(SRC) | wc -l)
FILE_N = $(shell ls | grep a.out | wc -l)
FILE2_N = $(shell ls | grep *.txt | wc -l)

forbidden:
	@printf "$(BLUE)\n=====FINDING DELETEABLES=====\n\n"
	@printf "${YELLOW}"
	@grep "printf" $(SRC) || true
	@grep "//DELETE" $(SRC) || true
	@printf "${PINK}HAY %i PRINTF Y %i BLOQUES A BORRAR\n${NC}" $(PRINT_N) $(DEL_N)
	@printf "$(BLUE)\n=====SCANNING EXTRA FILES=====\n\n"
	@ls | grep a.out || true
	@ls | grep *.txt || true
	@printf "${PINK}HAY %i ARCHIVOS A BORRAR\n${NC}" $(shell expr $(FILE_N) + $(FILE2_N))
	@printf "$(BLUE)\n=====EXECUTING NORMINETTE=====\n\n${RED}"
	@norminette > /dev/null && printf "$(GREEN)	---OK---\n\n" || norminette | grep Error
	@printf "${NC}"

lesgo:
	@printf "$(BLUE)\n\t=====ARE YOU READYYYY??=====\n\n${GREEN}"
	@echo "\t####                      (25%)\r\c"
	@sleep 0.5
	@echo "\t###########               (50%)\r\c"
	@sleep 0.5
	@echo "\t###############           (75%)\r\c"
	@sleep 0.5
	@echo "\t#######################   (100%)\r\c"
	@echo "\n"
	@sleep 0.5
	@printf "$(BLUE)\n\t=====DONE=====\n\n${GREEN}"
	@sleep 2
	@cat /dev/random

.PHONY: all clean fclean re bonus