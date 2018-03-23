#include "Structs.h"


Operation addingOperation(char *name, Offer offer)
{
	Operation operation;

	operation.name = (char *)malloc(sizeof(char) * (101));
	strcpy(operation.name, name);
	operation.offr = offer;

	return operation;
}

void addOperation(OperationsList *operationList, Operation operation)
{
	operationList->ops = (OperationsList *)realloc(operationList->ops, sizeof(OperationsList) * (10));
	operationList->ops[operationList->length] = operation;
	operationList->length++;
	operationList->idx++;
}
