#include <stdio.h>
#include <stdlib.h>

int Pow(int alt,int ust)
{
  if(ust==0) 
    return 1;
  else if(ust==1) 
    return alt;
  int araSonuc;
  araSonuc=Pow(alt,ust-1);
  return araSonuc*alt;
}

int main() {
  int sayi;
  int us;
  int sonuc;
  printf("Sayiyi giriniz: ");
  scanf("%d",&sayi);
  printf("ussu giriniz: ");
  scanf("%d",&us);
  sonuc = Pow(sayi,us);
  printf("%d ^ %d = %d",sayi,us,sonuc);
  return 0;
}
