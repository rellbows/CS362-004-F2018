// Adventurer
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittestHelper.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define TESTS 2
int main(int argc, char** argv)	{
	struct gameState state;
	int a;
	printf ("Testing Adventurer card\n");
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 4, &state);
    state.deckCount[0] = 0;
	a = cardEffect(adventurer, 0, 0, 0, &state, 1, 0);
	int i;
	bool result = false;
	for(i = 0; i < state.handCount[state.whoseTurn]; i++){
		if(state.hand[state.whoseTurn][i] == 6){
			result = true;
			break;
		}
	}
	// test 1 is to see if the supply count for gold has stayed the same
	// test 2 is to prove that the current player has no gold cards in their hand
	bool results[TESTS] = {assertTrue("supplyCount", state.supplyCount[gold], 30), assertTrue("goldCount", result, false)};
	printFinalResult(results, TESTS);
	return 0;
}

