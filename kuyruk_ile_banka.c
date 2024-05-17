#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
  char isim[20];
  struct Node *nextNode;

};
//Havale işleminin başlangıcı ve bitişi
struct Node *havaleHeadNode=NULL,*havaleRearNode=NULL;
//Para Yatırma işleminin başlangıcı ve bitişi
struct Node *paraYatirmaHeadNode=NULL,*paraYatirmaRearNode=NULL;
//Para Çekme işleminin başlangıcı ve bitişi
struct Node *paraCekmeHeadNode=NULL,*paraCekmeRearNode=NULL;


void enqueue()
{
  struct Node *tmp;
  int secim;
  tmp=(struct Node*)malloc(sizeof(struct Node));//Yeni musteri icin yer alma
  if(tmp==NULL)//yer yok
  {
    printf("Yeterli alan yok\n");
    return;
  }
  printf("Isminiz: ");
  scanf("%s",&tmp->isim);
  tmp->nextNode=NULL;
  printf("\n1-Havale\n2-Para Yatirma\n3-Para cekme\nsecim yapiniz: ");
  scanf("%d",&secim);
  if(secim !=1 && secim != 2 && secim != 3)//Hatalı girdi
  {
    printf("Hatali secim\n");
    free(tmp);
    return;
  }

  if(secim==1)//Havale seçimi
  {
    if(havaleHeadNode==NULL)//Havale listesinde kimse yoksa başa ekle
    {
      havaleHeadNode=tmp;
      havaleHeadNode->nextNode=NULL;
      havaleRearNode=tmp;
      havaleRearNode->nextNode=NULL;
    }
    else//havale listesinin sonuna ekleme
    {
      havaleRearNode->nextNode=tmp;
      havaleRearNode=tmp;
      havaleRearNode->nextNode=NULL;
    }
  }
  else if(secim==2)//Para yatırma
  {
    if(paraYatirmaHeadNode==NULL)//Para yatırma listesi boşsa başa ekle
    {
      paraYatirmaHeadNode=tmp;
      paraYatirmaHeadNode->nextNode=NULL;
      paraYatirmaRearNode=tmp;
      paraYatirmaRearNode->nextNode=NULL;
    }
    else//sona ekle
    {
      paraYatirmaRearNode->nextNode=tmp;
      paraYatirmaRearNode=tmp;
      paraYatirmaRearNode->nextNode=NULL;
    }
  }
  else//Para çekme
  {
    if(paraCekmeHeadNode==NULL)// para çekme listesi boşsa başa ekle
    {
      paraCekmeHeadNode=tmp;
      paraCekmeHeadNode->nextNode=NULL;
      paraCekmeRearNode=tmp;
      paraCekmeRearNode->nextNode=NULL;
    }
    else// sona ekle
    {
      paraCekmeRearNode->nextNode=tmp;
      paraCekmeRearNode=tmp;
      paraCekmeRearNode->nextNode=NULL;
    }
  }
  //Liste bağlantıları(Havaleden sonra para yatırma, para yatırmadan sonra para çekme)
  if(paraYatirmaHeadNode!=NULL && havaleRearNode!=NULL) 
  havaleRearNode->nextNode=paraYatirmaHeadNode;
  else if(paraCekmeHeadNode!=NULL && havaleRearNode!=NULL) 
  havaleRearNode->nextNode=paraCekmeHeadNode;
  else if(havaleRearNode != NULL) 
  havaleRearNode->nextNode=NULL;

  if(paraCekmeHeadNode!=NULL && paraYatirmaRearNode !=NULL) 
  paraYatirmaRearNode->nextNode=paraCekmeHeadNode;
  else if(paraYatirmaRearNode != NULL) 
  paraYatirmaRearNode->nextNode=NULL;
}

void dequeue()
{
  if(havaleHeadNode == NULL && paraCekmeHeadNode == NULL && paraYatirmaHeadNode == NULL)
  {
    printf("Listede kimse yok\n");
    return;
  }
  struct Node *ptr;

  if(havaleHeadNode != NULL)
  {

    printf("Isim: %s\t",havaleHeadNode->isim);
    printf("Islem: Havale");
    if(havaleHeadNode->nextNode == havaleRearNode)
    {
      havaleRearNode=NULL;
    }
    ptr=havaleHeadNode;
    if(havaleHeadNode->nextNode==paraYatirmaHeadNode)
    {

      havaleHeadNode=NULL;
      havaleRearNode=NULL;
    }
    else
    {
      havaleHeadNode=havaleHeadNode->nextNode;
    }
    free(ptr);
  }
  else if(paraYatirmaHeadNode != NULL)
  {
    printf("Isim: %s\t",paraYatirmaHeadNode->isim);
    printf("Islem: Para Yatirma\n");
    if(paraYatirmaHeadNode->nextNode == paraYatirmaRearNode)
    {
      paraYatirmaHeadNode=NULL;
    }
    ptr=paraYatirmaHeadNode;
    if(paraYatirmaHeadNode->nextNode==paraCekmeHeadNode)
    {

      paraYatirmaHeadNode=NULL;
      paraYatirmaRearNode=NULL;
    }
    else
    {
      paraYatirmaHeadNode=paraYatirmaHeadNode->nextNode;
    }
    free(ptr);
  }
  else if(paraCekmeHeadNode != NULL)
  {
    printf("Isim: %s\t",paraCekmeHeadNode->isim);
    printf("Islem: Para Cekme");
    ptr=paraCekmeHeadNode;
    if(paraCekmeHeadNode->nextNode == paraCekmeRearNode)
    {
      paraCekmeHeadNode=NULL;
      paraCekmeRearNode=NULL;

    }
    paraCekmeHeadNode=paraCekmeHeadNode->nextNode;
    free(ptr);
  }
}

void Goster()
{
  if(havaleHeadNode == NULL && paraCekmeHeadNode == NULL && paraYatirmaHeadNode == NULL)
  {
    printf("Listede kimse yok\n");
    return;
  }
  struct Node *ptr;
  ptr=havaleHeadNode;
  while(ptr != paraYatirmaHeadNode && ptr !=NULL)
  {
    printf("Isim %s\t",ptr->isim);
    printf("Islem: Havale\n");
    ptr=ptr->nextNode;
  }
  ptr=paraYatirmaHeadNode;
  while(ptr != paraCekmeHeadNode && ptr !=NULL)
  {
    printf("Isim %s\t",ptr->isim);
    printf("Islem: Para Yatirma\n");
    ptr=ptr->nextNode;
  }
  ptr=paraCekmeHeadNode;
  while(ptr != NULL)
  {
    printf("Isim %s\t",ptr->isim);
    printf("Islem: Para Cekme\n");
    ptr=ptr->nextNode;
  }
}
int main() {
  while(1)
  {
    int secim;

    printf("\n1-Sira al\n2-Islem yap\n3-Goster\nSecim: ");
    scanf("%d",&secim);
    switch(secim)
    {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        Goster();
        break;
    }
    printf("\n");
    system("pause");
    system("cls");
  }
  return 0;
}
