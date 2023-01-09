//Code for Circular linked list
#include<stdio.h>
#include<conio.h>
#include<String.h>
#include<malloc.h>
#define MAX 100

struct studinfo{
	int index;
	int marks;
	char name[MAX];
	struct studinfo *next;
}*start;
void create_LinkedList();//Function for create a LINKEDLIST and store node as end of linklist as much as we want
void insert_at_FirstNode();//during the execution, if we want to add NODE at starting of the LINKEDLIST 
void insert_at_EndNode();//and if we want to add NODE at last or Ending of the LINKEDLIST
void insert_at_After_Node_By_Name();//if we want to add NODE to The next of any particular NODE that we want
void insert_at_Before_Node_By_Name();//if we want to add NODE to The previous of any particular NODE that we want
void insert_at_After_Node_By_Index();//we can add any NODE after our choosed NODE by using INDEX to identified NODE
void insert_at_Before_Node_By_Index();//we can add any NODE before our choosed NODE by using INDEX to identified NODE
void delete_from_Start();//If we want to delete a NODE from starting of the LINKEDLIST
void delete_from_End();//If we want to delete a NODE from Ending point of the LINKEDLISt
void delete_Node_from_Anywhere_By_Name();//We can delete any NODE from this LINKEDLIST by USING STUDENT NAME
void delete_Node_from_Anywhere_By_Index();//If we Know the INDEX of any NODE in this LINKEDLIST then we can delete NODE by USING INDEX
void traverse();//This function will return remain full LINKEDLIST to us
//These some variable decalared as Gloable variable
struct studinfo *newnode, *ptr, *store, *last;
char ch;
//we declare main function, every task will be operate from here
main()
{
	int c;
	start=NULL;
	 
	//do-while loop run till we take a choice as 13
	//it will be exit when we choose 13
	do{
		printf("\n\n\t+--------------------------------------------------------------------------------------------------------+");
		printf("\n\t|                               >>>Enter choice for linklist operations<<<                               |");
		printf("\n\t|                                                                                                        |");
		printf("\n\t| 1. For create linklist...                       | 8.  DELETE NODE from Strating point.                 |");
		printf("\n\t| 2. For Insert NODE at First..                   | 9.  DELETE NODE from End of the LINKLIST.            |");
		printf("\n\t| 3. For Insert NODE at last..                    | 10. DELETE NODE BY NAME from LINKLIST.               |");
		printf("\n\t| 4. For Insert NODE at After any NODE By NAME    | 11. DELETE NODE BY INDEX from LINKLIST.              |");
		printf("\n\t| 5. For Insert NODE at Before any NODE By NAME   |------------------------------------------------------+");
		printf("\n\t| 6. For Insert NODE at After any NODE By INDEX   | 12. For Traverse LINKEDLIST..                        |");
		printf("\n\t| 7. For Insert NODE at Before any NODE By INDEX  | 13. FOR EXIT...                                      |");
		printf("\n\t+-------------------------------------------------+------------------------------------------------------+");
		printf("\n\nEnter a choice that you want to do..= ");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:create_LinkedList();break;
			
			case 2:insert_at_FirstNode();break;
					
			case 3:insert_at_EndNode(); break;
			
			case 4:insert_at_After_Node_By_Name();break;
		
			case 5:insert_at_Before_Node_By_Name();break;
			
			case 6: insert_at_After_Node_By_Index();break;
			
			case 7: insert_at_Before_Node_By_Index();break;
			
			case 8:delete_from_Start();break;
			
			case 9:delete_from_End();break;
			
			case 10:delete_Node_from_Anywhere_By_Name();break;
			
			case 11:delete_Node_from_Anywhere_By_Index();break;
			
			case 12: traverse();break;
			
			case 13: printf("\n\n\t......Hope you enjoy it.....");break;
			
			default: printf("\n\nPlease Enter right choice: ");
			
		}
	}while(c!=13);
	
}
//@create_LinkedList() function will create a LINKLIST and add NODE next to next continuesly
void create_LinkedList()
{
	do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		
		if(start == NULL)
		{
		start = newnode;
		newnode->index=1;
		newnode->next=start;
		last=newnode;
		
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}
		else
		{
			
			ptr=last;
			ptr->next=newnode;
			newnode->next=start;
			last=newnode;
				
			
			
			newnode->index=ptr->index+1;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");		
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
	
}
//End of the @create_LinkedList() function
//@insert_at_FirstNode function will add new NODE at First NODE or Front of the LINKLIST
void insert_at_FirstNode()
{
		
	
	do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		
		if(start == NULL)
		{
		start = newnode;
		newnode->index=1;
		newnode->next=start;
		last=newnode;
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}else
		{
			
			ptr=start;
			start = newnode;
			newnode->next = ptr;
			newnode->index=1;
			last->next=start;
			while(ptr->next!=start)
			{
				ptr->index+=1;
				ptr=ptr->next;
			}
			ptr->index+=1;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
		
	}
//End of the @insert_at_FirtNode
//@insert_at_EndNode funtion will be add new NODE at end of linklist
void insert_at_EndNode()
{
	
	
		do{
		newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
		printf("\nEnter a new record: marks and name = ");
		scanf("%d%s",&newnode -> marks,newnode->name);
		newnode -> next = NULL;
		
		if(start == NULL)
		{
		start = newnode;
		newnode->index=1;
		newnode->next=start;
		last=newnode;
		
		printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
		}
		else
		{
			
			ptr=last;
			ptr->next=newnode;
			newnode->next=start;
			last=newnode;
				
			
			
			newnode->index=ptr->index+1;
			printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");		
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
	}
//End of the @insert_at_EndNode
//@insert_at_After_Node_By_Name funtion will be add new NODE in somewhere between of linklist
void insert_at_After_Node_By_Name()
{
	
	
	
	char C_name[MAX];
do{
		printf("\n\nInsert Previous NODE name where you want to store next new NODE: ");
		scanf("%s",&C_name);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			int a = strcmp(ptr->name,C_name);
		
			//start = newnode;
			while(a!=0 && ptr->next!=start)
			{
				ptr = ptr->next;
				a = strcmp(ptr->name,C_name);
			}
			
			if(a==0)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				newnode->next = ptr->next;
				ptr->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=start)
				{
					ptr=ptr->next;
					ptr->index+=1;
				}
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
				return;
			}
			
			
			printf("\n\t>>>>>>There is no available NODE to this name: %s \n",C_name);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
	
}
//End of the @insert_at_After_Node_By_Name() function
//@insert_at_Before_Node_By_Name() will add an NODE before NODE which we want
void insert_at_Before_Node_By_Name()
{
		char C_name[MAX];
do{
		printf("\n\nInsert NEXT NODE name where you want to store new NODE: ");
		scanf("%s",&C_name);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			store=NULL;
			int a = strcmp(ptr->name,C_name);
		
			//start = newnode;
			while(a!=0 && ptr->next!=start)
			{
				store = ptr;
				ptr = ptr->next;
				a = strcmp(ptr->name,C_name);
			}
			
			if(a==0)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				if(store==NULL)
				{
					newnode->next=start;
					start=newnode;
					newnode->index=ptr->index;
					while(ptr->next!=start)
					{
						ptr->index+=1;
						ptr=ptr->next;
					}
					ptr->index+=1;
					printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
					return;
				}
				newnode->next = store->next;
				store->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=start)
				{
					ptr->index+=1;
					ptr=ptr->next;
				}
				ptr->index+=1;
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
				return;
			}
			
			printf("\n\t>>>>>>There is no available NODE to this name: %s \n",C_name);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
}
//End of the @insert_at_Before_Node_By_Name() function
//@insert_at_After_Node_By_Index() will add an NODE before NODE which we want
void insert_at_After_Node_By_Index()
{
	
	
	int ind;
do{
		printf("\n\nInsert Previous NODE INDEX where you want to store next new NODE: ");
		scanf("%d",&ind);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			
		
			//start = newnode;
			while(ptr->index!=ind && ptr->next!=start)
			{
				ptr = ptr->next;
				
			}
			
			if(ptr->index==ind)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				newnode->next = ptr->next;
				ptr->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=start)
				{
					ptr=ptr->next;
					ptr->index+=1;
				}
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");

				return;
			}
			
			
			printf("\n\t>>>>>>There is no available NODE to this INDEX: %d \n",ind);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
}
//End of the @insert_at_After_Node_By_Index() function
//@insert_at_Before_Node_By_Index() will add an NODE before NODE which we want
void insert_at_Before_Node_By_Index()
{
		int ind;
do{
		printf("\n\nInsert NEXT NODE INDEX where you want to store new NODE: ");
		scanf("%d",&ind);
		
		
		if(start == NULL)
		{
		printf("\n>>>>>>Empty LIST! Atleast Enter One NODE<<<<<<");
		
		}else
		{
			ptr = start;
			
		
			//start = newnode;
			while(ptr->index!=ind && ptr->next!=start)
			{
				store = ptr;
				ptr = ptr->next;
				
			}
			
			if(ptr->index==ind)
			{
				newnode = (struct studinfo *)malloc(sizeof(struct studinfo));
				printf("\nEnter a new record: marks and name = ");
				scanf("%d%s",&newnode -> marks,newnode->name);
				if(ptr->index==1)
				{
					newnode->next=start;
					start=newnode;
					newnode->index=ptr->index;
					while(ptr->next!=start)
					{
						ptr->index+=1;
						ptr=ptr->next;
					}
					ptr->index+=1;
					printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
					return;
				}
				newnode->next = store->next;
				store->next=newnode;
				newnode->index=ptr->index;
				while(ptr->next!=start)
				{
					ptr->index+=1;
					ptr=ptr->next;
				}
				ptr->index+=1;
				printf("\n\n\t>>>>>>>>>>>Successfully INSERT One NODE<<<<<<<<<<<\n");
				return;
			}
			
			printf("\n\t>>>>>>There is no available NODE to this INDEX: %d \n",ind);
			}
			fflush(stdin);
			printf("\nDo you want to continue (y/n) = ");
			scanf("%C",&ch);
		}while(ch=='y' || ch == 'Y');
}
//End of the @insert_at_Before_Node_By_Index() function
//@delete_from_Start() will be delete a NODE from Starting point
void delete_from_Start()
{
	if(start==NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	
	 
	ptr = start;
	if(ptr==last)
	{
		start=NULL;
		printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
		printf("\n\n\t\t****NOW!! list is empty***");
		return;
	}
	ptr = ptr->next;
	start = ptr;
	printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
	int i=2;
	while(i<=last->index)
	{
		ptr->index-=1;
		ptr=ptr->next;
		i++;
		
	}
	
}
//End of the @delete_from_Start()
//@delete_from_End() Function will delete one NODE from the end of the LINKLIST
void delete_from_End()
{
	
	 
	ptr =start;
	if(start==NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	if(ptr==last)
	{
		start=NULL;
		printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
		printf("\n\n\t\t****NOW!! list is empty***");
		return;

	}
	
		int i = 1;
		while(i<last->index-1)
		{
			ptr = ptr->next;
			i++;
		}
		ptr->next = start;
		last=ptr;
		printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");

	
}
//End of the @delete_from_End()
//@delete_Node_from_Anywhere_By_Name() Function ask us that write a name of the NODE which you want to DELETE
void delete_Node_from_Anywhere_By_Name()
{
	char S_name[MAX];
	printf("\nWrite NAME of the STUDENT that you want to delete from LINKLIST: ");
	scanf("%s",&S_name);
	
	if(start == NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	else
	{
		 
		ptr = start;
		int a = strcmp(ptr->name,S_name);
		if(a==0)
		{
			if(ptr->next==start)
			{
				
				start=NULL;
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			store = ptr->next;
			start = store;
			
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			while(store->next!=start)
			{
				store->index-=1;
				store=store->next;
			}
			store->index-=1;
			return;		
		}
		while(a!=0 && ptr->next != start)
		{
			store = ptr;
			ptr = ptr->next;
			a = strcmp(ptr->name,S_name);
			
		}
		if(a==0)
		{
			if(ptr->next==start)
			{
				store->next=start;
				last=store;
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			store->next=ptr->next;
		
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			while(ptr->next!=start)
			{
				ptr->index-=1;
				ptr=ptr->next;
			}
			ptr->index-=1;
			return;
		}
		printf("\n\t>>>>>>There is no available NODE to this name: %s \n",S_name);
		
	
			
	}
	
}
//End of @delete_Node_from_Anywhere_By_Name()
//@delete_Node_from_Anywhere_By_Index() Function ask us that write a name of the NODE which you want to DELETE
void delete_Node_from_Anywhere_By_Index()
{
	int ind;
	printf("\nWrite INDEX of the NODE that you want to delete from LINKLIST: ");
	scanf("%d",&ind);
	
	if(start == NULL)
	{
		printf("\n\n\t\t**** list is empty***");
		return;
	}
	else
	{
		 
		ptr = start;
		
		if(ptr->index==ind)
		{
			if(ptr->next==start)
			{
				start=NULL;
				printf("this is");
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			store = ptr->next;
			start = store;
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			while(store->next!=start)
			{
				store->index-=1;
				store=store->next;
			}
			store->index-=1;
			return;		
		}
	
		while(ptr->index!=ind && ptr->next != start)
		{
			store = ptr;
			ptr = ptr->next;	
		}
		if(ptr->index==ind)
		{
			if(ptr->next==start)
			{
				store->next = start;
				last=store;
				printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
				return;
			}
			store->next=ptr->next;
			printf("\n\n\t>>>>>>>>>>>Successfully Delete One NODE<<<<<<<<<<<\n");
			
			while(ptr->next!=start)
			{
				ptr->index-=1;
				ptr=ptr->next;
			}
			ptr->index-=1;
			return;
		}
		printf("\n\t>>>>>>There is no available NODE to this INDEX: %d \n",ind);
		
	
			
	}
}
//End of @delete_Node_from_Anywhere_By_Index()
//Created function to traverse the each node of the linked list
	void traverse()
	{
		struct studinfo *ptr;
		if(start == NULL)
		{
			printf("\n\n\t\t**** list is empty***");
			return;
		}
		
		store = start;
		printf("\n\t*-----------------------------------------*\n");
		while(store->next!=start)
		{
			store=store->next;
		}
		ptr = start;
		int i=1;
		while(i<=last->index)
		{
			printf("\t|Record: INDEX: %d, MARKS: %d and NAME: %s\n",ptr->index,ptr -> marks,ptr->name);
			ptr = ptr->next;
			i++;
		}
		printf("\t*-----------------------------------------*\n\n\t>>>>>>>>>>>Press Enter to Continue<<<<<<<<<<<");

		getch();
	}
//End of the @traverse function
	
