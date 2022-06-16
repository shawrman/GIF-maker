#ifndef LINKEDLISTH
#define LINKEDLISTH
#define MAX 25
#define FALSE 0
#define TRUE !FALSE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// Frame struct
typedef struct Frame
{
	char*		name;
	unsigned int	duration;
	char*		path; 
	
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	int index;
	struct FrameNode* next;
} FrameNode;
int updateIndex(FrameNode* head);


FrameNode* Remove(FrameNode** head);
void insertAtEnd(FrameNode** head);


void printFrame(Frame* cur);
void print(FrameNode* head);
void changeDurationForAll(FrameNode* head);
void changeDuration(FrameNode* head);
void swapNodes(FrameNode** head_ref, int x, int y);
int exists(char* fname);






#endif
