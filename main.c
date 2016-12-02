//Rawan Alsaadi 10081442
//Omar Toutounji 10169506
//Beltan Michel 10169162

#include "udll.h"

/**
 * Inserts a new node at the beginning of the doubly linked list
 *
 * @data Data of the first node i.e. data of the new node
 */

int main(){
	Data data1={5};
	Data data2={-10};
	Data data3={1000};
	Data data4={-100};
		
	insert(1,data1);
	insert(2,data2);
	insert(3,data3);
	insert(4,data4);
	printf("Length is %d\n",length());
	displayList();
	removeNode(3);
	displayList();
	//system("pause");
	return 0;

}
