#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

// singly Linear linked list 
void InsertFirstSL(PPNODE Head,int no)
{
	PNODE newn=NULL;
	newn= (PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;

	if(*Head== NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->next=*Head;
		*Head=newn;
	}
}
void InsertLastSL(PPNODE Head,int no)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;

	if(*Head== NULL)
	{
		*Head=newn;
	}
	else
	{
		while(temp->next!= NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}
int Count(PNODE Head)
{
	int iCnt=0;
	while(Head != NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}
void InsertAtPosSL(PPNODE Head, int no,int pos)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	int size=0,i=0;

	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;

	size=Count(*Head);
	if(*Head == NULL)
	{
		*Head=newn;
	}
	if(pos == 1)
	{
		InsertFirstSL(Head,no);
	}
	else if(pos == size+1)
	{
		InsertLastSL(Head,no);
	}
	else
	{	
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=	temp->next;
		temp->next=newn;
	}
}
void DeleteFirstSL(PPNODE Head)
{
	PNODE First=NULL;
	PNODE temp=*Head;

	if(*Head == NULL)
	{
		printf("No element in list\n");
		return;
	}
	else
	{	
		*Head=(*Head)->next;
		free(temp);
	}
}
void DeleteLastSL(PPNODE Head)
{
	PNODE temp=*Head;
	PNODE Temp2=NULL;

	if(*Head == NULL)
	{
		return;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp=temp->next;
		}
		Temp2= temp->next->next;
		printf("%d\n",Temp2 );
		temp->next=NULL;
		free(Temp2);
		printf("%d\n",Temp2 );
	}
}
void DeleteAtPosSL(PPNODE Head,int pos)
{
	PNODE temp= *Head;
	PNODE temp2=NULL;
	int no=0,i=0,size=0;

	size=Count(*Head);
	if(*Head ==  NULL)
	{
		return;
	}
	if(pos==1)
	{
		DeleteFirstSL(Head);
	}
	else if(pos== size)
	{	
		DeleteLastSL(Head);
	}
	else
	{
		for(i=1;i< pos-1;i++)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		no=temp2->data;
		temp->next=temp->next->next;
		free(temp2);

		printf("Deleted node %d\n",no );
	}
}//end of Singly Linked list All Operation 

// Doubly Linked List
void InsertFirstDL(PPNODE Head, int no)
{
	PNODE newn= NULL;
	newn =(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;

	if(*Head== NULL)
	{
		*Head= newn;
		newn->next=NULL;
		newn->prev=NULL;
	}
	else
	{
		newn->next=*Head;
		*Head=newn;
	}
}
void InsertLastDL(PPNODE Head,int no)
{
	PNODE newn=NULL;
	PNODE temp=*Head;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->next=temp;
		newn->next=NULL;
	}
}

void InsertAtPosDL(PPNODE Head,int no,int pos)
{	
	PNODE newn=NULL;
	PNODE temp=*Head;
	int size=0,i=0;

	size=Count(*Head);

	if(*Head== NULL)
	{
		InsertFirstDL(Head,no);
	}
	else if(pos == size+1)
	{
		InsertLastDL(Head,no);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;

		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
	}
}

int DeleteFirstDL(PPNODE Head)
	{
		int iResult=0;	
	if(*Head == NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	else
	{	
		PNODE temp=*Head;
		*Head=(*Head)->next;
		iResult=temp->data;
		free(temp);
	}
	return iResult;
}

int DeleteLastDL(PPNODE Head)
{
	int iResult=0;
	PNODE temp=*Head;
	PNODE temp2=NULL;
	if(*Head ==NULL)
	{
		printf("Linked LIst is empty\n");
		return -1;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=NULL;
		iResult=temp2->data;
		free(temp2);
	}
	return iResult;
}

int DeleteAtPosDL(PPNODE Head,int pos)
{
	PNODE temp=*Head;
	PNODE temp2=NULL;
	int size=0,i=0,iResult=0;
	size=Count(*Head);
	if(*Head == NULL)
	{
		printf("Error: No element in list\n");
		return -1;
	}
	if(pos ==1)
	{
		DeleteFirstDL(Head);
	}
	else if(pos ==size)
	{
		DeleteLastDL(Head);
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=temp->next->next;
		iResult=temp2->data;
		free(temp2);

	}
	return iResult;
}  // End Of Doubly Linked List

void InsertFirstSC()




void Display(PNODE Head)
{
 while(Head != NULL)
 {
 	printf("%d ->",Head->data );
 	Head=Head->next;
 }
 printf("NULL\n");
}

 int main()
{
	PNODE First=NULL;
	int choice=1,choice2=1,no=0,pos=0,iRet=0;
	while(choice != 0)
	{
		printf("\nChoose the any operation of linked list\n");
		printf("1: Singly linear Linked List\n");
		printf("2: Singly circular linked list\n");
		printf("3: Doubly linear linked list\n");
		//printf("4: Doubly circular linked list\n");
		printf("0: Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:   //Singly Linear Linked List
		while(choice2 != 0)
			{
			printf("\n------------------------------------------------------------------\n");
			printf("Select any for singly linear linked List operation\n");
			printf("1: Insert First\n");
			printf("2: Insert last\n");
			printf("3: Insert At pos\n");
			printf("4: Delete First\n");
			printf("5: Delete last\n");
			printf("6: Deletet At pos\n");
			printf("7: Display List\n");
			printf("8: Count list Element\n");
			printf("0: Exit  \n");

			printf("Enter The choice\n" );
			scanf("%d",&choice2);
		
			switch(choice2)
			{
				case 1:
				printf("Enter Number to add\n");
				scanf("%d",&no);
				InsertFirstSL(&First,no);
				break;

				case 2:
					printf("Enter number to add At last position\n");
					scanf("%d",&no);
					InsertLastSL(&First,no);
				break;

				case 3:
					printf("Enter number to add At position\n");
					scanf("%d",&no);
					printf("Enter The possition\n");
					scanf("%d",&pos);
					InsertAtPosSL(&First,no,pos);
				break;

				case 4:
					printf("Delete first element\n");
					DeleteFirstSL(&First);
				break;

				case 5:
					printf("Delete last element\n");
					DeleteLastSL(&First);
					break;
				case 6:
					printf("enter position\n");
					scanf("%d",&pos);
					DeleteAtPosSL(&First,pos);
					break;

				case 7:
				Display(First);
				break;

				case 8:
					iRet=Count(First);
					printf("total number of element in list : %d\n",iRet);
				break;
				default:
					printf("Invalid choice\n");

			}
		}
		break;

		case 2:  						//Singly Circular Linked LIst
		while(choice2 != 0)
			{
			printf("\n------------------------------------------------------------------\n");
			printf("Select any for singly circular linked List operation\n");
			printf("1: Insert First\n");
			printf("2: Insert last\n");
			printf("3: Insert At pos\n");
			printf("4: Delete First\n");
			printf("5: Delete last\n");
			printf("6: Deletet At pos\n");
			printf("7: Display List\n");
			printf("8: Count list Element\n");
			printf("0: Exit  \n");

			printf("Enter The choice\n" );
			scanf("%d",&choice2);

			switch(choice2)
			{
				case 1:
					printf("Enter Number to add\n");
					scanf("%d",&no);
					InsertFirstSC(&First,no);
					break;
				
				case 2:
					printf("Enter number to add At last position\n");
					scanf("%d",&no);
					InsertLastDL(&First,no);
					break;

				case 3:
					printf("Enter number to add At position\n");
					scanf("%d",&no);
					printf("Enter The possition\n");
					scanf("%d",&pos);
					InsertAtPosDL(&First,no,pos);
					break;

				case 4:
					printf("First element Deleted\n");
					iRet=DeleteFirstDL(&First);
					printf("Deleted Number :: %d\n",iRet);
				    break;

				case 5:
					printf("Last element Deleted\n");
					iRet=DeleteLastDL(&First);
					printf("Deleted Number :: %d\n",iRet);
					break;

				case 6:
					printf("enter position\n");
					scanf("%d",&pos);
					iRet=DeleteAtPosDL(&First,pos);
					printf("Deleted Number :: %d\n",iRet);
					break;

				case 7:
					Display(First);
					break;

				case 8:
					iRet=Count(First);
					printf("total number of element in list : %d\n",iRet);
					break;

				case 0:
					printf("Thank u for using application\n");
					break;
				default:
					printf("Invalid choice\n");
					
			}

		}
		break;

		case 3: 						// Doubly Linear linked list
		while(choice2 != 0)
		{
			printf("\n------------------------------------------------------------------\n");
			printf("Select any for Doubly linear linked List operation\n");
			printf("1: Insert First\n");
			printf("2: Insert last\n");
			printf("3: Insert At pos\n");
			printf("4: Delete First\n");
			printf("5: Delete last\n");
			printf("6: Deletet At pos\n");
			printf("7: Display List\n");
			printf("8: Count list Element\n");
			printf("0: Exit  \n");

			printf("Enter The choice\n" );
			scanf("%d",&choice2);
		
			switch(choice2)
			{
				case 1:
					printf("Enter Number to add\n");
					scanf("%d",&no);
					InsertFirstDL(&First,no);
					break;
				
				case 2:
					printf("Enter number to add At last position\n");
					scanf("%d",&no);
					InsertLastDL(&First,no);
					break;

				case 3:
					printf("Enter number to add At position\n");
					scanf("%d",&no);
					printf("Enter The possition\n");
					scanf("%d",&pos);
					InsertAtPosDL(&First,no,pos);
					break;

				case 4:
					printf("First element Deleted\n");
					iRet=DeleteFirstDL(&First);
					printf("Deleted Number :: %d\n",iRet);
				    break;

				case 5:
					printf("Last element Deleted\n");
					iRet=DeleteLastDL(&First);
					printf("Deleted Number :: %d\n",iRet);
					break;

				case 6:
					printf("enter position\n");
					scanf("%d",&pos);
					iRet=DeleteAtPosDL(&First,pos);
					printf("Deleted Number :: %d\n",iRet);
					break;

				case 7:
					Display(First);
					break;

				case 8:
					iRet=Count(First);
					printf("total number of element in list : %d\n",iRet);
					break;

				case 0:
					printf("Thank u for using application\n");
					break;
				default:
					printf("Invalid choice\n");
					
			}
		}
		break;
		/*
		case 4: 						// Doubly Circular Linked list
			while(choice2 != 0)
		{
			printf("\n------------------------------------------------------------------\n");
			printf("Select any for Doubly circular linked List operation\n");
			printf("1: Insert First\n");
			printf("2: Insert last\n");
			printf("3: Insert At pos\n");
			printf("4: Delete First\n");
			printf("5: Delete last\n");
			printf("6: Deletet At pos\n");
			printf("7: Display List\n");
			printf("8: Count list Element\n");
			printf("0: Exit  \n");

			printf("Enter The choice\n" );
			scanf("%d",&choice2);
		
			switch(choice2)
			{
				case 1:
				printf("Enter Number to add\n");
				scanf("%d",&no);
				InsertFirstDC(&First,no);
				break;

				case 2:
					printf("Enter number to add At last position\n");
					scanf("%d",&no);
					InsertLastDC(&First,no);
				break;

				case 3:
					printf("Enter number to add At position\n");
					scanf("%d",&no);
					printf("Enter The possition\n");
					scanf("%d",&pos);
					InsertAtPosDC(&First,no,pos);
				break;

				case 4:
					printf("Delete first element\n");
					DeleteFirstDC(&First);
					break;

				case 5:
					printf("Delete last element\n");
					DeleteLastDC(&First);
					break;
				case 6:
					printf("enter position\n");
					scanf("%d",&pos);
					DeleteAtPosDC(&First,pos);
					break;

				case 7:
				Display(First);
					break;

				case 8:
					iRet=Count(First);
					printf("total number of element in list : %d\n",iRet);
					break;
				default:
					printf("Invalid choice\n");
			}
		}
		break;*/

		case 0:
			printf("Thank U for using application\n");
		break;

		default:
			printf("Invalid Choice\n");

	
	}
	return 0;
}
}