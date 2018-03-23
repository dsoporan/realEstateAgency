#include "Structs.h"

Offer update(OfferList *offerList, char *addr)
{
	Offer offer;
	int idx, surf, pr;
	char *typ = (char *)malloc(sizeof(char) * 101);

	idx = find_index_by_addr(offerList, addr);
	printf("NEW Type: ");
	scanf("%s", typ);
	printf("NEW Address: ");
	scanf("%s", addr);
	printf("NEW Surface: ");
	scanf("%d", &surf);
	printf("NEW Price: ");
	scanf("%d", &pr);

	if (check_addr_unique(offerList, addr))
	{
		offer = adding_offer(typ, addr, surf, pr);
		offerList->off[idx] = offer;
	}
	else
		printf("This ADDRESS already exists.\n");
	free(typ);
	return offer;
}

void displayAscPrice(OfferList *offerList, OfferList *offerList2, char *part)
{
	int i, j;
	Offer offer;
	if (strcmp("*", part) != 0)
	{
		for (i = 0; i < offerList->lenght; i++)
		{
			if (check_string_substring(offerList->off[i].address, part))
				add(offerList2, offerList->off[i]);
		}
	}
	else
	{
		for (i = 0; i < offerList->lenght; i++)
			add(offerList2, offerList->off[i]);
	}
	for (i = 0; i < offerList2->lenght - 1; i++)
	{
		for (j = i + 1; j < offerList2->lenght; j++)
		{
			if (offerList2->off[i].price > offerList2->off[j].price)
			{
				offer = offerList2->off[i];
				offerList2->off[i] = offerList2->off[j];
				offerList2->off[j] = offer;
			}
		}
	}
	printAllOffers(offerList2);
}

void typeSurface(OfferList *offerList, OfferList *offerList2, char *ty, int surf)
{
	int i, j;
	Offer offer;

	for (i = 0; i < offerList->lenght; i++)
	{
		if (strcmp(offerList->off[i].type, ty) == 0)
		{
			if (offerList->off[i].surface > surf)
				add(offerList2, offerList->off[i]);
		}
	}
	printAllOffers(offerList2);
	if (offerList2->lenght == 0)
		printf("No offers\n");
}