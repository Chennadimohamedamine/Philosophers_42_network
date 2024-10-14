FILE = safe_bonus.c utils_bonus.c 
OBGFILE_MAN = $(FILE:%.c=%.o)
PROGRAM = philo_bonus

CFLAG = -Wall -Wextra -Werror

%.o: %.c philo_bonus.h
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