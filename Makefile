norm:
	norminette days_c  && make main && ./a.out
d600:
d601:
d602:
d603:
d604:

main:
	gcc  days_c/00/*/*.c days_c/01/*/*.c days_c/02/*/*.c days_c/03/*/*.c days_c/04/*/*.c days_c/05/*/*.c  main.c -std=gnu99 -Wall -Wextra -Werror && make d600 && make d601 && make d602 && make d603 && make d604
mainall:
	make main && ./a.out all
watch:
	./watch-tests.sh
