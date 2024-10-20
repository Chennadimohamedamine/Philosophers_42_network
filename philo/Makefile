MANDATORY = philo.c philo_utils.c safe.c utils.c ph_utils.c util.c
OBGFILE_MAN = $(MANDATORY:%.c=%.o)
PROGRAM = philo

CFLAG = -Wall -Wextra -Werror -pthread -g

%.o: %.c philosopher.h
	cc $(CFLAG) -o $@ -c $<

$(PROGRAM): $(OBGFILE_MAN)
	cc $(OBGFILE_MAN) -o $(PROGRAM)

all : $(PROGRAM)

clean:
	rm -f $(OBGFILE_MAN)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re

