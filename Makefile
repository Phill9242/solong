
# PATH VARIABLES
HEADERS_PATH = ./headers/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/

# COMPILATION
CC = gcc -Wall -Wextra -Werror -O3
CFLAGS = $(DEBUG) -I $(HEADERS_PATH)

# VALGRIND
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ./so_long map2.ber

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory
TOUCH = touch -a

# FILES
NAME = ./so_long
LIBFT_A = $(LIBS_PATH)libft.a

SRC_FILES = map_utils.c \
			map_utils2.c \
			so_long.c \
			movement_utils.c \
			img_utils.c \

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

# TARGETS
all: $(NAME)

# -> compiles libft all over
$(LIBFT_A):
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)

make_dir:
	@$(MKDIR) $(BINS_PATH)

# -> creates executable so_long inside ./bin/
$(NAME): $(LIBFT_A) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lmlx -lXext -lX11 -L $(LIBS_PATH) -lft

# -> creates object files for so_long
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

# -> mandatory flag for project submission
bonus: all

valgrind: $(NAME)
	@$(VALGRIND)

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@$(RM) $(OBJECTS)
	@$(MAKE_NOPRINT) clean -C $(LIBS_PATH)libft/

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_NOPRINT) fclean -C $(LIBS_PATH)libft/

# recompile all the files, deleting the previous ones->
re: fclean all

.PHONY: all run clean fclean re valgrind bonus make_dir
