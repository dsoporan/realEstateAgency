#include "Structs.h"

int main()
{
	char *op = (char *)malloc(sizeof(char) * 101);
	char *typ = (char *)malloc(sizeof(char) * 101);
	char *typ2 = (char *)malloc(sizeof(char) * 101);
	char *typ3 = (char *)malloc(sizeof(char) * 101);
	char *addr = (char *)malloc(sizeof(char) * 101);
	char *part = (char *)malloc(sizeof(char) * 101);
	int surf, pr, i, idx;
	OfferList offerList;
	Offer offer, offer2, upOffer;
	OfferList offs, offerList2, offerList3, offerListUpdate, offerListUpdateUndo, offerListCopy;
	OperationsList undoList;
	OperationsList redoList;
	Operation operation;

	initOfferList(&offerList);
	initOfferList(&offs);
	initOfferList(&offerList2);
	initOfferList(&offerList3);
	initOfferList(&offerListUpdate);
	initOfferList(&offerListUpdateUndo);
	initOfferList(&offerListCopy);
	initFirst(&offerList);

	initOperationList(&undoList);
	initOperationList(&redoList);

	while (1)
	{
		Menu();
		printf("Option: ");
		scanf("%s", op);
		if (strcmp(op, "add") == 0)
		{
			printf("Type: ");
			scanf("%s", typ);
			printf("Address: ");
			scanf("%s", addr);
			printf("Surface: ");
			scanf("%d", &surf);
			printf("Price: ");
			scanf("%d", &pr);
			offer = adding_offer(typ, addr, surf, pr);
			add(&offerList, offer);

			add(&offs, offer);

			operation = addingOperation("add", offer);
			addOperation(&undoList, operation);
		}
		else if (strcmp(op, "print") == 0)
		{
			printAllOffers(&offerList);
		}
		else if (strcmp(op, "delete") == 0)
		{
			printf("ADDRESS to delete: ");
			scanf("%s", addr);
			offer = offerList.off[find_index_by_addr(&offerList, addr)];
			delete(&offerList, addr);

			operation = addingOperation("delete", offer);
			addOperation(&undoList, operation);
		}
		else if (strcmp(op, "update") == 0)
		{
			printf("ADDRESS to update: ");
			scanf("%s", addr);
			offer2 = offerList.off[find_index_by_addr(&offerList, addr)];
			offer = update(&offerList, addr);
			
			add(&offs, offer);
			add(&offerListUpdate, offer);

			operation = addingOperation("update", offer2);
			addOperation(&undoList, operation);

		}
		else if (strcmp(op, "display") == 0)
		{
			printf("Give a part from an address ('*' if you want them all) : ");
			scanf("%s", part);

			displayAscPrice(&offerList, &offerList2, part);
			offerList2.lenght = 0;
			
		}
		else if (strcmp(op, "display_type") == 0)
		{
			printf("Give a type of an offer : ");
			scanf("%s", typ2);
			printf("Give a surface : ");
			scanf("%d", &surf);

			typeSurface(&offerList, &offerList3, typ2, surf);
			offerList3.lenght = 0;

		}
		else if (strcmp(op, "undo") == 0)
		{
			if (undoList.length != 0)
			{
				if (strcmp(undoList.ops[undoList.length - 1].name, "add") == 0)
				{
					operation = addingOperation("add", undoList.ops[undoList.length - 1].offr);
					addOperation(&redoList, operation);

					delete(&offerList, undoList.ops[undoList.length - 1].offr.address);
					undoList.length--;

				}
				else if (strcmp(undoList.ops[undoList.length - 1].name, "delete") == 0)
				{
					operation = addingOperation("delete", undoList.ops[undoList.length - 1].offr);
					addOperation(&redoList, operation);

					add(&offerList, undoList.ops[undoList.length - 1].offr);
					undoList.length--;
				}
				else if (strcmp(undoList.ops[undoList.length - 1].name, "update") == 0)
				{
					idx = find_index_by_addr(&offerList, offerListUpdate.off[offerListUpdate.lenght - 1].address);
					offerListUpdate.lenght--;

					operation = addingOperation("update", offerList.off[idx]);
					addOperation(&redoList, operation);

					offerList.off[idx].address = undoList.ops[undoList.length - 1].offr.address;
					offerList.off[idx].type = undoList.ops[undoList.length - 1].offr.type;
					offerList.off[idx].surface = undoList.ops[undoList.length - 1].offr.surface;
					offerList.off[idx].price = undoList.ops[undoList.length - 1].offr.price;
					
					add(&offerListUpdateUndo, undoList.ops[undoList.length - 1].offr);
					undoList.length--;

				}
			}
			else
				printf("Undo cannot be performed\n");
			
		}
		else if (strcmp(op, "redo") == 0)
		{
			if (redoList.length != 0)
			{
				if (strcmp(redoList.ops[redoList.length - 1].name, "add") == 0)
				{
					add(&offerList, redoList.ops[redoList.length - 1].offr);
					redoList.length--;

				}
				else if (strcmp(redoList.ops[redoList.length - 1].name, "delete") == 0)
				{
					delete(&offerList, redoList.ops[redoList.length - 1].offr.address);
					redoList.length--;
				}
				else if (strcmp(redoList.ops[redoList.length - 1].name, "update") == 0)
				{
					idx = find_index_by_addr(&offerList, offerListUpdateUndo.off[offerListUpdateUndo.lenght - 1].address);
					offerListUpdateUndo.lenght--;

					offerList.off[idx].address = redoList.ops[redoList.length - 1].offr.address;
					offerList.off[idx].type = redoList.ops[redoList.length - 1].offr.type;
					offerList.off[idx].surface = redoList.ops[redoList.length - 1].offr.surface;
					offerList.off[idx].price = redoList.ops[redoList.length - 1].offr.price;
					redoList.length--;

				}
			}
			else
				printf("Redo cannot be performed\n");
		}
		else if (strcmp(op, "lab") == 0)
		{
			printf("Give type: ");
			scanf("%s", typ3);
			printf("Give price: ");
			scanf("%d", &pr);
			for (int k = 0; k < offerList.lenght; k++)
			{
				if (strcmp(offerList.off[k].type, typ3) == 0)
				{
					if (offerList.off[k].price < pr)
					{
						add(&offerListCopy, offerList.off[k]);
					}
				}
			}
			for (int k = 0; k < offerListCopy.lenght - 1; k++)
			{
				for (int k2 = k + 1; k2 < offerListCopy.lenght; k2++)
				{
					if (offerListCopy.off[k].price > offerListCopy.off[k2].price)
					{
						offer = offerListCopy.off[k];
						offerListCopy.off[k] = offerListCopy.off[k2];
						offerListCopy.off[k2] = offer;
					}
				}
			}
			printAllOffers(&offerListCopy);


		}
		else if (strcmp(op, "tests") == 0)
		{
			test_all(&offerList);
			printf("All good.\n");
		}
		else
			break;
	}

	free(op);
	free(typ);
	free(typ2);
	free(typ3);
	free(part);
	free(addr);
	for (i = 0; i < offs.lenght; i++)
	{
		free(offs.off[i].address);
		free(offs.off[i].type);
	}
	free(offs.off);
	free(offerList3.off);
	free(offerList2.off);
	free(offerList.off);
	free(offerListCopy.off);
	for (i = 0; i < undoList.idx; i++)
	{
		free(undoList.ops[i].name);
	}
	for (i = 0; i < redoList.idx; i++)
	{
		free(redoList.ops[i].name);
	}
	free(undoList.ops);
	free(redoList.ops);
	free(offerListUpdate.off);
	free(offerListUpdateUndo.off);
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}