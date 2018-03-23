#pragma once
#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>
#include "dynamicArray.h"

typedef struct
{
	char *name;
	Offer offr;
}Operation;

typedef struct
{
	int idx;
	int length;
	Operation *ops;
}OperationsList;

void Menu();
Offer adding_offer(char *ty, char *addr, int surf, int pri);
Operation addingOperation(char *name, Offer offer);
int find_index_by_addr(OfferList *offerList, char *addr);
int check_addr_unique(OfferList *offerList, char *addr);
int check_string_substring(char *str1, char *str2);
void initOfferList(OfferList *offerList);
void initOperationList(OperationsList *operationList);
void add(OfferList *offerList, Offer offer);
void addOperation(OperationsList *operationList, Operation operation);
void delete(OfferList *offerList, char *addr);
Offer update(OfferList *offerList, char *addr);
void initFirst(OfferList *offerList);
void printOffer(Offer off);
void printAllOffers(OfferList *offerList);
void printAllOperations(OperationsList *operationList);
void displayAscPrice(OfferList *offerList, OfferList *offerList2, char *part);
void typeSurface(OfferList *offerList, OfferList *offerList2, char *ty, int surf);
void test_all(OfferList *offerList);
