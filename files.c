#include "files.h"



FrameNode* insertAtTheEnd(FrameNode** head, FrameNode* newNode)
{
	if (newNode == NULL)
	{
		return NULL;
	}
	if (exists(newNode->frame->path) == 0)
	{
		printf("file curppted!");
		return NULL;
	}

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
	return 32423;
}
char* get_filename_ext(char* filename)
{
	const char* dot = strrchr(filename, '.');
	if (!dot || dot == filename) return "";
	return dot ;
}
FrameNode* load(char* path)
{
	//load from file : check if file exetion is .txt  if yes read every line thats equeaal to one node and insert it at last for every line;
	char word[5] = ".txt";
	word[strcspn(word, "\n")] = 0;
	if (strcmp(get_filename_ext(path), word) == 0)
	{
		int choose = 0;
		FILE* fp = fopen(path, "r");
		char ch = ' ';
		FrameNode* head = NULL;
		FrameNode* p = head;
		char buffer[MAX_LENGTH] = { 0 };
		FrameNode* temp = NULL;
		while (fgets(buffer, MAX_LENGTH, fp))
		{

			if (insertAtTheEnd(&head, NewNode(buffer)) == NULL)
			{
				return NULL;
			}


		}
		return head;
	}
	else
	{
		printf("crrupted file!");
		return NULL;
	}
	
		
}
void save(char* path, FrameNode* head)
{	//wirth to file all the node deitils;
	if (head == NULL)
	{
		printf("nothing to save");
		return;
	}
	char line[MAX_LENGTH] = { 0 };
	FILE* fptr = fopen(path, "w");
	// exiting program 
	if (fptr == NULL) {
		printf("Error! cant open file!");
		return;
	}
	while (head)
	{
		fprintf(fptr, "%s;%u;%s;\n", head->frame->name, head->frame->duration, head->frame->path);
		if (head->next)
		{
			head = head->next;
		}
		else
		{
			printf("done!");
			break;
		}
	}
	
	fclose(fptr);
}
FrameNode* NewNode(char* buffer)
{

	unsigned int Bduratin = { 0 };
	char s[2] = ";";
	char* token = strtok(buffer, s);
	FrameNode* newNode = (FrameNode*)calloc(3, sizeof(FrameNode));
	Frame* newFrame = (Frame*)calloc(3, sizeof(Frame));
	unsigned int duration = 0;
	char* name = (char*)calloc(MAX, sizeof(char));
	char* path = (char*)calloc(MAX, sizeof(char));
	
	strcpy(name, token);

	token = strtok(NULL, s);
	duration = (unsigned int)atoi(token);
	token = strtok(NULL, s);
	strcpy(path, token);
	path[strcspn(path, "\n")] = 0;


	newFrame->name = name;
	newFrame->duration = duration;
	newFrame->path = path;
	FILE* fp = fopen(path, "r");
	if (!fp)
	{
		free(name);
		free(path);
		free(newFrame);
		free(newNode);
		return NULL;
	}
	fclose(fp);
	newNode->frame = newFrame;
	return newNode;


}
void FreeAll(FrameNode* head)
{
	FrameNode* pNode;

	FrameNode* tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		
		free(tmp->frame->path);
		free(tmp->frame->name);
		free(tmp->frame);
		free(tmp);

	}
	return NULL;
}