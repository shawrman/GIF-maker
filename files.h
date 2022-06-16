#ifndef FILESH
#define FILESH
#define MAX 25
#define FALSE 0
#define TRUE !FALSE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linkedList.h"
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 256

void save(char* path,FrameNode* head);
FrameNode* load(char* path);
FrameNode* NewNode(char* buffer);

void FreeAll(FrameNode* head);
char* get_filename_ext(char* filename);



#endif