#include <stdio.h>
#include <stdlib.h>

int recursiveFactorial(int n)
{
  if (n == 1) 
    return 1;
  else 
    return(n*recursiveFactorial(n-1));
}

int main() {
  int sayi;
  printf("Faktoriyeli hesaplanacak sayiyi giriniz: ");
  scanf("%d",&sayi);
  printf("%d! = %d",sayi,recursiveFactorial(sayi));
  return 0;
}
