#include <stdio.h>
#include <stdlib.h>

int Queue[20];
int queueIndex = 0; // Kuyrukta bulunan veri sayısını tutuyor

void enqueue(int data)// kuyruğa veri ekleme
{
  if(queueIndex == 19) // Kuyruk doldu mu
  {
    printf("Kuyruk dolu\n");
    return;
  }
  Queue[queueIndex++] = data; // kuyruğa ekleme yap
}

void dequeue()// kuyruktaki ilk veriyi gösterip silme
{
  if(queueIndex == 0)
  {
    printf("Kuyruk bos\n");
    return;
  }
  printf("%d\n", Queue[0]);// ilk veriyi göster
  int i;
  for(i = 0; i < queueIndex - 1; i++)// diziyi 1 adım sola kaydır
  {
    Queue[i] = Queue[i + 1];
  }
  queueIndex--;// son indexi tut
}

void front()// İlk veriyi silmeden gösterir
{
  if(queueIndex == 0)
  {
    printf("Kuyruk bos\n");
    return;
  }
  printf("%d\n", Queue[0]);// ilk veriyi göster
}

void size()// Kuyruk boyutunu gösterir
{
  if(queueIndex == 0)
  {
    printf("Kuyruk bos\n");
    return;
  }
  printf("Size: %d\n", queueIndex);
}

int main() {
  while(1)
  {
    int choice;
    int data;
    printf("\n1-Enqueue(Kuyruga eleman ekleme)\n2-Dequeue(Cikarma)\n3-Front(Gosterme)\n4-Size(Eleman Sayisi)\nSecim: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
        printf("Veriyi girin: ");
        scanf("%d", &data);
        enqueue(data);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        front();
        break;
      case 4:
        size();
        break;
      default:
        printf("Geçersiz seçim\n");
        break;
    }
    printf("\n");
    system("pause");
    system("cls");

  }
  return 0;
}
