#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_TEST 30

unsigned int F( const unsigned int n );
unsigned int FR( const unsigned int n );
int IsPrime( unsigned int n );

char debugStr[32];

// tests F(n) on the input 0..MAX_TEST
int main( int argc, char ** argv )
{
  printf("Testing F(0..%d)\n", MAX_TEST);

  unsigned int f;
  unsigned int fr;

  char tmpStr[32];

  unsigned int i;
  for( i=0; i<=MAX_TEST; i++ )
  {
    f  = F(i);
    fr = FR(i);
    assert(f == fr);
    int bPrime = IsPrime(f);
    if( f%3 == 0 && f%5 == 0)
    {
      assert( strcmp( debugStr, "FizzBuzz\n" ) == 0 );
    }
    else if( f%3 == 0 && bPrime )
    {
      assert( f == 3 );
      assert( strcmp( debugStr, "FizzBuzzFizz\n" ) == 0 );
    }
    else if( f%3 == 0 )
    {
      assert( strcmp( debugStr, "Fizz\n" ) == 0 );
    }
    else if( f%5 == 0 && bPrime )
    {
      assert( f == 5 );
      assert( strcmp( debugStr, "BuzzBuzzFizz\n" ) == 0 );
    }
    else if( f%5 == 0 )
    {
      assert( strcmp( debugStr, "Buzz\n" ) == 0 );
    }
    else if( bPrime )
    {
      assert( strcmp( debugStr, "BuzzFizz\n" ) == 0 );
    }
    else
    {
      sprintf(tmpStr, "%u\n", f);
      assert( strcmp( debugStr, tmpStr ) == 0 );
    }
    
    i++;
  }
  printf("Test F(n), n=0..%d, PASSED\n", MAX_TEST);

  return 0;
}

