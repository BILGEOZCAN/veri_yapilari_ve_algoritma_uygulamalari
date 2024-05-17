#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;	
};
struct Node *head=NULL,*tail=NULL;

void ekle()
{
  struct Node *tmp;
  //Yeni veri için bellekten yer aliyor
  tmp=(struct Node *)malloc(sizeof(struct Node));
  //yeterli alan var mi?
  if(tmp==NULL)
  {
    printf("Yetersiz bellek");
    return;
  }
  printf("Veriyi girin: ");
  scanf("%d",&tmp->data);
  tmp->next=NULL;
  //Liste bossa girilen veriyi en basa ekler
  if(head==NULL)
  {
    head=tmp;
    tail=tmp;
    head->next=tail;
    tail->next=head;
    return;
  }
  //liste bos degilse sona ekler
  tail->next=tmp;
  tail=tmp;
  tail->next=head;
}

void Goster()
{
  struct Node *tmp;
  //Liste bos mu
  if(head==NULL)
  {
    printf("Liste bos");
    return;
  }
  //liste bos degilse bastan baslayip tekrar basa gelene kadar verileri yazdirir.
  tmp=head;
  while(tmp->next!=head)
  {
    printf("%d\n",tmp->data);
    tmp=tmp->next;
  }
  printf("%d",tail->data);
}

void KonumaEkleme()
{
  int konum;
  int i=0;
  struct Node *tmp,*ptr;

  //Yeni veri için bellekten yer aliyor
  tmp=(struct Node *)malloc(sizeof(struct Node));
  //yeterli alan var mi
  if(tmp==NULL)
  {
    printf("Yetersiz bellek");
    return;
  }
  printf("Konumu girin: ");
  scanf("%d",&konum);

  printf("veriyi girin: ");
  scanf("%d",&tmp->data);
  tmp->next=NULL;


  if(konum==0)
  {
    // Eklenmek istenen konum 0'sa ve liste bossa en basa ekler ilk ve son veriyi eklenen veri yapar.
    if(head==NULL)
    {
      head=tmp;
      tail=tmp;
      head->next=tail;
      tail->next=head;
      return;
    }
    //liste bos degilse basa ekler ve listeyi 1 kaydirir.
    tmp->next=head;
    head=tmp;
    tail->next=head;
    return;
  }
  else if(head==NULL)
  {
    printf("Konum Bulunamadi");
  }
  else
  {
    //Eklenmek istenen konumdan 1 oncesini bulur
    for(i,ptr=head;i<konum-1;i++)
    {
      ptr=ptr->next;
      if(ptr==head)
      {
        printf("Konum Bulunamadi");
        return;
      }
    }
    //eklenmek istene yer son verinin oldugu yerse en sona ekler
    if(ptr->next==head)
    {
      tmp->next=head;
      ptr->next=tmp;
      tail=tmp;
      tail->next=head;
      return;

    }
    //degilse araya ekleme yapar
    tmp->next=ptr->next;
    ptr->next=tmp;

  }
}
void sil()
{
  struct Node *tmp,*ptr;
  if(head==NULL)
  {
    printf("Liste bos");
    return;
  }
  if(head==tail)//Listede 1 eleman varsa head ve taili bos yapar
  {
    printf("Silinen veri: %d",head->data);
    head=NULL;
    tail=NULL;
    return;
  }
  if(head->next==tail)//listede 2 eleman varsa head ve tail'i esitler
  {
    printf("Silinen veri: %d",tail->data);
    tail=tail->next;
    head->next=tail;
    tail->next=head;
    return;
  }
  ptr=head;
  while(ptr->next!=head)//Son elemani bulup siler ondan oncekini tail yapar
  {
    tmp=ptr;
    ptr=ptr->next;
  }
  tmp->next=head;
  tail=tmp;
  printf("Silinen veri: %d",ptr->data);
  free(ptr);
}

void konumdanSilme()
{
  if(head==NULL)
  {
    printf("Liste bos");
    return;
  }
  int konum;
  printf("Konumu girin: ");
  scanf("%d",&konum);
  if(konum==0)
  {
    //Silinmek istenilen konum 0 ve listede 1 eleman varsa head ve tail'i bos yapar
    if(head==tail)
    {
      printf("Silinen veri: %d\n",head->data);
      head=NULL;
      tail=NULL;
      return;
    }
    //ilk veriyi siler ondan sonrakini ilk veri yapar
    printf("Silinen veri: %d",head->data);
    head=head->next;
    tail->next=head;

  }
  else
  {
    struct Node *ptr,*tmp;
    ptr=head;
    int i=0;
        for(i=0;i<konum;i++) 
    { 
      tmp=ptr; ptr=ptr->next;
            if(ptr==head)
            {
                 printf("Konum bulunamadi");
                 return;
            }
        }
        tmp->next=ptr->next;
        if(ptr->next==head)
        {
            tail=tmp;
    }
        printf("Silinen Veri: %d",ptr->data);
        free(ptr);
  }
}

int main(int argc, char *argv[]) {
  while(1)
  {
    int secim;
    printf("\n1-ekle\n2-goster\n3-konuma ekle\n4-Sil\n5-Konumdan Silme\nsecim: ");
    scanf("%d",&secim);
    switch(secim)
    {
      case 1:
        ekle();
        break;
      case 2:
        Goster();
        break;
      case 3:
        KonumaEkleme();
        break;
      case 4:
        sil();
        break;
      case 5:
        konumdanSilme();
        break;
    }
    printf("\n");
    system("pause");

  }
  return 0;
}
