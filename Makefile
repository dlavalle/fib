SRCS_MAIN = ./fib.c

SYMS_MAIN = -DIS_MAIN=1

SRCS_TEST  = ./fib.c
SRCS_TEST += ./tests.c

SYMS_TEST  = -DFIB_TEST=1

MAIN = fib

TEST = tests

all: 
	gcc -Wall $(SRCS_MAIN) $(SYMS_MAIN) -o $(MAIN).elf
	gcc -Wall $(SRCS_TEST) $(SYMS_TEST) -o $(TEST).elf
	
$(MAIN):
	gcc -Wall $(SRCS_MAIN) $(SYMS_MAIN) -o $(MAIN).elf

$(TEST):
	gcc -Wall $(SRCS_TEST) $(SYMS_TEST) -o $(TEST).elf

clean:
	rm -f $(MAIN).elf
	rm -f $(TEST).elf

