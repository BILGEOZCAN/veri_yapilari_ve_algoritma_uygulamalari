#include <stdio.h>
#include <stdlib.h>

struct node
	{
		int data;
		struct node *next;
	
	};
	struct node *Start = NULL;
	
void BasaEkleme()
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	
	if(tmp == NULL)
	{
		printf("Yetersiz Bellek");
		return;
	}
	
	printf("Veriyi girin: ");
	scanf("%d", &tmp->data);
	
	tmp->next = NULL;
	
	if(Start == NULL)
	{
		Start = tmp;
	}
	else
	{
		tmp->next = Start;
		Start=tmp;
	}
}

void SonaEkleme()
{
	struct node *tmp, *ptr;
	tmp = (struct node*)malloc(sizeof(struct node));
	
	if(tmp == NULL)
	{
		printf("Yetersiz Bellek");
		return;
	}
	
	printf("Veriyi girin: ");
	scanf("%d", &tmp->data);
	
	tmp->next = NULL;
	
	if(Start == NULL)
	{
		Start = tmp;
	}
	else
	{
		ptr = Start;
		
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = tmp;
	}
}

void BastanSilme()
{
	struct node *ptr;
	
	if(Start == NULL)
	{
		printf("Liste Bos");
	}
	else
	{
		printf("Silinen veri: %d", Start->data);
		ptr = Start;
		Start->next=Start;
		free(ptr);
	}
}

void SondanSilme()
{
	struct node *ptr, *tmp;
	
	if(Start == NULL)
	{
		printf("Liste Bos");
	}
	else if(Start->next == NULL)
	{
		printf("Silinen veri: %d", Start->data);
		free(Start);
		Start=NULL;
	}
	else
	{
		ptr = Start;
		
		while(ptr->next != NULL)
		{
			tmp = ptr;
			ptr = ptr->next;
		}
		tmp->next=NULL;
		printf("Silinen veri: %d", ptr->data);
		free(ptr);
	}
}

void Goster()
{
	struct node *ptr;
	if(Start == NULL)
	{
		printf("Liste Bos");
		return;
	}
	ptr = Start;
	while(ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
}

int main(int argc, char** argv) 
	{
		BasaEkleme();
		SonaEkleme();
		Goster();
		return 0;
	}
