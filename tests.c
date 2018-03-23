#include "Structs.h"

void test_all(OfferList *offerList)
{
	int i;
	//Check address if it is unique
	i = check_addr_unique(offerList, "Cluj", 9);
	assert(i == 0);
	i = check_addr_unique(offerList, "asdfa", 9);
	assert(i == 1);
	//Returning the index of a certain address
	i = find_index_by_addr(offerList, "Cluj", 9);
	assert(i == 0);
	i = find_index_by_addr(offerList, "Clujaaa", 9);
	assert(i == -1);
	//Checking if a string contains a substring
	i = check_string_substring("asdasd", "as");
	assert(i == 1);
	i = check_string_substring("asdasd", "dd");
	assert(i == 0);
}