#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int roll;
	long  prn,m;
	char name[20],e[20],add[30];
	struct node *next;
}*first=NULL,*last=NULL,*t;
int ct=1;
void create()
{
	int i,n;
	printf("Enter the number of records you wish to input\n");
	scanf("%d",&n);
	first=(struct node *)malloc(sizeof(struct node));
	printf("Enter the Roll Number, PRN ,Name ,Mobile Number ,E-mail id and Address of student respectively:\n");
	scanf("%d\n",&first->roll);
	scanf("%ld\n",&first->prn);
	gets(first->name);
	scanf("%ld\n",&first->m);
	gets(first->e);
	gets(first->add);
	first->next=NULL;
	last=first;
	for(i=1;i<n;i++)
	{
		ct++;
		t=(struct node *)malloc(sizeof(struct node));
		printf("Enter the Roll Number, PRN ,Name ,Mobile Number ,E-mail id and Address of student respectively:\n");		
		scanf("%d\n",&t->roll);
		scanf("%ld\n",&t->prn); 
		gets(t->name);
		scanf("%ld\n",&t->m);
		gets(t->e);
		gets(t->add);
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
int insert()
{
	int i,j;
	struct node *new_node,*p=first;
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter the Roll Number, PRN ,Name ,Mobile Number ,E-mail id and Address of student respectively:\n");
	scanf("%ld\n",&new_node->prn); 
	gets(new_node->name);
	scanf("%ld\n",&new_node->m);
	gets(new_node->e);
	gets(new_node->add);
	printf("Enter the index after which you want to insert a new record:\n");
	scanf("%d",&i);
	if(p!=NULL)
	{
		if(i==0)
		{
			ct++;
			new_node->next=p;
			p=new_node;
			first=p;
		}
		else if(i>0&&i<=ct)
		{
			ct++; 
			for(j=0;j<i-1;j++)
			{
				p=p->next;
			}
			new_node->next=p->next;
			p->next=new_node;
		}
		else
		{
			printf("Not in the size of list.\n");
			return 0;
		}
	}
	else
	{
		new_node->next=NULL;
		first=p=new_node;
		return 0;
	}
	return 0; 
}
int delete1()
{
	struct node *p=first,*t;
	int r;
	printf("Enter the Roll Number of student you wish to delete from the record\n");
	scanf("%d",&r);
	if(first->roll==r)
	{
		if(first->next!=NULL)
		{
			first=first->next;
		}
		else
		{ 
			printf("The list is empty\n");
			first=NULL;
		}
	} 
	else
	{
		while(p->roll!=r)
		{
			t=p;
			p=p->next;
		}
		t->next=p->next; 
		free(p);
	}
	return 0;
}
void search()
{ 
	int r,f=0;
	printf("Enter the Roll Number of student you wish to search in the record\n");
	scanf("%d",&r);
	struct node *p=first;
	while(p!=NULL)
	{
		if(p->roll==r)
		{
			printf("Element is present in the list\n");
			p=p->next;
			f=1;
			break;
		}
		else
		{
			p=p->next;
		}
	}
	if(f==0)
	{
		printf("Element is not present in the list\n");
	}
}
void modify()
{
	struct node *p=first;
	int i,j;
	printf("Enter the index of record you want to modify\n");
	scanf("%d",&i);
	for(j=0;j<i-1;j++)
	{
		p=p->next;
	}
	printf("Enter the new Roll Number, PRN ,Name ,Mobile Number ,E-mail id and Address of student respectively:\n");
	scanf("%d\n",&p->roll);
	scanf("%ld\n",&p->prn); 
	gets(p->name);
	scanf("%ld\n",&p->m);
	gets(p->e);
	gets(p->add);
}
int display()
{
	struct node *d;
	d=first;
	if(first==NULL)
	{
		printf("The list is empty.\n");
	}
	while(d!=NULL)
	{
		printf("%d\t%ld\t%s\t%ld\t%s\t%s\t\n",d->roll,d->prn,d->name,d->m,d->e,d->add);
		d=d->next;
	}
	return 0;
}
int main()
{
	int c;
	create();
	do
	{
		printf("1. To display the list.\n");
		printf("2. To insert a new record in the list.\n");
		printf("3. To delete a record from the list.\n");
		printf("4. To search a record in the list.\n");
		printf("5. To modify a record in the list.\n");
		printf("6. To exit.\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				display();
				break;
			}
			case 2:
			{
				insert();
				break;
			}
			case 3:
			{
				delete1();
				break;
			}
			case 4:
			{
				search();
				break;
			}
			case 5:
			{
				modify();
				break;
			}
			case 6:  
			{
				exit(0);
				break;
			}
			default:
				printf("Wrong input.\n");
		}
	}
	while(1);
	return 0;
}
