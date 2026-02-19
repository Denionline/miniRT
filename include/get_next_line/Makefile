# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 10:14:44 by dximenes          #+#    #+#              #
#    Updated: 2025/06/17 11:18:17 by dximenes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD = \033[0;39m
C_GRAY = \033[0;90m
C_RED = \033[0;91m
C_GREEN = \033[0;92m
C_YELLOW = \033[0;93m
C_BLUE = \033[0;94m
C_MAGENTA = \033[0;95m
C_CYAN = \033[0;96m
C_WHITE = \033[0;97m

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME		= get_next_line
ARQUIVE		= $(NAME).a

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

SRC_PATH	= src/
BUILD_PATH	= .build/
INC_PATH	= include/

# **************************************************************************** #
#                                    Files                                     #
# **************************************************************************** #

FILES		=	get_next_line
FILES		+=	get_next_line_utils

SRCS		=	$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS		=	$(addprefix $(BUILD_PATH), $(addsuffix .o, $(FILES)))

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
MAKE		=	make --no-print-directory

# **************************************************************************** #
#                                    Comands                                   #
# **************************************************************************** #


all: start $(NAME)
	@printf "$(C_GREEN)[$(NAME)] is ready :D$(C_STD)\n"

start:
	@printf "$(C_MAGENTA)===========Function [$(NAME)]===========$(C_STD)\n"

$(NAME): $(BUILD_PATH)
	@printf "\n$(C_YELLOW)Compile $(NAME) files:$(C_STD)\n"
	@TOTAL=$$(echo $(SRCS) | wc -w);\
	CUR=1;\
	for SRC in $(SRCS); do\
		OBJ=$(BUILD_PATH)$$(basename $$SRC .c).o;\
		$(CC) $(CFLAGS) -I$(INC_PATH) -c $$SRC -o $$OBJ;\
		PERC=$$(printf "%d" $$((100 * CUR / TOTAL)));\
		FILLED=$$(printf "%0.f" $$((20 * PERC / 100)));\
		EMPTY=$$((20 - FILLED));\
		BAR=$$(printf "$(C_GREEN)%*s$(C_STD)" $$FILLED "" | tr " " "#")$$(printf "%*s" $$EMPTY "" | tr " " ".");\
		printf "\rCompiling [%s] %3d%%" $$BAR $$PERC;\
		CUR=$$((CUR + 1)); \
	done;\
	printf "\n";
	@$(AR) $(ARQUIVE) $(OBJS)

$(BUILD_PATH):
	@mkdir $(BUILD_PATH)

clean:
	@rm -rf $(BUILD_PATH)

fclean: clean
	@rm -rf $(ARQUIVE)

re: fclean all
