# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 16:52:50 by lvon-war          #+#    #+#              #
#    Updated: 2023/05/25 17:44:44 by lvon-war         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Name
ENAME	=	fdf
NAME	=	FdF.a
CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar -rsc
FILES	=	Fdf.c hook.c visu.c parsing.c Matrixcalc.c button.c

# Path for .c , .h and .o Files 
LIBFT	=	./include/libft/lib.a
MLX := ./include/minilibx-linux/libmlx.a
SRC_PATH := ./SRC/
OBJ_PATH := ./OBJ/
MLX_PATH := ./include/minilibx-linux

# Compliation under Mac OS
ifeq ($(shell uname),Darwin)
INC_PATH := -I ./include/libft/include -I ./include/minilibx_macos -I ./include
LINKER := -L ./include/minilibx_macos -lmlx -lm
FRAMEWORK := -framework Appkit -framework OpenGl
MLX := ./include/minilibx_macos

# Compliation under anything else (but only work under linux)
else
INC_PATH := -I ./include/libft/include -I ./include/minilibx-linux -I ./include
LINKER := -L ./include/minilibx-linux -lmlx -lX11 -lXext -lm
FRAMEWORK :=
MLX_PATH := ./include/minilibx-linux
endif

all : $(LIBFT) $(MLX) $(NAME)

$(MLX) :
	@echo [INFO] Compliling minilibx
	@make -C $(MLX_PATH)

$(LIBFT) :
	@echo [INFO] Compliling libft
	@make -C ./include/libft

# Files to compile
OBJ1 := $(FILES:.c=.o)
OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_PATH)     

# Build final Binary
$(NAME): $(OBJ) $(MLX)
	@echo [INFO] Creating $(Shell uname) Binary Executable [$(NAME)]
	$(AR) $(NAME) $(OBJ) $(LINKFLAGS)
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) $(MLX) $(INC_PATH) $(FRAMEWORK) $(LINKER) -o $(ENAME)

# Clean all the object files and the binary
clean:   
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_PATH)*

fclean: clean
		@$(RM) -rfv $(NAME)
		@$(RM) -rfv $(ENAME)
deepclean : fclean
		@make fclean -C ./include/libft
		@make clean -C $(MLX_PATH)
re: fclean all

san: all
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) $(MLX) $(INC_PATH) $(FRAMEWORK) $(LINKER) -fsanitize=address -o $(ENAME)

test: all
	./fdf mytest.fdf

.PHONY : clean fclean re