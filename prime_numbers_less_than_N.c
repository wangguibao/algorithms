/*
 * prime_numbers_less_than_N.c
 * Get all prime numbers less than N.
 * The most efficient way: Sieve of Eratosthenes
 * (http://primes.utm.edu/glossary/page.php?sort=SieveOfEratosthenes)
 *
 * Author: Wang Guibao (wang_guibao#163.com)
 */
 #include <stdio.h>
 #include <math.h>
 #define LIMIT  100000

 int main()
 {
     int prime[LIMIT + 1];
     int i;
     int j;

     for (i = 2; i <= LIMIT; i++) {
         prime[i] = 1;
     }

     for (i = 2; i * i <= LIMIT; i++) {
         if (prime[i] == 0) {
             continue;
         }
         for (j = i * i ; j <= LIMIT; j += i) {
             prime[j] = 0;
         }
     }

     for (i = 2; i <= LIMIT; i++) {
         if (prime[i] == 1) {
             printf("%d\n", i);
         }
     }

     return 0;
 }
