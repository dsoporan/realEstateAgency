#pragma once

typedef struct
{
	char *type;
	char *address;
	int surface;
	int price;
}Offer;

typedef Offer *TElement;

//Dynamic Array
typedef struct
{
	TElement off;
	int lenght;

}OfferList;
