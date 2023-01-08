#include<stdio.h>
#include<conio.h>
#include<String.h>
#include<malloc.h>

struct studinfo
{
	int id;
	char std_Name[100];
	int marks;
	struct studinfo *previous, *next;
}*start;

void create_list()
{
	char ch;
	do 
	{
		
		struct studinfo *newnode,*ptr;
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\n\nEnter Student NAME : ");
		scanf("%s",newnode->std_Name);
		printf("Enter MARKS : ");
		scanf("%d",&newnode->marks);
		newnode->previous = NULL;
		newnode->next=NULL;
		if(start==NULL)
		{
			newnode->id=1;
			start = newnode;
			printf("\n\n\t\t---> successfully insert one node <---");
			
		}
		else
		{
		ptr = start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		newnode->id = ptr->id+1; 
		ptr->next=newnode;
		newnode->previous = ptr;
			printf("\n\n\t\t---> successfully insert one node <---");
		}
		fflush(stdin);
		printf("\n\nDo you want to insert more element(y/n) = ");
		scanf("%c",&ch);
	
	}while(ch=='y' || ch=='Y');
}
void add_Node_at_starting_point()
{
	char ch;

	do 
	{
		if(start==NULL)
			printf("\n\t\tERROR!! ->> First create LINKEDLIST");
		else
		{
		struct studinfo *newnode,*ptr;
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\n\nEnter Student NAME : ");
		scanf("%s",&newnode->std_Name);
		printf("Enter MARKS : ");
		scanf("%d",&newnode->marks);
		newnode->previous = NULL;
		ptr = start;
		start = newnode;
		newnode->id = 1; 
		ptr->previous=newnode;
		newnode->next = ptr;
		while(ptr!=NULL)
		{
			ptr->id+=1;
			ptr=ptr->next;
		}
		printf("\n\n\t\t---> successfully insert one node <---");
		}
		fflush(stdin);
		printf("\n\nDo you want to insert more element(y/n) = ");
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
}
void add_Node_at_Ending_point()
{
	char ch;

	do 
	{
		if(start==NULL)
			printf("\n\t\tERROR!! ->> First create LINKEDLIST");
		else
		{
			struct studinfo *newnode,*ptr;
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\n\nEnter Student NAME : ");
		scanf("%s",&newnode->std_Name);
		printf("Enter MARKS : ");
		scanf("%d",&newnode->marks);
		newnode->next=NULL;
		ptr = start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		newnode->id = ptr->id+1; 
		ptr->next=newnode;
		newnode->previous = ptr;
		
		printf("\n\n\t\t---> successfully insert one node <---");
		}
		fflush(stdin);
		printf("\n\nDo you want to insert more element(y/n) = ");
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
}
void add_Node_Before_Any_NODE()
{
	char ch;
	int F_ID;

	do 
	{
		struct studinfo *newnode,*ptr,*store;
		
		
		if(start==NULL)
			printf("\n\t\tERROR!! ->> First create LINKEDLIST");
		else
		{
			printf("\n\nEnter ID of NODE where you want to store newnode before that NODE : ");
			scanf("%d",&F_ID);
			ptr = start;
			while(ptr->id!=F_ID && ptr->next!=NULL)
				ptr=ptr->next;
			if(ptr->id!=F_ID && ptr->next==NULL)
				printf("\n\tThere is NO ID available to this NUMBER : %d\n\n",F_ID);
			else
			{
				struct studinfo *newnode,*ptr;
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\n\nEnter Student NAME : ");
				scanf("%s",&newnode->std_Name);
				printf("Enter MARKS : ");
				scanf("%d",&newnode->marks);
				ptr=start;
				if(ptr->next==NULL)
				{
					newnode->id=1;
					newnode->next=ptr;
					newnode->previous=NULL;
					ptr->previous=newnode;
					ptr->id=2;
				}
				else
				{
					if(ptr->id==F_ID)
					{
						newnode->id=1;
						newnode->next=ptr;
						ptr->previous=newnode;
						start=newnode;
						while(ptr!=NULL)
						{
							ptr->id+=1;
							ptr=ptr->next;
						}
					}
					else
					{
						while(ptr->id!=F_ID)
						{
							store = ptr;
							ptr=ptr->next;
						}
						newnode->id = store->id+1; 
						store->next=newnode;
						newnode->previous = store;
						newnode->next=ptr;
						ptr->previous=newnode;
						while(ptr!=NULL)
						{
							ptr->id+=1;
							ptr=ptr->next;
						}
					}
				}	
			}
		printf("\n\n\t\t---> successfully insert one node <---");
		}
		
		fflush(stdin);
		printf("\n\nDo you want to insert more element(y/n) = ");
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
}
void add_Node_After_Any_NODE()
{
	
	char ch;
	int F_ID;

	do 
	{
		struct studinfo *newnode,*ptr,*store;
		
	
		if(start==NULL)
			printf("\n\t\tERROR!! ->> First create LINKEDLIST");
		else
		{
			printf("\n\nEnter ID of NODE where you want to store newnode before that NODE : ");
			scanf("%d",&F_ID);
			ptr = start;
			while(ptr->id!=F_ID && ptr->next!=NULL)
				ptr=ptr->next;
			if(ptr->id!=F_ID && ptr->next==NULL)
				printf("\n\tThere is NO ID available to this NUMBER : %d\n\n",F_ID);
			else
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\n\nEnter Student NAME : ");
				scanf("%s",&newnode->std_Name);
				printf("Enter MARKS : ");
				scanf("%d",&newnode->marks);
				ptr=start;
				if(ptr->next==NULL)
				{
					newnode->id=2;
					newnode->next=NULL;
					ptr->next=newnode;
					newnode->previous=ptr;
				}
				else
				{
					if(ptr->id==F_ID)
					{
						newnode->id=2;
						ptr->next=newnode;
						newnode->previous=ptr;
						ptr=ptr->next;
						newnode->next=ptr;
						ptr->previous=newnode;
						while(ptr!=NULL)
						{
							ptr->id+=1;
							ptr=ptr->next;
						}
					}
					else
					{
						while(ptr->id!=F_ID)
							ptr=ptr->next;
						store = ptr;
						ptr=ptr->next;
						newnode->id = store->id+1; 
						store->next=newnode;
						newnode->previous = store;
						newnode->next=ptr;
						ptr->previous=newnode;
						while(ptr!=NULL)
						{
							ptr->id+=1;
							ptr=ptr->next;
						}
					}
				}	
			}
		printf("\n\n\t\t---> successfully insert one node <---");
		}
		
		fflush(stdin);
		printf("\n\nDo you want to insert more element(y/n) = ");
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
}
void Delete_NODE_from_Starting_Point()
{
	struct studinfo *ptr;
	if(start==NULL)
		printf("\n\n\t\t>>>>>>Doubly LinkedList is empty.<<<<<<");
	else
	{	ptr=start;
		if(ptr->next==NULL)
		{
			start=NULL;
		printf("\n\n\t\t---> successfully delete one node <---");
		}

		else
		{
			ptr=ptr->next;
			ptr->previous=NULL;
			start=ptr;
			while(ptr!=NULL)
			{
				ptr->id-=1;
				ptr=ptr->next;
			}
		printf("\n\n\t\t---> successfully delete one node <---");
		}
	}
}
void Delete_NODE_from_Ending_Point()
{
	struct studinfo *ptr,*store;
	if(start==NULL)
		printf("\n\n\t\t>>>>>>Doubly LinkedList is empty.<<<<<<");
	else
	{	ptr=start;
		if(ptr->next==NULL)
		{
			start=NULL;
		printf("\n\n\t\t---> successfully delete one node <---");
		}

		else
		{
			while(ptr->next!=NULL)
				ptr=ptr->next;
			store=ptr->previous;
			store->next=NULL;			
		printf("\n\n\t\t---> successfully delete one node <---");
		}
	}
}
void Delete_Any_NODE_BY_ID()
{
	struct studinfo *ptr,*store;
	int F_ID;	

	if(start==NULL)
		printf("\n\t\tERROR!! ->> First create LINKEDLIST");
	else
	{
		printf("\nEnter ID of NODE which one you want to DELETE from Linkedlist : ");
		scanf("%d",&F_ID);
		ptr = start;
		while(ptr->id!=F_ID && ptr->next!=NULL)
			ptr=ptr->next;
		if(ptr->id!=F_ID && ptr->next==NULL)
			printf("\n\tThere is NO ID available to this NUMBER : %d\n\n",F_ID);
		else
		{
			ptr=start;
			if(ptr->next==NULL)
				start=NULL;
			
			else
			{
				if(ptr->id==F_ID)
				{
					ptr=ptr->next;
					ptr->previous=NULL;
					start=ptr;
					while(ptr!=NULL)
					{
						ptr->id-=1;
						ptr=ptr->next;
					}
				}
				
				else
				{
					while(ptr->id!=F_ID)
						ptr=ptr->next;
					store = ptr->previous;
					if(ptr->next==NULL)
						store->next=NULL;
					else
					{
						ptr=ptr->next;
						store->next=ptr;
						ptr->previous=store;
						while(ptr!=NULL)
						{
							ptr->id-=1;
							ptr=ptr->next;
						}
					}
				}
			}
		printf("\n\n\t\t---> successfully delete one node <---");
		}
	}
}
void searching(){
	struct studinfo *ptr;
	int node_id;
	printf("\nEnter ID of node that you want to search : ");
	scanf("%d",&node_id);
	ptr=start;
	while(ptr->next!=NULL)
	{
		if(ptr->id==node_id)
		{
			printf("\n\tFound!!");
			return;
		}
		ptr=ptr->next;
		
	}
	if(ptr->next==NULL)
	printf("\nNot found!!");
	
}
void forward_traversing()
{
	struct studinfo *ptr;
	ptr = start;
	if(start==NULL)
	{
		printf("\n\n\t\t>>>>>>Doubly LinkedList is empty.<<<<<<");
		return;
	}
	
	while(ptr!=NULL)
	{
		printf("| %d.) NAME : %s , MARKS :%d |\n",ptr->id,ptr->std_Name,ptr->marks);
		ptr=ptr->next;
	}
	
	
}
void backward_traversing()
{
	struct studinfo *ptr;
	ptr = start;
	if(start==NULL)
	{
		printf("\n\n\t\t>>>>>>Doubly LinkedList is empty.<<<<<<");
		return;
	}
	
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	while(ptr!=NULL)
	{
		
		printf("| %d.) NAME : %s , MARKS :%d |\n",ptr->id,ptr->std_Name,ptr->marks);
		ptr=ptr->previous;
	}
}
main()
{
	start=NULL;
	int choice;
	do
	{
		
		printf("\n\n\t+--------------------------------------------------------------------------------------------------------+");
		printf("\n\t|                         >>>Enter choice for DOUBLY LINKEDLIST operations<<<                            |");
		printf("\n\t+--------------------------------------------------------------------------------------------------------+");
		printf("\n\t+-------------------------------------------------+------------------------------------------------------+");
		printf("\n\t| 1. For create DOUBLY LINKEDLIST...              |                                                      |");
		printf("\n\t| 2. For Insert NODE at First..                   | 6.  DELETE NODE from Strating point.                 |");
		printf("\n\t| 3. For Insert NODE at last..                    | 7.  DELETE NODE from End of the LINKLIST.            |");
		printf("\n\t| 4. For Insert NODE at BEFORE any NODE By ID	  | 8.  DELETE NODE BY INDEX from LINKLIST.              |");
		printf("\n\t| 5. For Insert NODE at AFTER any NODE By ID	  |                                                      |");
		printf("\n\t+-------------------------------------------------+-------------------------+-----------------------+----+");
		printf("\n\t| 9. For FORWARD Traverse of LINKEDLIST..         | 11. For Searching NODE  | Click 0 for restore   |    |");
		printf("\n\t| 10.For BACKWARD Traverse of LINKEDLIST..        | 12. For Exit PROGRAM    | One Last DELETED NODE |    |");
		printf("\n\t+-------------------------------------------------+-------------------------+-----------------------+----+");
		
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create_list();break;
			case 2:add_Node_at_starting_point();break;
			case 3:add_Node_at_Ending_point();break;
			case 4:add_Node_Before_Any_NODE();break;
			case 5:add_Node_After_Any_NODE();break;
			case 6:Delete_NODE_from_Starting_Point();break;
			case 7:Delete_NODE_from_Ending_Point();break;
			case 8:Delete_Any_NODE_BY_ID();break;
			case 9:forward_traversing();break;
			case 10:backward_traversing();break;
			case 11:searching();break;
			case 12:printf("\n\n\t\t>>>>>Hope you enjoy it..<<<<<");break;
			default : printf("\n\n\t\t>>>>Enter right choice please<<<<");
		}
		
	}while(choice!=12);
}