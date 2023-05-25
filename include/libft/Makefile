# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvon-war <lvonwar42@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 16:51:48 by lvon-war          #+#    #+#              #
#    Updated: 2023/05/25 16:51:52 by lvon-war         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable Name 
NAME	=	lib.a
CFLAGS	=	-Wall -Werror -Wextra -I. -c
AR		=	ar -rsc
FILES	=	ft_printf.c ft_basicprint.c ft_printu.c ft_printx.c
FILES	+=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcpy.c \
			ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_toupper.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_is_whitespace.c ft_power.c ft_swap.c ft_abs.c ft_listmanip.c\
			ft_rev_int_tab.c
FILES	+=	get_next_line.c
all : $(NAME)

# Path for .c , .h and .o Files 
SRC_PATH := ./LIBFT_SRCS/
PFSRC_PATH := ./PF_SRCS/
GNLSRC_PATH := ./GNL_SRCS/
OBJ_PATH := ./OBJ/
INC_PATH := -I ./include

# Files to compile
OBJ1 := $(FILES:.c=.o)
OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)     

$(OBJ_PATH)%.o: $(GNLSRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)  

$(OBJ_PATH)%.o: $(PFSRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)          

# Build final Binary
$(NAME): $(OBJ)
	@echo [INFO] Creating Binary Executable [$(NAME)]
	$(AR) $(NAME) $(OBJ) $(LINKFLAGS)

# Clean all the object files and the binary
clean:   
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_PATH)*


fclean: clean
		@$(RM) -rfv $(NAME)
		@$(RM) -rfv test.out

re: fclean all

test : all
	gcc main.c $(NAME) $(C_FLAGS) -o test.out
	./test.out

.PHONY : clean fclean re
