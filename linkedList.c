#include "LinkedList.h"
#define _CRT_SECURE_NO_WARNINGS


void print(FrameNode* head)
{	//sending to print all the nodes
	printf("\nName			Duration			Path\n");
	FrameNode* p = head;
	if (p)
	{
		while (p)
		{
			printFrame(p->frame);
			if (p->next == NULL )
			{
				break;
			}
			p = p->next;

		}
	}
	
}
void printFrame(Frame* cur)
{	//print frame ditels
	printf("\n%s			%u ms			%s\n", cur->name, cur->duration, cur->path);
}
void insertAtEnd(FrameNode** head)
{	// insert at the end new node 
	FrameNode* newNode = (FrameNode*)calloc(3,sizeof(FrameNode));
	Frame* newFrame = (Frame*)calloc(3,sizeof(Frame));
	unsigned int duration = 0;
	char* name = (char*)calloc(MAX, sizeof(char));
	char* path = (char*)calloc(MAX, sizeof(char));
	newNode->frame = newFrame;
	printf("duration of frame in ms: ");
	scanf("%u", &duration);
	getchar();
	newNode->frame->duration = duration;
	printf("enter name of frame: ");
	fgets(name, MAX, stdin);
	name[strcspn(name, "\n")] = 0;

	printf("enter path of frame: ");
	fgets(path, MAX, stdin);
	path[strcspn(path, "\n")] = 0;
	if (exists(path))
	{
		printf("file found!");

	}
	else
	{
		printf("file not found! \ntry again!");
		free(name);
		free(path);
		free(newFrame);
		free(newNode);
		return;
	}
	newNode->frame->name = name;														
	newNode->frame->path = path;
	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		FrameNode* p = *head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = newNode;
	}
}



int updateIndex(FrameNode* head)
{	//update the index of all the nodes and return the number of nodes
	int i = 1;
	FrameNode* temp = head;

	
	while (temp)
	{
		temp->index = i;
		i++;
		if (temp->next)
		{
			temp = temp->next;

		}
		else
		{
			return i;
		}
	}

	
}
FrameNode* Remove(FrameNode** head)
{	 //remove node from list
	if (*head == NULL)
	{
		printf("you gif is empty.");
		return NULL;
	}
	printf("enter the name of the frame you want to remove: ");

	char name[MAX] = { 0 };
	fgets(name, MAX, stdin);
	name[strcspn(name, "\n")] = 0;
	
		if (strcmp((*head)->frame->name, name) == 0 )
		{
			*head = (*head)->next;
			return NULL;
		}
		else
		{
			FrameNode* p = *head;
			while (p->next)
			{
				if (p->next->frame->name && strcmp(p->next->frame->name, name) == 0)
				{
					p->next = p->next->next;
					printf("found and delted!.");
					return NULL;

				}
				p = p->next;
			}
			
		}
	
	
	


}

void changeDuration(FrameNode* head)
//changing duration for one node
{
	char name[MAX] = { 0 };
	unsigned int done = 0;
	printf("enter name: ");
	fgets(name, MAX, stdin);
	name[strcspn(name, "\n")] = 0;



	FrameNode* p = head;
	
	while (p)
	{
		if (strcmp(p->frame->name, name) == 0)
		{
			printf("enter new durtion: ");
			scanf("%u", &done);
			getchar();
			p->frame->duration = done;
		
			break;
		}
		if (!p->next)
		{
			printf("not found!\n");
			break;
		}
		else
		{
			p = p->next;
		}

	}
	
	printf("try again with correct name.");
}
void changeDurationForAll(FrameNode* head)
{
	//changing duration for all nodes
	unsigned int done = 0;
	
	printf("enter new durtion: ");
	scanf("%u", &done);
	getchar();


	
	FrameNode* p = head;
	
	while (p)
	{
	
		p->frame->duration = done;
		if (!p->next)
		{
			printf("done\n");
			break;
		}
		else
		{
			p = p->next;
		}

	}
	
	
}
int exists(char* fname)
{
	  //check if file exiest

	FILE* file;
	if ((file = fopen(fname, "r")))
	{	
		
		fclose(file);
		return 1;
	}
	printf("error! \n");
	return 0;
}
void swapNodes(FrameNode** head_ref, int x, int y)
{
	// Nothing to do if x and y are same
	if (x == y)
	{
		printf("nothing to do!\n");
		return;

	}

	// Search for x (keep track of prevX and CurrX
	FrameNode* prevX = NULL, * currX = *head_ref;
	while (currX && currX->index != x) {
		prevX = currX;
		currX = currX->next;
	}

	// Search for y (keep track of prevY and CurrY
	FrameNode* prevY = NULL, * currY = *head_ref;
	while (currY && currY->index != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	// If either x or y is not present, nothing to do
	if (currX == NULL || currY == NULL)
	{
		printf("can't found index!\n");
		return;
	}


	// If x is not head of linked list
	if (prevX != NULL)
	{
		prevX->next = currY;

	}
	else // Else make y as new head
	{
		*head_ref = currY;

	}

	// If y is not head of linked list
	if (prevY != NULL)
	{
		prevY->next = currX;

	}
	else // Else make x as new head
	{
		*head_ref = currX;

	}

	// Swap next pointers
	FrameNode* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
	printf("done!\n");

}

