/*********************************
* Class: MAGSHIMIM C2			 *
* openCV template      			 *
**********************************/
#define CV_IGNORE_DEBUG_BUILD_GUARD
#include <opencv2/imgcodecs/imgcodecs_c.h>

#include "LinkedList.h"
#include "view.h"
#include "files.h"
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX 25
int main(void)
{
	int first = 0;
	int second = 0;
	int choose = 1;
	FrameNode* head = NULL;
	char path[MAX] = { 0 };
	char name[MAX] = { 0 };
	
	while (choose != 0)
	{	
		printf("\n\nWhat would you like to do?\n"
			"[0] Exit\n"
			"[1] Add new Frame\n"
			"[2] Remove a Frame\n"
			"[3] switch frame index\n"
			"[4] Change frame duration\n"
			"[5] Change duration of all frames\n"
			"[6] List frames\n"
			"[7] Play movie!\n"
			"[8] Save project\n"
			"[9] Load project(be curfull its will delete your unsaved project\n"
		);
		scanf("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1:
			 insertAtEnd(&head);  
			break;
		case 2:
			Remove(&head);

			break;
		case 3:
			first = 0;
			second = 0;
			printf("enter what nodes to switch: ");
			scanf("%d", &first);
			getchar();
			scanf("%d", &second);
			getchar();
			swapNodes(&head, first, second);
			break;
		case 4:
			changeDuration(head);
			break;
		case 5:
			changeDurationForAll(head);
			break;
		case 6:
			print(head);
			break;
		case 7:
			play(head);
			break;
		case 8:
			printf("where you want to save the file?  ");
			fgets(path, MAX, stdin);
			path[strcspn(path, "\n")] = 0;

			printf("name the file ");
			fgets(name, MAX, stdin);
			name[strcspn(name, "\n")] = 0;
			strcat(path, "/");
			path[strcspn(path, "\n")] = 0;

			strcat(path, name);
			//strcat(path, ".txt");
			path[strcspn(path, "\n")] = 0;

			save(path, head);

			
			break;
		case 9:
			printf("from where you want to load the file?  ");
			fgets(path, MAX, stdin);
			path[strcspn(path, "\n")] = 0;
			if (exists(path))
			{
				head = load(path);

			}
			else
			{
				printf("cant open file!");
			}

			break;
		case 0:
			printf("bye!!!");
			FreeAll(head);
			head = NULL;
			break;
		}
		updateIndex(head);
	} 
	

	return 0;
}