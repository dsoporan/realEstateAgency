#include "Structs.h"

void initOperationList(OperationsList *operationList)
{
	operationList->idx = 0;
	operationList->length = 0;
	operationList->ops = (Operation *)malloc(sizeof(Operation));
}

void initFirst(OfferList *offerList)
{
	Offer offer0 = { "house", "Cluj", 123, 2000 };
	Offer offer1 = { "house", "Moldova", 190, 245766 };
	Offer offer2 = { "apartment", "Iasi", 11, 11 };
	Offer offer3 = { "apartment", "Floresti", 23, 22 };
	Offer offer4 = { "apartment", "Cluj-Floresti", 223, 1000000 };
	Offer offer5 = { "penthouse", "Cluj-Napoca", 244, 999999 };
	Offer offer6 = { "house", "Galati", 1, 1 };
	Offer offer7 = { "house", "Timisoara", 76, 200000 };
	Offer offer8 = { "apartment", "Bucuresti", 355, 321321 };
	Offer offer9 = { "penthouse", "Cluj2", 123, 2222 };

	add(offerList, offer0);
	add(offerList, offer1);
	add(offerList, offer2);
	add(offerList, offer3);
	add(offerList, offer4);
	add(offerList, offer5);
	add(offerList, offer6);
	add(offerList, offer7);
	add(offerList, offer8);
	add(offerList, offer9);
}