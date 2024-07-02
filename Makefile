MANDATORY = philo/philo.c philo/philo_utils.c \
			philo/check_utils.c  philo/utils.c 
 
OBG_MAN = $(MANDATORY:%.c=%.o)
PROGRAM = philo_

CFLAG = -Wall -Wextra -Werror  -g -pthread

philo/%.o: philo/%.c philo/philosopher.h
	cc $(CFLAG) -o $@ -c $<

$(PROGRAM): $(OBG_MAN)
	cc $(OBG_MAN) -o $(PROGRAM)

all : $(PROGRAM)

clean:
	rm -f $(OBG_MAN)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re