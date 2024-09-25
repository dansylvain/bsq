NAME = bsq

CC = gcc
CFLAGS = -g -Iinc #-Wall -Wextra -Werror

SRC_DIR = src
LIB = src/lib
OBJS_DIR = objs

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/bsq.c \
		$(SRC_DIR)/extract_mapdata.c \
		$(SRC_DIR)/display.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/gnl.c \
		$(SRC_DIR)/gnl_utils.c \
		$(SRC_DIR)/map_validity_check.c \
		$(LIB)/ft_memset.c \
		$(LIB)/ft_split.c \
		$(LIB)/ft_calloc.c \
		$(LIB)/ft_strdup.c \
		$(LIB)/ft_strlen.c \
		$(LIB)/ft_isdigit.c \
		$(LIB)/ft_strcmp.c \
		$(LIB)/ft_strlcpy.c \
		$(LIB)/ft_atoi.c \
		$(LIB)/ft_strlcat.c \
		$(LIB)/ft_itoa.c 	

OBJS = $(SRC:%.c=$(OBJS_DIR)/%.o)

DESIGN_MARKER = .design_running

INCLUDES = -I incs

all: $(NAME)

$(DESIGN_MARKER):
	clear
	@bash src/generateGradient.sh
	@touch $(DESIGN_MARKER)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(DESIGN_MARKER) $(OBJS) 
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) 
	@echo "$(NAME) compiled !"

clean:
	@rm -rf $(OBJS_DIR) toto
	@echo "obj files cleaned."

fclean: clean
	@rm -f $(NAME) $(DESIGN_MARKER)
	@echo "all files cleaned."

re: fclean all

.PHONY: all clean fclean re
