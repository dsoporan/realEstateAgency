#include "Structs.h"

//init Dynamic Array
void initOfferList(OfferList *offerList)
{
	offerList->lenght = 0;
	offerList->off = (TElement)malloc(sizeof(Offer));
}

//sizing and adding in Dynamic Array 
void add(OfferList *offerList, Offer offer)
{
	offerList->off = (TElement)realloc(offerList->off, sizeof(Offer) * (offerList->lenght + 1));
	offerList->off[offerList->lenght] = offer;
	offerList->lenght++;
}

//deleting from Dynamic Array
void delete(OfferList *offerList, char *addr)
{
	int idx;

	idx = find_index_by_addr(offerList, addr);
	if (idx != -1)
	{
		for (int i = idx; i < offerList->lenght; i++)
			offerList->off[i] = offerList->off[i + 1];
		offerList->lenght--;
		printf("Address deleted.\n");
	}
	else
		printf("The Address does not exist.\n");
}

//Creating an offer that will be added in Dynamic Array
Offer adding_offer(char *ty, char *addr, int surf, int pri)
{
	Offer Offers;
	Offers.type = (char *)malloc(sizeof(char) * (101));
	strcpy(Offers.type, ty);
	Offers.address = (char *)malloc(sizeof(char) * (101));
	strcpy(Offers.address, addr);
	Offers.surface = surf;
	Offers.price = pri;

	return Offers;
}