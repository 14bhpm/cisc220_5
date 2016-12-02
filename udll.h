#ifndef UDLL
#define UDLL


#include<stdlib.h>
#include<stdio.h>

union Data{	
	int intData;
	int * intPtr;
	float floatData;
	float * floatPtr;	
	char charData;
	char * charPtr;
};


typedef struct DNode{
	union Data data;
	struct DNode * next;
	struct DNode * prev;
};

typedef union Data Data;
typedef struct DNode DNode;

DNode *head;
DNode *last;
void insertAtBeginning(Data data);
void insertAtEnd(Data data);
void displayList();
int length();
void insert(int index, Data data);
union Data get(int index);
void removeNode(int index);
void removeNodeAtBeginning();
void removeNodeAtEnd();

#endif
