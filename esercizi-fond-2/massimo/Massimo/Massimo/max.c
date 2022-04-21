#include "elemtype.h"
#include "list.h"

const ElemType* MaxElement(const Item* i) {

	if (ListIsEmpty(i))
	{
		return NULL;
	}

	ElemType e = 0;

	for (Item* tmp = i ; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)){
		if (e < tmp->value){
			e = tmp->value;
		}
	}
	
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)){
		if (e == tmp->value){
			return ListGetHeadValue(tmp);
		}
	}
}