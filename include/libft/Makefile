# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME= libft
ARQUIVE= libft.a

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD			= \033[0;39m
C_GRAY			= \033[0;30m
C_RED			= \033[0;31m
C_GREEN			= \033[0;32m
C_YELLOW		= \033[0;33m
C_BLUE			= \033[0;34m
C_MAGENTA		= \033[0;35m
C_CYAN			= \033[0;36m
C_WHITE			= \033[0;37m
C_LGRAY			= \033[0;90m
C_LRED			= \033[0;91m
C_LGREEN		= \033[0;92m
C_LYELLOW		= \033[0;93m
C_LBLUE			= \033[0;94m
C_LMAGENTA		= \033[0;95m
C_LCYAN			= \033[0;96m
C_LWHITE		= \033[0;97m

# **************************************************************************** #
#                                     Paths                                    #
# **************************************************************************** #

SRC_PATH		= src/
BUILD_PATH		= .build/
INCLUDE_PATH	= include

FT_IS_PATH		= ft_is/
FT_TO_PATH		= ft_to/
FT_STR_PATH		= ft_str/
FT_PUT_PATH		= ft_put/
FT_MEM_PATH		= ft_mem/
FT_LST_PATH		= ft_lst/

FT_IS_FILES		+= ft_isalnum
FT_IS_FILES		+= ft_isalpha
FT_IS_FILES		+= ft_isprint
FT_IS_FILES		+= ft_isdigit
FT_IS_FILES		+= ft_isspace
FT_IS_FILES		+= ft_isascii
FT_IS_FILES		+= is_strmatch

FT_TO_FILES		+= ft_toupper
FT_TO_FILES		+= ft_tolower
FT_TO_FILES		+= ft_atoi
FT_TO_FILES		+= ft_atof
FT_TO_FILES		+= ft_atoll
FT_TO_FILES		+= ft_itoa
FT_TO_FILES		+= ft_basetoi

FT_STR_FILES	+= ft_strcmp
FT_STR_FILES	+= ft_strncmp
FT_STR_FILES	+= ft_strlen
FT_STR_FILES	+= ft_strlcpy
FT_STR_FILES	+= ft_strlcat
FT_STR_FILES	+= ft_substr
FT_STR_FILES	+= ft_strtrim
FT_STR_FILES	+= ft_strchr
FT_STR_FILES	+= ft_split
FT_STR_FILES	+= ft_strrchr
FT_STR_FILES	+= ft_strnstr
FT_STR_FILES	+= ft_strmapi
FT_STR_FILES	+= ft_strjoin
FT_STR_FILES	+= ft_strdup
FT_STR_FILES	+= ft_striteri
FT_STR_FILES	+= ft_strtok
FT_STR_FILES	+= ft_strremove

FT_PUT_FILES        += ft_putchar_fd
FT_PUT_FILES        += ft_putstr_fd
FT_PUT_FILES        += ft_putendl_fd
FT_PUT_FILES        += ft_putnbr_fd

FT_MEM_FILES        += ft_calloc
FT_MEM_FILES        += ft_bzero
FT_MEM_FILES        += ft_memcpy
FT_MEM_FILES        += ft_memcmp
FT_MEM_FILES        += ft_memmove
FT_MEM_FILES        += ft_memset
FT_MEM_FILES        += ft_memchr

FT_LST_FILES    += ft_lstnew
FT_LST_FILES    += ft_lstadd_front
FT_LST_FILES    += ft_lstsize
FT_LST_FILES    += ft_lstlast
FT_LST_FILES    += ft_lstadd_back
FT_LST_FILES    += ft_lstdelone
FT_LST_FILES    += ft_lstclear
FT_LST_FILES    += ft_lstiter
FT_LST_FILES    += ft_lstmap


SRC_FILES       += $(addprefix $(FT_IS_PATH), $(FT_IS_FILES) )
SRC_FILES       += $(addprefix $(FT_TO_PATH), $(FT_TO_FILES) )
SRC_FILES       += $(addprefix $(FT_STR_PATH), $(FT_STR_FILES) )
SRC_FILES       += $(addprefix $(FT_PUT_PATH), $(FT_PUT_FILES) )
SRC_FILES       += $(addprefix $(FT_MEM_PATH), $(FT_MEM_FILES) )
SRC_FILES       += $(addprefix $(FT_LST_PATH), $(FT_LST_FILES) )

OBJ_FILES       += $(FT_IS_FILES)
OBJ_FILES       += $(FT_TO_FILES)
OBJ_FILES       += $(FT_STR_FILES)
OBJ_FILES       += $(FT_PUT_FILES)
OBJ_FILES       += $(FT_MEM_FILES)
OBJ_FILES       += $(FT_LST_FILES)

SRCS 			:= $(addprefix $(SRC_PATH), $(addsuffix .c,$(SRC_FILES)))
OBJS 			:= $(addprefix $(BUILD_PATH), $(addsuffix .o,$(OBJ_FILES)))


# **************************************************************************** #
#                                     Compiler                                 #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MAKE		= make --no-print-directory

# **************************************************************************** #
#                                     Comands                                  #
# **************************************************************************** #

RM          = rm -rf
AR          = ar rcs

# **************************************************************************** #
#                                      Rules                                   #
# **************************************************************************** #

.PHONY: all clean fclean re

all: start $(ARQUIVE)
	@printf "$(C_GREEN)[$(NAME)] is ready :D$(C_STD)\n"

start:
	@printf "$(C_MAGENTA)===========Library [$(NAME)]===========$(C_STD)\n"

$(ARQUIVE): | $(BUILD_PATH)
	@printf "\n$(C_YELLOW)Compile $(NAME) files:$(C_STD)\n"
	@TOTAL=$$(echo $(SRCS) | wc -w); \
		CUR=1; \
		for SRC in $(SRCS); do\
			OBJ=$(BUILD_PATH)$$(basename $$SRC .c).o;\
			$(CC) $(CFLAGS) -I $(INCLUDE_PATH) -c $$SRC -o $$OBJ;\
			PERC=$$(printf "%d" $$((100 * CUR / TOTAL))); \
			FILLED=$$(printf "%0.f" $$((20 * PERC / 100))); \
			EMPTY=$$((20 - FILLED)); \
			BAR=$$(printf "$(C_GREEN)%*s$(C_STD)" $$FILLED "" | tr " " "#")$$(printf "%*s" $$EMPTY "" | tr " " "."); \
			printf "\rCompiling [%s] %3d%%" $$BAR $$PERC; \
			CUR=$$((CUR + 1)); \
		done; \
		printf "\n";
	@$(AR) $(ARQUIVE) $(OBJS)

$(BUILD_PATH):
	@mkdir $(BUILD_PATH)

clean:
	@$(RM) $(BUILD_PATH)

fclean: clean
	@$(RM) $(ARQUIVE)

re: fclean all
