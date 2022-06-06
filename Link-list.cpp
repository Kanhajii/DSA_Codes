#include <stdio.h>
#include <cstdlib>
struct node 
{
	int data;
	struct node *add;
};

struct node *start=NULL, *temp, *New, *next, *prev;

void create();
void insert();
void Delete();
void display();

int main()
{
	int ch;
	
	do
	{
		printf("\n ------------------Link List------------------");
		printf("\nPress 1 for Create operation\n");
		printf("Press 2 for insert operation\n");
		printf("Press 3 for Delete operation\n");
		printf("Press 4 for display operation\n");
		printf("Press 5 for Exit operation\n");
		
		printf("Enter your Choice:-");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:create();break;
			case 2:insert();break;
			case 3:Delete();break;
			case 4:display();break;
			default:printf("Invalid choice");
		}
	}
	while(ch<5);
}

void create()
{
	int n;
	char ch;
	printf("Enter a value:-");
	scanf("%d",&n);
	
	start = (struct node*)malloc(sizeof(struct node));
	
	start->data=n;
	start->add=NULL;
	temp = start;
	
	printf("To add more element press y:-");
	scanf(" %c",&ch);
	
	while(ch=='Y' || ch=='y')
	{
		printf("Enter a value:- ");
		scanf("%d",&n);
		
		New = (struct node*)malloc(sizeof(struct node));
		
		New->data=n;
		New->add=NULL;
		temp->add=New;
		temp=New;
		
		printf("To add more element press y:-");
		scanf(" %c",&ch);
	}
}

void insert()
{
	if(start==NULL)
	{
		printf("List not created create a list first");
	}
	else
	{
	
	int n, pos, count=0, i=1;
	
	printf("Enter a value:- ");
	scanf("%d",&n);
	
	New = (struct node*)malloc(sizeof(struct node));
	
	New->data=n;
	New->add=NULL;
	
	printf("Enter a position:- ");
	scanf("%d",&pos);
	
	if(pos==1)
	{
		New->add=start;
		New = start;
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			count++;
			temp=temp->add;
		}
		
		if(pos>count+1)
		{
			printf("Invalid position pls enter valid position < %d ",count+1);
		}
		else if(pos==count+1)
		{
			temp=start;
			while(temp->add!=NULL)
			{
				temp=temp->add;
			}
			temp->add=New;
		}
		else
		{
			next=start;
			while(i<pos)
			{
				prev=next;
				next=next->add;
				i++;
			}
			prev->add=New;
			New->add=next;
		}
	}
}
}
void Delete()
{
	int pos, count=0, i=1;
	
	printf("Enter a position:- ");
	scanf("%d",&pos);
	
	if(pos==1)
	{
		temp=start;
		start=start->add;
		printf("Deleted data = %d",temp->data);
		free(temp);
		
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			count++;
			temp=temp->add;
		}
		
		if(pos>count)
		{
			printf("Invalid positoin pls enter < = %d",count);
		}
		
		else if(pos==count)
		{
			next=start;
			while(next->add!=NULL)
			{
				prev=next;
				next=next->add;
			}
			prev->add=NULL;
			printf("Deleted data = %d ",next->data);
			free(next);
			
		}
		else
		{
			next=start;
			while(i<pos)
			{
				prev=next;
				next=next->add;
			}
			temp=next;
			next=next->add;
			printf("Deleted data is %d",temp->data);
			free(temp);
			prev->add=next;
			
		}
	}
}

void display()
{
	if(start==NULL)
	{
		printf("List not created create a list first");
	}
	else
	{
		temp = start;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->add;
		}
		printf("\n");
	}
}


