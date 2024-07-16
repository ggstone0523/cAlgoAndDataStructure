#include "ArrayStack.h"

int AS_IsFull(ArrayStack* Stack) {
	return ((Stack->Top + 1) >= Stack->Capacity);
}
