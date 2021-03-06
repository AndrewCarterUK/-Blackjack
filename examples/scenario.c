#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../blackjack.h"

const int simulations = 100;

int main(int argc, char *argv[])
{
    blackjack_simulation_results_t results;

    // These are the remaining cards in the deck
    blackjack_card_t deck[] = { 5, 7, BLACKJACK_ACE, 2, BLACKJACK_QUEEN, BLACKJACK_QUEEN, 4, 10 };

    // This is the players hand (it must have space for one more card to allow for simulating taking a new card)
    blackjack_card_t hand[3] = { 6, 7 };

    // This is the card that the dealer has
    blackjack_card_t dealer_card = 9;

    // Seed the random number generator
    srand(time(NULL));

    // Run the simulations
    // This will scramble the deck, write to the next card in the hand array and fill the results structure
    blackjack_run_simulations(deck, sizeof(deck) / sizeof(blackjack_card_t), hand, 2, dealer_card, &results, simulations);

    // Print the results
    printf(
        "Hit Results:\n"
            "\tWin Probability:         %d%%\n"
            "\tLose Probability:        %d%%\n"
            "\tDraw Probablity:         %d%%\n"
            "\tBust Probability:        %d%%\n"
            "\tDealer Bust Probability: %d%%\n"
        "\n"
        "Stand Results:\n"
            "\tWin Probability:         %d%%\n"
            "\tLose Probability:        %d%%\n"
            "\tDraw Probablity:         %d%%\n"
            "\tDealer Bust Probability: %d%%\n"
        "\n",
        results.hit_wins, results.hit_loses, results.hit_draws, results.hit_bust, results.hit_dealer_bust,
        results.stand_wins, results.stand_loses, results.stand_draws, results.stand_dealer_bust
    );

    return 0;
}