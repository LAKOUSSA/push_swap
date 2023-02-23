NAME		=	push_swap
NAME_BONUS	=	checker
LIB			=	libft/libft.a
PRINT		=	ft_printf/libftprintf.a

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror

SRC_LIB		=	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
				libft/ft_isprint.c libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_strlcat.c \
				libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c \
				libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_atoi.c libft/ft_strdup.c \
				libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
				libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
				libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_lstnew_bonus.c libft/ft_substr.c \
				libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c \
				libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c
SRC_PRINT	=	ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_putnbr_add.c \
				ft_printf/ft_putnbr.c ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putnbr_hlow.c \
				ft_printf/ft_putnbr_hupp.c ft_printf/ft_printf.c

SRC			=	ps/beggin.c ps/act00.c ps/act01.c ps/act02.c ps/sort.c ps/large.c

SRC_BONUS	=	bonus/checker.c bonus/need.c bonus/swap.c bonus/push.c bonus/rotate.c bonus/reverse_rotate.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ			=	$(SRC:.c=.o)

OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

all		:	$(NAME)

$(NAME): $(OBJ) $(LIB) $(PRINT)
	@printf "\e[38;5;236m \n ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎ COMPILING ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎\n\e[0m\n"
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(PRINT) -o $(NAME)
	@printf "\e[38;5;216m→	successfully build	✔︎\e[0m\n"

$(LIB)	:	$(SRC_LIB)
	@make -C libft
	@make -C libft bonus
	@make -C libft clean

$(PRINT):	$(SRC_PRINT)
	@make -C ft_printf
	@make -C ft_printf clean

bonus	:	$(OBJ_BONUS) $(LIB) $(PRINT)
			@printf "\e[38;5;236m \n ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎ COMPILING BONUS ⚡︎⚡︎⚡︎⚡︎⚡︎⚡︎\n\e[0m\n"
			$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) $(PRINT) -o $(NAME_BONUS)
			@printf "\e[38;5;216m→	successfully build	✔︎\e[0m\n"

clean	:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@make -C libft clean
	@make -C ft_printf clean
	@printf "\e[38;5;206m→	Objects files deleted 🗑\e[0m\n"

fclean	: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -C libft fclean
	@make -C ft_printf fclean
	@printf "\e[38;5;206m→	All files was deleted 🗑\e[0m\n"

re		: fclean all
