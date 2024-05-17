#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int data;
  struct Queue *nextNode;
};
struct Queue *headNode=NULL; //ilk verinin adresi
struct Queue *rearNode=NULL; //son verinin adresi

void enqueue(int data)//veri ekleme
{
  struct Queue *tmp;
  tmp=(struct Queue *)malloc(sizeof(struct Queue));//Yeni veri için bellekten yer isteniyor
  if(tmp==NULL)//bellekte yer yok
  {
    printf("Yetersiz bellek\n");
    return;
  }
  tmp->data=data;
  if(headNode==NULL)//Kuyruk boşsa başa ekle
  {
    headNode=tmp;
    rearNode=tmp;
    rearNode->nextNode=NULL;
    return;
  }
  rearNode->nextNode=tmp;// sona ekleme
  rearNode=tmp;
  rearNode->nextNode=NULL;
}

void dequeue()//ilk veriyi gösterip silme
{
  struct Queue *ptr;
  if(headNode == NULL)
  {
    printf("Kuyruk bos\n");
    return;
  }
  printf("%d\n",headNode->data);
  if(headNode->nextNode==rearNode)//Listede 1 eleman varsa son veriyi sıfırlar
  {
    rearNode=NULL;
  }
  ptr=headNode;
  headNode=headNode->nextNode;//2.veriyi başa alma
  free(ptr);//ilk veriyi silme
}

void front() // ilk veriyi silmeden gösterir
{
  if(headNode == NULL)
  {
    printf("Kuyruk bos\n");
    return;
  }
  printf("%d\n",headNode->data);
}

void size()
{
  int size=0;
  struct Queue *ptr;
  ptr=headNode;
  if(headNode==NULL)
  {
    printf("Kuyruk bos\n");
    return;
  }
  while(ptr!=NULL) // son veriye gelene kadar döner
  {
    size++;
    ptr=ptr->nextNode;
  }
  printf("Size: %d\n",size);
}

int main() {
    while(1)
  {
    int secim;
    int data;
    printf("\n1-Enqueue\n2-Dequeue\n3-Front\n4-Size\nSecim: ");
    scanf("%d",&secim);
    switch(secim)
    {
      case 1:
        printf("Veriyi girin: ");
        scanf("%d",&data);
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

    }
    printf("\n");
    system("pause");
    system("cls");

  }
  return 0;
}
