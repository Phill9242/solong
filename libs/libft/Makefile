# PATH VARIABLES
HEADERS_PATH = ../../headers/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ../

# COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p

# FILES
LIBNAME = libft.a
SRC_FILES =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_get_next_line.c \
			ft_get_next_line_utils.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstmap.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \

SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

# TARGETS
all: prep $(LIBNAME)

prep:
	@$(MKDIR) $(SRCS_PATH) $(OBJS_PATH)

$(LIBNAME): $(OBJECTS)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(CC) $(FLAGS) -c -I $(HEADERS_PATH) $< -o $@

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(LIBS_PATH)$(LIBNAME)

re: fclean all

.PHONY:	all clean fclean re
