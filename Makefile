# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 16:52:50 by lvon-war          #+#    #+#              #
#    Updated: 2023/05/25 16:52:53 by lvon-war         ###   ########.fr        #
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
SRC_PATH := ./SRC/
OBJ_PATH := ./OBJ/

ifeq ($(shell uname),Darwin)
	# macOS
INC_PATH := -I ./include/libft/include -I ./include/minilibx_macos -I ./include
LINKER := -L ./include/minilibx_macos -lmlx -lm
FRAMEWORK := -framework Appkit -framework OpenGl

else

INC_PATH := -I ./include/libft/include -I ./include/minilibx-linux -I ./include
LINKER := -L ./include/minilibx-linux -lmlx -lX11 -lXext -lm
FRAMEWORK :=
endif
all : $(LIBFT) $(NAME)

$(LIBFT) :
	@make -C ./include/libft

# Files to compile
OBJ1 := $(FILES:.c=.o)
OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_PATH)     

# Build final Binary
$(NAME): $(OBJ)
	@echo [INFO] Creating $(Shell uname) Binary Executable [$(NAME)]
	$(AR) $(NAME) $(OBJ) $(LINKFLAGS)
	$(CC) $(CFLAGS) $(NAME) $(LIBFT)  $(INC_PATH) $(FRAMEWORK) $(LINKER) -o $(ENAME)

# Clean all the object files and the binary
clean:   
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_PATH)*

fclean: clean
		@$(RM) -rfv $(NAME)
		@$(RM) -rfv $(ENAME)

deepclean : fclean
		@make fclean -C ./include/libft
re: fclean all

san: all
	$(CC) $(CFLAGS) $(NAME) $(LIBFT)  $(INC_PATH) $(FRAMEWORK) $(LINKER) -fsanitize=address -o $(ENAME)
test: all
	./fdf mytest.fdf

.PHONY : clean fclean re