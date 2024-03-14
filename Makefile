CC				= cc
AR				= ar rc
CFLAGS			= -Wall -Wextra -Werror
NAME			= ./build/libft.a
RM				= rm -vf
SRC_DIR			= ./src/
BUILD_DIR		= ./build/

SRC_FILES := $(wildcard $(SRC_DIR)*.c)

OBJECT_FILES	= \
				$(SOURCE_FILES:%.c=$(BUILD_DIR)%.o)

all: ${NAME}



${NAME}: ${OBJECT_FILES}
	@${AR} $@ $?

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJECT_FILES}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
