#include <stdio.h>
#include <string.h>
#include <limits.h>

#ifndef FIB_TEST
  #define FIB_TEST 0
#endif

#if FIB_TEST == 1
  extern char debugStr[];
  #define LOG_STRING(x) strcpy(&debugStr[0], x);
#else
  #define LOG_STRING(x)
#endif

int IsPrime( unsigned int n );

// computes fibonacci numbers, f_i, where i = 0..n
// if f_i is a multiple of 3, prints Fizz
// if f_i is a multiple of 5, prints Buzz
// if f_i is prime, prints BuzzFizz
// otherwise f_i is printed
// returns f_n
// NOTE 1: computes n+1 total fibonacci numbers
// NOTE 2: if f_i exceeds UINT_MAX, an error is printed and no further 
//         numbers in the sequence are printed
unsigned int F( const unsigned int n )
{
  char outputStr[64];
  unsigned int fib     = 0;
  unsigned int fibLast = 0;
  int fn1 = 1;
  int fn2 = 0;

  unsigned int i;
  for( i=0; i<=n; i++ )
  {
    if( i==0 )
    {
      fib = 0;
    }
    else if( i==1 )
    {
      fib = 1;
    }
    else
    {
      fib = fn1 + fn2;
      fn2 = fn1;
      fn1 = fib;
    }

    if( fibLast > fib )
    {
      printf("F(%u) exceeds max unsigned integer, %u.  Stopping...\n", 
             i, 
             UINT_MAX);
      return fibLast;
    }
    fibLast = fib;

    int strPos = 0;

    if( fib%3 == 0 )
    {
      strPos += sprintf(&outputStr[strPos], "Fizz");
    }

    if( fib%5 == 0 )
    {
      strPos += sprintf(&outputStr[strPos], "Buzz");
    }

    if( IsPrime(fib) )
    {
      strPos += sprintf(&outputStr[strPos], "BuzzFizz");
    }

    if(strPos == 0)
    {
      sprintf(outputStr, "%u\n", fib);
    }
    else
    {
      sprintf(&outputStr[strPos], "\n");
    }

    printf(outputStr);
  }
 
  LOG_STRING(outputStr);
  return fib;
}

// recursively computes fibonacci number f_n
// returns f_n
unsigned int FR( const unsigned int n )
{
  if(      n == 0 ) return 0;
  else if( n == 1 ) return 1;
  else return       FR(n-1) + FR(n-2);
}

int IsPrime( unsigned int n )
{
  if( n <= 1 ) return 0;

  int i;
  for(i=2; i<=n/2; i++)
  {
    if( n%i == 0 )
    {
      return 0;
    }
  }

  return 1;
}

#ifndef IS_MAIN
  #define IS_MAIN 0
#endif

#if IS_MAIN == 1
#include <stdlib.h>
int main( int argc, char ** argv )
{
  int n;
  if( argc > 1 )
  {
    n = strtol(argv[1], NULL, 10);
  }
  else
  {
    n = 20;
  }

  F(n);
  
  return 0;
}
#endif

