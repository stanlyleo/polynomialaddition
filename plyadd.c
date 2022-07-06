#include<stdio.h>
#include<stdlib.h>

struct node
	{
		int coe;
		int pow;
		struct node *next;
	};



void insert(int terms,struct node** head,struct node** tail)
{	
	int data1,data2,i;
	for(i=0;i<terms;i++)
	{	
		
		printf("Enter coefficient :");
		scanf("%d",&data1);
		printf("Enter power :");
		scanf("%d",&data2);
		
		if(*head==NULL)
		{	
			*head=(struct node*)malloc(sizeof(struct node));
			(*head)->pow=data2;
			(*head)->coe=data1;
			*tail=*head;
		}
		else
		{	
			(*tail)->next=(struct node*)malloc(sizeof(struct node));
			*tail=(*tail)->next;
			(*tail)->pow=data2;
			(*tail)->coe=data1;
		}
	}
}
	
void display(struct node** head)
{
	struct node *pos;
	pos=*head;
	if(*head==NULL)
	{
	printf("Empty list");
	}
	else
	{
		printf("\nElements are: ");
		while(pos!=NULL)
		{
			printf("\t%dx^%d",pos->coe,pos->pow);
			pos=pos->next;
		}
	}
}
			
void delete(struct node** pos,struct node** head1,struct node** tail1)
{
	struct node* del;
				
	del=*head1;			
	if(*pos==*head1)
	{
		*head1=(*head1)->next;

		del->next=NULL;
		free(del);
	}
	else if(*pos==*tail1)
	{
		while(del->next!=*tail1)
		{
			del=del->next;
		}
		*tail1=del;
		del=(*tail1)->next;
		(*tail1)->next=NULL;
		free(del);
	}
	else
	{
		while(del->next!=*pos)
		{
			del=del->next;
		}
		struct node *tem;
		tem=del->next;
		del->next=del->next->next;
		tem->next=NULL;
		free(tem);
	}
}

void addterm(struct node** head1,struct node** tail1, struct node** head3, struct node** tail3)
{
	struct node *pos,*temp,*del;
	int p,s;
	pos=*head1;
	do
	{
		temp=*head1;
		s=0;
		p=temp->pow;

		while(temp->next!=NULL)
		{
			if(temp->pow==p)
			{
				s=s+(temp->coe);
				del=temp;
				temp=temp->next;
				delete(&del,&(*head1),&(*tail1));
			}
			else
			{	
				temp=temp->next;
			}
		}
		pos=pos->next;
		if(*head3==NULL)
		{
			*head3=(struct node*)malloc(sizeof(struct node));
			(*head3)->pow=p;
			(*head3)->coe=s;
			*tail3=*head3;
		}
		else
		{
			(*tail3)->next=(struct node*)malloc(sizeof(struct node));
			*tail3=(*tail3)->next;
			(*tail3)->pow=p;
			(*tail3)->coe=s;
		}
	}while(pos!=NULL);	
}
						
void main()
{
	struct node *head1=NULL, *head2=NULL, *head3=NULL,*tail1=NULL,*tail2=NULL,*tail3=NULL,*pos,*temp,*del;
	int t1,t2,s,p;
	printf("first equation\nenter number of terms : ");
	scanf("%d",&t1);
	insert(t1,&head1,&tail1);
	printf("first equation:");
	display(&head1);
	printf("\nsecond equation\nenter number of terms : ");
	scanf("%d",&t2);
	insert(t2,&head2,&tail2);
	printf("\nsecond equation:");
	display(&head2);
	tail1->next=head2;
	tail1=tail2;
	tail1->next=(struct node*)malloc(sizeof(struct node));
	tail1=tail1->next;
	while(head1->coe!=0)
	{
		addterm(&head1,&tail1,&head3,&tail3);
	}
	printf("\n\nResult:");
	display(&head3);	
}
