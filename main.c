#include "udll.h"
#include <stdlib.h>

/**
 * Inserts a new node at the beginning of the doubly linked list
 *
 * @data Data of the first node i.e. data of the new node
 */

int main(){
	Data data1={10};
	Data data2={-10};
	Data data3={1000};
	Data data4={-100};
		
	insert(0,data1);
	insert(1,data2);
	insert(2,data3);
	insert(3,data4);
	removeNode(1);
	displayList();

}



