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
#                                    Files                                     #
# **************************************************************************** #

NAME			= miniRT
LIBFT			= $(LIBFT_PATH)libft.a
MLX				= $(MLX_PATH)libmlx.a

# **************************************************************************** #
#                                   Path's                                     #
# **************************************************************************** #

INC_PATH		= include
BUILD_PATH		= .build/

VPATH			+= ./
VPATH			+= tests/aux/
VPATH			+= src/
VPATH			+= src/aux/
VPATH			+= src/canvas/
VPATH			+= src/math/
VPATH			+= src/math/aux/
VPATH			+= src/math/tuples/
VPATH			+= src/math/matrices/
VPATH			+= src/math/matrices/transformations
VPATH			+= src/parse/
VPATH			+= src/ray
VPATH			+= src/objects
VPATH			+= src/surface
VPATH			+= src/light
VPATH			+= src/world

LIBFT_PATH		= $(INC_PATH)/libft/
MLX_PATH		= $(INC_PATH)/minilibx-linux/

# **************************************************************************** #
#                                   Files                                      #
# **************************************************************************** #

MAIN_FILE		?= main.c

TEST_FILES		+= print_matrix
TEST_FILES		+= print_tuple
TEST_FILES		+= print_color
TEST_FILES		+= prints

CANVAS_FILES	+= canvas ft_pixel_put init_canvas ft_destroy_canvas ft_init_hooks color_operations
MATH_FILES		+= constructors
MATH_FILES		+= is_equals
MATH_FILES		+= sum_tuples
MATH_FILES		+= subtract_tuples
MATH_FILES		+= negate_tuple
MATH_FILES		+= multiply_tuple
MATH_FILES		+= divide_tuple
MATH_FILES		+= magnitude
MATH_FILES		+= normalize
MATH_FILES		+= dot
MATH_FILES		+= cross
MATH_FILES		+= multiply_tuple_tuple

MATRIX_FILES	+= matrix
MATRIX_FILES	+= identity_matrix
MATRIX_FILES	+= multiply_matrix
MATRIX_FILES	+= multiply_matrix_tuple
MATRIX_FILES	+= translation
MATRIX_FILES	+= transpose_matrix
MATRIX_FILES	+= determinant
MATRIX_FILES	+= submatrix
MATRIX_FILES	+= minor
MATRIX_FILES	+= cofactor
MATRIX_FILES	+= inverse
MATRIX_FILES	+= rotate_x
MATRIX_FILES	+= rotate_y
MATRIX_FILES	+= rotate_z
MATRIX_FILES	+= scaling
MATRIX_FILES	+= shearing

RAY_FILES		+= ray_constructor
RAY_FILES		+= position
RAY_FILES		+= intersect
RAY_FILES		+= transform_ray
RAY_FILES		+= intersection
RAY_FILES		+= intersections
RAY_FILES		+= hit
RAY_FILES		+= sort_intersections

OBJ_FILES		+= set_transform
OBJ_FILES		+= constructors_objs

LIGHT_FILES		+= point_light
LIGHT_FILES		+= lighting

SURFACE_FILES	+= normal_at
SURFACE_FILES	+= reflect

WORLD_FILES		+= world_constructors
WORLD_FILES		+= intersect_world
WORLD_FILES		+= prepare_computations
WORLD_FILES		+= shade_hit
WORLD_FILES		+= color_at

FILES			+= $(TEST_FILES)
FILES			+= $(CANVAS_FILES)
FILES			+= $(MATH_FILES)
FILES			+= $(MATRIX_FILES)
FILES			+= $(RAY_FILES)
FILES			+= $(OBJ_FILES)
FILES			+= $(LIGHT_FILES)
FILES			+= $(SURFACE_FILES)
FILES			+= $(WORLD_FILES)


SRCS			= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS			= $(addprefix $(BUILD_PATH), $(addsuffix .o, $(FILES)))

# **************************************************************************** #
#                                    Git                                       #
# **************************************************************************** #

LIBFT_URL		= https://github.com/Denionline/libft.git
MLX_URL			= https://github.com/42paris/minilibx-linux.git

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Werror -Wextra -Wall -g
MLXFLAGS		= -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz
MAKE			= make --no-print-directory
MAKERE			= make re --no-print-directory
RM				= rm -rf
LIBS			= $(LIBFT)

# **************************************************************************** #
#                                  Commands                                    #
# **************************************************************************** #

all: start verify_libft verify_mlx $(NAME)
	@printf "$(C_MAGENTA)===========End [$(NAME)]===========$(C_STD)\n"

start:
	@printf "$(C_MAGENTA)===========Program [$(NAME)]===========$(C_STD)\n"

$(NAME): $(BUILD_PATH) $(OBJS)
	@$(CC) $(CFLAGS) -I$(INC_PATH) $(MAIN_FILE) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

$(BUILD_PATH)%.o: %.c
	@$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@
	@printf "$(C_YELLOW)Compiling $< -> $@$(C_STD)\n";

$(BUILD_PATH):
	@mkdir -p $(BUILD_PATH)

clean:
	@$(RM) $(BUILD_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean make_libft all

verify_libft:
	@if test ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "libft: $(C_GREEN)✅$(C_STD)\n"; fi
	@cd $(LIBFT_PATH); git pull; $(MAKE); cd ../../

get_libft:
	@echo "Cloning Libft"
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@printf "$(C_GREEN)libft$(C_STD) successfully downloaded\n"

make_libft:
	@$(MAKE) -C $(LIBFT_PATH)

verify_mlx:
	@if test ! -d "$(MLX_PATH)"; then $(MAKE) get_mlx; \
		else printf "minilibx: $(C_GREEN)✅$(C_STD)\n"; fi

get_mlx:
	@printf "Cloning get_next_line\n"
	@git clone $(MLX_URL) $(MLX_PATH)
	@printf "\n$(C_GREEN)minilibx$(C_STD) successfully downloaded\n"
	@$(MAKE) -C $(MLX_PATH)
