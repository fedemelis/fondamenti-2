#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

Item* Diff(const Item* i1, const Item* i2) {

	bool nonPresente = true;
	Item* ris = ListCreateEmpty();

	for (const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)){
		nonPresente = true;
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)){
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0){
				nonPresente = false;
			}
		}
		if (nonPresente){
			ris = ListInsertBack(ris, ListGetHeadValue(tmp1));
		}
	}
	return ris;
}

