// Feast
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittestHelper.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define TESTS 1
// FEAST gives you 5 coins
int main(int argc, char** argv)	{
	struct gameState state;
	int a;
	printf ("Testing Feast card\n");
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 4, &state);
    state.supplyCount[duchy] = 1; // change this to 0 and an infinite loop will occur
    // a = cardEffect(feast, 2, 0, 0, &state, 1, 0); this function call will cause an infinite loop 
	a = cardEffect(feast, 5, 0, 0, &state, 1, 0); // if you buy card 5 - silver - which costs 3 you can buy it
	// test 1 is to see if the function returned the correct value
	bool results[TESTS] = {assertTrue("value returned", a, 0)};
	printFinalResult(results, TESTS);
	return 0;
}


// BUG FOUND: change supply count of province to 0 and an infinite loop will occur - there's none of that card left so it never exits
// BUG FOUND: change supply count of province to 1 and an infinite loop will still occur - it's too expensive

// BUG SOLUTION: You have to have more coins than the current cost of the item that you are trying to buy to exit out of the while loop
// - now you can't buy something when you have the exact amount ready for it