CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11 -g3
NAME = logger
SRCS = main.cpp src/ConsoleLogger.cpp src/FileLogger.cpp
INCLUDE_PATH = -Isrc -Iinclude

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.cpp=.o)))

VALID = \033[1;32m
NOTVALID = \033[1;31m
LOADING = \033[1;33m
INFOS = \033[1;36m
RESET = \033[0m

VPATH = src:src

all: $(NAME)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE_PATH) -MMD -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(INCLUDE_PATH) -o $(NAME)

clean:
	rm -f $(OBJ) obj/*/*.d obj/*.d

fclean: clean
	rm -rf $(NAME) .cache

re: fclean all

listC:
	@LIST=$$(find -wholename "./src/*.cpp" | cut -c 3- | tr '\n' ' '); \
	printf "🗅 $(INFOS)copy all CPP sources files into clipboard :\n$(RESET)$$LIST\n"; \
	echo -n $$LIST | wl-copy

-include $(OBJ:.o=.d)
