# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_MAGENTA := \033[35m
C_YELLOW  := \033[33m
C_GREEN   := \033[32m
C_STD     := \033[0m

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
VPATH			+= src/world/aux

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

CANVAS_FILES	+= canvas
CANVAS_FILES	+= ft_pixel_put
CANVAS_FILES	+= init_canvas
CANVAS_FILES	+= ft_destroy_canvas
CANVAS_FILES	+= ft_init_hooks
CANVAS_FILES	+= render
CANVAS_FILES	+= pixel_at

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
RAY_FILES		+= ray_for_pixel

OBJ_FILES		+= set_transform
OBJ_FILES		+= constructors_objs
OBJ_FILES		+= local_normal_at
OBJ_FILES		+= local_intersect

LIGHT_FILES		+= point_light
LIGHT_FILES		+= lighting
LIGHT_FILES		+= stripe_at
LIGHT_FILES		+= stripe_pattern

SURFACE_FILES	+= normal_at
SURFACE_FILES	+= reflect

WORLD_FILES		+= view_transform
WORLD_FILES		+= camera
WORLD_FILES		+= world_constructors
WORLD_FILES		+= intersect_world
WORLD_FILES		+= prepare_computations
WORLD_FILES		+= shade_hit
WORLD_FILES		+= color_at
WORLD_FILES		+= is_shadowed
WORLD_FILES		+= append_object_on_world

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
	@printf "\r$(C_YELLOW)[%s] Files compiled $(C_STD)%-30s\n" $$(echo $(OBJS) | wc -w) " "
	@printf "$(C_MAGENTA)✔ Build finished: $(NAME)$(C_STD)\n"

start:
	@printf "$(C_MAGENTA)▶ Building $(NAME)...$(C_STD)\n"

$(NAME): $(BUILD_PATH) $(OBJS)
	@$(CC) $(CFLAGS) -I$(INC_PATH) $(MAIN_FILE) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

$(BUILD_PATH)%.o: %.c
	@printf "\r$(C_YELLOW)[CC] %-50s$(C_STD)" "$<"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

$(BUILD_PATH):
	@mkdir -p $(BUILD_PATH)

clean:
	@$(RM) $(BUILD_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

verify_libft:
	@if test ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "libft: $(C_GREEN)✅$(C_STD)\n"; fi
# 	@cd $(LIBFT_PATH); git pull; $(MAKE); cd ../../

get_libft:
	@echo "Cloning Libft"
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@printf "$(C_GREEN)libft$(C_STD) successfully downloaded\n"

verify_mlx:
	@if test ! -d "$(MLX_PATH)"; then $(MAKE) get_mlx; \
		else printf "minilibx: $(C_GREEN)✅$(C_STD)\n"; fi

get_mlx:
	@printf "Cloning get_next_line\n"
	@git clone $(MLX_URL) $(MLX_PATH)
	@printf "\n$(C_GREEN)minilibx$(C_STD) successfully downloaded\n"
	@$(MAKE) -C $(MLX_PATH)
