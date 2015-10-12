#General

Computes the Fibonacci sequence F(0) .. F(n)

Prints "Fizz" when the Fibonacci number in the sequence is a multiple of 3

Prints "Buzz" when the Fibonacci number in the sequence is a multiple of 5

Prints "BuzzFizz" when the Fibonacci number in the sequence is a prime

Prints the Fibonacci number in the sequence when the number is not a multiple
of 3, is not a multiple of 5 and is not prime

#Running the application

    ./fib.elf 

  calls F(20)

    ./fib.elf n 

  calls F(n), n should be an integer

#Building the application

    make fib

  generates the file `fib.elf`

#Building the tests

    make tests

  generates the file `tests.elf`

#Running the tests

    ./tests.elf 

  Checks the output of F(0), F(1), ..., F(30)

#Source

* fib.c: implements the application
* tests.c: implements tests for the function F(n)

