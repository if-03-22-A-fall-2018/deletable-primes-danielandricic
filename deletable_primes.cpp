#include "deletable_primes.h"
#include <math.h>

/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 14
 * Title:			deletable_primes.c
 * Author:			D. Andricic
 * Due Date:		25.Februar 2019
 * ----------------------------------------------------------
 */

   unsigned long remove_digit(int index, unsigned long n)
   {
      long numPow = pow(10, index);
      unsigned long num;
      num = n / (numPow * 10) * numPow + (n % numPow);
      return num;
   }

   bool is_prime(unsigned long p)
   {
     if (p <= 1 || (p % 2 == 0 && p > 2))
     {
       return false;
     }

     for(int i = 3; i <= sqrt(p); i += 2)
     {
       if (p % i == 0)
       {
         return false;
       }
     }
     return true;
   }

   // Counter für das Iterieren.
 int get_length(unsigned long n)
 {
     int count=0;
     while (n > 1)
     {
       n /= 10;
       count++;
     }
     return count;
 }

 // Methode, die alle Möglichkeiten für die Ermittlung von Primzahlen ausprobiert.
 int get_ways(unsigned long p)
 {
   if(p < 10 && is_prime(p))
   {
     return 1;
   }
   else if(p < 10 && !is_prime(p))
   {
     return 0;
   }

   int countways = 0;
   for (int i = 0; i < get_length(p); i++)
   {
     if(is_prime(remove_digit(i, p)))
     {
       countways += get_ways(remove_digit(i,p));
     }
   }
   return countways;
  }
