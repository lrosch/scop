CC:= g++

NAME:= scop

CFLAGS+= -Wall -Werror -Wextra -std=c++98

LIBRARIES = .\libraries\libglfw3.a .\libraries\libglad.a -lgdi32

LINK+= $(LIBRARIES)

HEADER += .\include

SRC= $(addprefix src/, main.cpp callback.cpp utils.cpp object.cpp)

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC) -I $(HEADER) $(LIBRARIES)
	@printf "\n		successfully compiled \n\n"

all: $(NAME)

silence:
	@:

clean:
	@find . -type f -name '*.o' -delete

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all

delete: 
	rm -f $(NAME)

.PHONY: clean fclean re