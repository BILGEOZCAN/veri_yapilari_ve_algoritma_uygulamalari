#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
	struct Node *previous;
};
struct Node *head=NULL;
struct Node *tail=NULL;

void ekle()
{
	struct Node *tmp;
	//Yeni veri icin bellekten yer alindi
	tmp=(struct Node*)malloc(sizeof(struct Node));
	//Bellekte yer var mi
	if(tmp==NULL)
	{
		printf("Yetersiz bellek");
		return;
	}
	printf("Veriyi girin: ");
	scanf("%d",&tmp->data);
	tmp->next=NULL;
	tmp->previous=NULL;
	if(head==NULL) // Liste bossa veriyi en basa ekledi
	{
		head=tmp;
		tail=tmp;
		head->next=tail;
		head->previous=tail;
		tail->next=head;
		tail->previous=head;
		return;
	}
	//Veriyi en sona ekledi
	tail->next=tmp;
	tmp->previous=tail;
	tail=tmp;
	tail->next=head;
	head->previous=tail;
}

void Goster()
{
	if(head==NULL)//Liste bos mu
	{
		printf("Liste bos");
		return;
	}
	//Bastan baslayip tekrar basa gelene kadar butun verileri ekranda gosterir
	struct Node *tmp;
	tmp=head;
	while(tmp->next!=head)
	{
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}
	printf("%d\n",tmp->data);
}
void TerstenGoster()
{
	if(head==NULL)
	{
		printf("Liste bos");
		return;
	}
	//Sondan baslayip tekrar sona gelene kadar verileri ekranda gosterir
	struct Node *tmp;
	tmp=tail;
	while(tmp->previous!=tail)
	{
		printf("%d\n",tmp->data);
		tmp=tmp->previous;
	}
	printf("%d\n",tmp->data);
}


void Sil()
{
	if(head==NULL)
	{
		printf("Liste bos");
		return;
	}
	//Listede 1 veri varsa head ve taili sifirladi
	if(head->next==head)
	{
		printf("Silinen veri: %d\n",head->data);
		head=NULL;
		tail=NULL;
		return;
	}
	//Son veriyi silip ondan oncekini son yapti
	struct Node *ptr;
	ptr=tail;
	tail=tail->previous;
	tail->next=head;
	head->previous=tail;
	printf("Silinen veri: %d\n",ptr->data);
	free(ptr);
	
}
void KonumaEkleme()
{
	struct Node *tmp;
	//Yeni veri icin bellekten yer aldi
	tmp=(struct Node*)malloc(sizeof(struct Node));
	if(tmp==NULL)
	{
		printf("Yetersiz bellek");
		return;
	}
	int konum;
	printf("Konumu girin: ");
	scanf("%d",&konum);
	printf("Veriyi girin: ");
	scanf("%d",&tmp->data);
	if(konum==0)
	{
		if(head==NULL) // konum 0 ve liste bossa basa ekledi
		{
			head=tmp;
			tail=tmp;
			head->next=tail;
			head->previous=tail;
			tail->next=head;
			tail->previous=head;
			return;
		}
		//basa ekledi ve listeyi kaydirdi
		head->previous=tmp;
		tmp->next=head;
		head=tmp;
		head->previous=tail;
		tail->next=head;
	}
	else if(head==NULL)//konum 0 degil ve liste bossa hata verir
	{
		printf("Konum bulunamadi");
	}
	else
	{
		struct Node *ptr;
		ptr=head;
		int i;
		//Girilen konumdan 1 oncekini buldu
		for(i=0;i<konum-1;i++)
		{
			ptr=ptr->next;
			if(ptr==head)
			{
				printf("Konum bulunamadi");
				return;
			}
		}
		if(ptr->next==head)//konum son verinin oldugu yerse sona ekledi
		{
			
			tail->next=tmp;
			tmp->previous=tail;
			tail=tmp;
			tail->next=head;
			head->previous=tail;
			return;
		}
		// araya ekleme islemi yapti
		tmp->next=ptr->next;
		ptr->next->previous=tmp;
		ptr->next=tmp;
		tmp->previous=ptr;
	}
}
void KonumdanSilme()
{
	struct Node *tmp,*ptr;
	int i,konum;
	if(head==NULL)
	{
		printf("Liste Bos");
		return;
	}
    else
    {
    	printf("Konumu girin: ");
        scanf("%d",&konum);
        if(konum==0)
        {
        	
            printf("Silinen Veri: %d",head->data);
            if(head->next==head)//konum 0 ve listede 1 eleman varsa head ve tail'i sifirladi
            {
                head=NULL;
                tail=NULL;
                return;
			}
			//ilk veriyi sildi ondan sonrakini ilk veri yapti
			head=head->next;
			head->previous=tail;
			tail->next=head;         
    	}
        else
        {
            ptr=head;
            //istenilen konuma kadar arama yapti
            for(i=0;i<konum;i++) 
			{ 
				tmp=ptr; ptr=ptr->next;
                if(ptr==head) // basa donduyse hata verdi
                {
                    printf("Konum bulunamadi");
                    return;
                }
            }
            tmp->next=ptr->next;
            if(ptr->next==head)//Konum son veriyse son veriyi sildi
            {
                tail=tmp;
                tail->next=head;
                head->previous=tail;
			}
			else
			{
				//aradan silme islemi yapti
				ptr->next->previous=tmp;
			}
            printf("Silinen Veri: %d",ptr->data);
            free(ptr);
    	}
    }
}
int main(int argc, char *argv[]) {
	while(1)
	{
		int secim;
		printf("\n1-Ekle\n2-Goster\n3-Tersten Goster\n4-Sil\n5-Konuma Ekleme\n6-Konumdan Silme\nSecim yapiniz: ");
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
				TerstenGoster();
				break;
			case 4:
				Sil();
				break;
			case 5:
				KonumaEkleme();
				break;
			case 6:
				KonumdanSilme();
				break;
		}
		printf("\n");
		system("pause");
	}
	return 0;
}
