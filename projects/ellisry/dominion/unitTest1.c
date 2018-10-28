/* 
** Filename: testDiscardCard.
** Description: Test the discardCard function.
** Author: Ryan Ellis
** Class: CS362
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISE_TEST to 0 remove printfs from output
#define NOISY_TEST 1

int main(){
	int i;
	int seed = 1000;
	int numPlayer = 2
	int maxBonus = 10;
	int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int discardedCart;

    printf("TESTING discardCard():\n");
    r = initializeGame(numPlayer, k, seed, &G);    // initialize the test game
    printf("Test 1 - Trash Flag\n");    // when trash flag (-1) is passed as argument
    discardedCard = G.hand[0][0];
    printf("Discarded Card is: %d", discardedCard);

    return 0;
}
