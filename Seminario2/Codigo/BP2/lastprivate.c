/**
 * @file firstlastprivate.c
 */

 #include <stdio.h>
 #ifdef _OPENMP
    #include <omp.h>
 #else
    #define omp_get_thread_num() 0
 #endif

 int main() {
   int i, n = 3;
   //int i, n= 10;
   int a[n], suma=0;

   for (i=0; i<n; i++)
   a[i] = i+1;

   #pragma omp parallel for lastprivate(suma)
   for (i=0; i<n; i++)
   {
      suma = a[i];
      printf(" thread %d suma=%d \n", omp_get_thread_num(),suma);
   }

   printf("\nFuera de la construcción parallel suma=%d\n",suma);
 }
