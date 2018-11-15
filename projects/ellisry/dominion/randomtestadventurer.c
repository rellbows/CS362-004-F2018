/* 
** Filename: randomTest1.c
** Description: Random test the adventurer action card.
** Author: Ryan Ellis
** Class: CS362
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"

#define TESTCARD "adventurer"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// number of random games to run
#define NUM_GAMES 20

// limits on player numbers *Note: MAX_PLAYERS already defined elsewhere
#define MIN_PLAYERS 2

int main(){
    int refNumTreasure;   // holds num of treasure card in ref game
    int testNumTreasure;   // holds num of treasure card in test game
    int newTreasure = 2;   // should have 2 more treasure cards after play
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed, numPlayers;    // going to randomize these
    int i;    // counter to keep track of games played
    int j;    // counter to get num of treasure cards
    int thisPlayer = 0;    // always using player 0
	struct gameState G, testG;
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int treasure[3] = {copper, silver, gold};

    // setup randomizer
    srand(time(NULL));

    // loop to run randomized games
    for (i = 0; i < NUM_GAMES; i++)
    {
        // randomize number of players
        numPlayers = MIN_PLAYERS + rand() % (MAX_PLAYERS+1 - MIN_PLAYERS);
        // randomize seed value for initializing game
        seed = 1 + rand() % (1000+1 - 1);
        // clear out values for treasure cards
        refNumTreasure = 0;
        testNumTreasure = 0;

        // start reference game used to check test game against
        initializeGame(numPlayers, k, seed, &G);

        printf("TESTING %s\n\n", TESTCARD);

        // Test 1: to ensure player 0 has two treasure cards at 
        // end of turn
        printf("Test 1 - Player 0's Has 2 Treasure Cards\n");

        // copy reference game to test game
        memcpy(&testG, &G, sizeof(struct gameState));
        // play adventurer
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
        // get number of treasure cards in reference game
        for (j = 0; j < 3; j++)
        {
            refNumTreasure += supplyCount(treasure[j], &G);
        }
        // get number of treasure cards in test game
        for (j = 0; j < 3; j++)
        {
            testNumTreasure += supplyCount(treasure[j], &testG);
        }
        if(refNumTreasure + newTreasure == testNumTreasure){
            printf("Test 1 passed!\n");
        }
        else{
            printf("Test 1 failed!\n");
        }
    }
    
    return 0;
}