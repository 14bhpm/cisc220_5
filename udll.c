#include "udll.h"
#include <stdlib.h>

/* This function deletes the second node of the list		*
 * since the data of head is always length(), it's the same	*
 * as deleting the head	itself								*/
void removeNodeAtBeginning(){
	
	if (length() == 1){
		head = NULL;
	} else if (length() == 2){
		free(head->next);
		head->next = NULL;
		head->data.intData--;
	} else {
		head->next = head->next->next;
		free(head->next->prev);
		head->next->prev = head;
		head->data.intData--;
	}
}

void removeNodeAtEnd(){
	
	last = last->prev;
	free(last->next);
	last->next = NULL;
	
}

void removeNode(int index){
	
	DNode * temp;
	
	if (head == NULL){
		printf("List is empty.\n");
	}
	else
	{
		if (index == 1){
			removeNodeAtBeginning();
		} else if (index == length()){
			removeNodeAtEnd();
		} else {
			
			/* If index is closer to length() (last index), it starts	*
			 * a for loop from last going down the list to the index.	*/
			if (abs(length() - index) < abs(1 - index)){
			temp = last;
			for (int i = length(); i>(index+1); i--){
				temp = temp->prev;
			}
			temp->prev = temp->prev->prev;
			free(temp->prev->next);
			temp->prev->next = temp;
			
			} else {
            temp = head;
            for (int i = 0; i<index-1; i++){
				temp = temp->next;
			}
			temp->next = temp->next->next;
			free(temp->next->prev);
			temp->next->prev = temp;
			}
		}
	}
	
}

union Data get(int index){
	
	DNode * temp;
 
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
	{
		
        if (abs(length() - index) > abs(0 - index)){
			temp = last;
			for (int i = length(); i>index; i--){
				temp = temp->prev;
			}
			return temp->data;
		} else {
            temp = head;
            for (int i = 0; i<index; i++){
				temp = temp->next;
			}
			return temp->data;
        }
    }
}

void insertAtBeginning(Data data)
{
    DNode * newNode;
	newNode = (DNode *)malloc(sizeof(DNode));
	newNode->data = data;
	newNode->prev = NULL;
    newNode->next = NULL;
 
    if(head == NULL)
    {
        head = newNode;
		last = newNode;
		head->data.intData = 1;
    }
    else
    {
		int intData = head->data.intData;
		intData++;
        newNode->next = head; //Points to next node which is currently head
        newNode->prev = NULL; //Previous node of first node is NULL
 
        /* Links previous address field of head with newnode */
        head->prev = newNode;
        /* Makes the new node as head node */
        head = newNode;
		head->data.intData = intData;
        
    }
}
 
 
void insertAtEnd(Data data)
{
    DNode * newNode;
	newNode = (DNode *)malloc(sizeof(DNode));
 
	newNode->data = data;
    newNode->next = NULL;
    newNode->prev = last;
 
    last->next = newNode;
    last = newNode;
	head->data.intData++;

            
}
  
/**
 * Displays the content of the list from beginning to end
 */
void displayList()
{
    DNode * temp;
    int n = 1;
 
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
 
        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
 
            n++;
 
            /* Moves the current pointer to next node */
            temp = temp->next;
        }
    }
}

int length(){
	if(head == NULL)
		return 0;
	return head->data.intData;
}
// index >=1 && index <=intData
void insert(int index, Data data)
{
    int i;
    DNode * newNode, *temp;	
 
    if(index < 1 || index > length() +1 ){
        printf("Error, Invalid index index must be between 1 and %d\n", length()+1);
	}else if(head == NULL){
		insertAtBeginning(data);
    }else{
		// if the index is closer to the head then use the head.
		if(index <= length()/2){ 
			temp = head;
			i=1; 
			while(i<index-1 && temp!=NULL){
				temp = temp->next;
				i++;
			}
		}else{  // the last pointer is coser to the index. use the Last
			temp = last;
			i=length(); 
			while(i>index-1 && temp!=NULL){
				temp = temp->prev;
				i--;
			}
		}
		 if(temp == last || index == length()+1){
            insertAtEnd(data);
        }else if(temp == head || index == 1){
            insertAtBeginning(data);
        }else if(temp!=NULL){
            newNode = (DNode *)malloc(sizeof(DNode));
            newNode->data = data;
            newNode->next = temp->next; //Connects new node with index+1th node
            newNode->prev = temp; //Connects new node with index-1th node
            if(temp->next != NULL){
                /* Connects index+1th node with new node */
                temp->next->prev = newNode;
            }
            /* Connects index-1th node with new node */
            temp->next = newNode;
			head->data.intData++;
 
            
        }        
	}
} 
