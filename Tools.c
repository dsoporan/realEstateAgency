#include "Structs.h"

void Menu()
{
	printf("Type 'print' if you want to see all the addresses \n");
	printf("Type 'add' if you want to add an Offer\n");
	printf("Type 'delete' if you want to delete an Offer\n");
	printf("Type 'update' if you want to update an Offer\n");
	printf("Type 'display' if you want to display Offers that contains a given string\n");
	printf("Type 'surface' if you want to display Offers that have a certain surface\n");
	printf("Type 'display_type' if you want to display Offers that have a given type with surface larger than a given value\n");
	printf("Type 'undo' for undo\n");
	printf("Type 'redo' for redo\n");
	printf("Type 'tests' for tests\n");
	printf("Type 'lab' for the lab activity\n");
	printf("Type 'exit' for exit\n");
}

int find_index_by_addr(OfferList *offerList, char *addr)
{
	for (int i = 0; i <= offerList->lenght; i++)
	{
		if (strcmp(offerList->off[i].address, addr) == 0)
			return i;
	}
	return -1;
}

int check_addr_unique(OfferList *offerList, char *addr)
{
	int i;
	if (offerList->lenght == 0)
		return 1;
	for (i = 0; i < offerList->lenght; i++)
	{
		if (strcmp(offerList->off[i].address, addr) == 0)
			return 0;
	}
	return 1;
}

int check_string_substring(char *str1, char *str2)
{
	int i, j, ok = -1;
	for (i = 0; i <= strlen(str1); i++)
	{
		if (str1[i] == str2[0])
		{
			ok = 1;
			for (j = 1; j < strlen(str2) && i < strlen(str1); j++)
			{
				i++;
				if (str1[i] != str2[j])
				{
					ok = 0;
					break;
				}
			}
		}
	}
	if (ok == 1)
		return 1;
	else
		return 0;
}

void printOffer(Offer off)
{
	printf("Type: %s\n", off.type);
	printf("Address: %s\n", off.address);
	printf("Surface: %d\n", off.surface);
	printf("Price: %d\n\n", off.price);
}

void printAllOffers(OfferList *offerList)
{
	Offer offer;
	int i;
	for (i = 0; i < offerList->lenght; i++)
	{
		offer = offerList->off[i];
		printOffer(offer);
	}
}

void printAllOperations(OperationsList *operationList)
{
	Offer offer;
	for (int i = 0; i < operationList->length; i++)
	{
		printf("%s", operationList->ops[i].name);
		offer = operationList->ops[i].offr;
		printOffer(offer);
	}
}