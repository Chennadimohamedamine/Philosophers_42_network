FILE = main_bonus.c process_bonus.c utils_bonus.c parc_bonus.c process_utils.c
OBGFILE_BONUS = $(FILE:%.c=%.o)
PROGRAM = philo_bonus

CFLAG = -Wall -Wextra -Werror

%.o: %.c philo_bonus.h
	cc $(CFLAG) -o $@ -c $<

$(PROGRAM): $(OBGFILE_BONUS)
	cc $(OBGFILE_BONUS) -o $(PROGRAM)

all : $(PROGRAM)

clean:
	rm -f $(OBGFILE_BONUS)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re