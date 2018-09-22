#################################################
###                  Settings                 ###
#################################################

EXEC = lem-in
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC_DIR = ./srcs/
INC_DIR = ./includes/
OBJ_DIR = ./objs/

#################################################
###                 Sources                   ###
#################################################

SRC =\
	main.c \
	\
	engine/li_find_best_road.c \
	engine/li_print_result.c \
	engine/li_utilities.c \
	\
	parsing/get_datas.c \
	parsing/handle_rooms.c \
	parsing/handle_pipes.c \
	\
	li_mini_libft/ft_strequ.c \
	\
	li_mini_libft2/ft_strjoin_free_s1.c \
	li_mini_libft2/ft_atoi.c \
	li_mini_libft2/ft_lstnew.c \
	li_mini_libft2/ft_lstpushback.c \
	li_mini_libft2/ft_strcmp.c \
	li_mini_libft2/ft_strdel.c \
	li_mini_libft2/ft_strdup.c \
	li_mini_libft2/ft_strisdigit.c \
	li_mini_libft2/ft_strsub.c \
	li_mini_libft2/get_next_line.c \
	li_mini_libft2/ft_strrealloc.c \
	li_mini_libft2/ft_strcat.c \
	li_mini_libft2/ft_strcpy.c \
	li_mini_libft2/ft_strncat.c \
	li_mini_libft2/ft_strncpy.c \
	li_mini_libft2/ft_strnew.c \
	li_mini_libft2/ft_strnisdigit.c \
	li_mini_libft2/ft_memalloc.c \
	li_mini_libft2/ft_lstlen.c \
	li_mini_libft2/ft_putendl.c \
	\
	ft_printf/ft_vdprintf.c \
	ft_printf/ft_vprintf.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_dprintf.c \
	ft_printf/pf_color.c \
	ft_printf/pf_buffering.c \
	ft_printf/pf_utilities.c \
	ft_printf/pf_unicode_handler.c \
	ft_printf/pf_get_attr.c \
	ft_printf/pf_numb_conv_tools.c \
	ft_printf/pf_casting.c \
	\
	ft_printf/pf_specifier/pf_convert_m.c \
	ft_printf/pf_specifier/pf_convert_big_m.c \
	ft_printf/pf_specifier/pf_convert_b.c \
	ft_printf/pf_specifier/pf_convert_c.c \
	ft_printf/pf_specifier/pf_convert_big_c.c \
	ft_printf/pf_specifier/pf_convert_d.c \
	ft_printf/pf_specifier/pf_convert_o.c \
	ft_printf/pf_specifier/pf_convert_p.c \
	ft_printf/pf_specifier/pf_convert_s.c \
	ft_printf/pf_specifier/pf_convert_big_s.c \
	ft_printf/pf_specifier/pf_convert_u.c \
	ft_printf/pf_specifier/pf_convert_v.c \
	ft_printf/pf_specifier/pf_convert_x.c \
	ft_printf/pf_specifier/pf_convert_y.c \
	ft_printf/pf_specifier/pf_convert_big_y.c \
	ft_printf/pf_specifier/pf_convert_n.c \
	ft_printf/pf_specifier/pf_convert_w.c \
	ft_printf/pf_specifier/pf_convert_big_w.c \
	ft_printf/pf_specifier/float/pf_convert_f.c \
	ft_printf/pf_specifier/float/pf_float_engine.c \
	ft_printf/pf_specifier/float/pf_float_integer_part.c \
	\
	ft_printf/pf_mini_libft/ft_dexp.c \
	ft_printf/pf_mini_libft/ft_get_dint_part.c \
	ft_printf/pf_mini_libft/ft_memcpy.c \
	ft_printf/pf_mini_libft/ft_memcmp.c \
	ft_printf/pf_mini_libft/ft_memset.c \
	ft_printf/pf_mini_libft/ft_strchr_zero.c \
	ft_printf/pf_mini_libft/ft_strnlen.c \
	ft_printf/pf_mini_libft/ft_strlen.c \
	ft_printf/pf_mini_libft/ft_get_nbr.c \
	ft_printf/pf_mini_libft/ft_strchr.c \
	ft_printf/pf_mini_libft/ft_isprint.c \
	ft_printf/pf_mini_libft/ft_isdigit.c


#################################################
###                   Format                  ###
#################################################

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJ =  $(notdir $(SRC:.c=.o))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

#################################################
###                   Rules                   ###
#################################################

.SILENT:
.PHONY: all clean fclean re

all: $(EXEC)

$(OBJS): $(SRCS)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) -I$(INC_DIR) $^
	mv -f $(OBJ) $(OBJ_DIR)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all
