/*
 * Ludo Dice Distribution Analyzer
 * A Monte Carlo simulation to analyze the probability distribution of rolling two dice
 * Author: Engineering Student Project
 * Concepts: Stochastic Modeling, Arrays, Loops, Functions, Random Number Generation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate rolling a single 6-sided die
int roll_one_die() {
    return (rand() % 6) + 1;  // Returns a number between 1 and 6
}

// Function to print the probability distribution in a formatted table
void print_distribution(int counts[], int num_rolls) {
    printf("\n");
    printf("============================================================================\n");
    printf("                    PROBABILITY DISTRIBUTION REPORT                        \n");
    printf("============================================================================\n");
    printf("Total Simulations: %d\n", num_rolls);
    printf("----------------------------------------------------------------------------\n");
    printf("  Sum  |  Count   | Simulated %% | Theoretical %% |  Ways  | Difference    \n");
    printf("----------------------------------------------------------------------------\n");

    // Theoretical number of ways to achieve each sum (out of 36 possibilities)
    int theoretical_ways[13] = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

    // Calculate and display statistics for each possible sum (2 through 12)
    for (int sum = 2; sum <= 12; sum++) {
        double simulated_prob = (counts[sum] * 100.0) / num_rolls;
        double theoretical_prob = (theoretical_ways[sum] * 100.0) / 36.0;
        double difference = simulated_prob - theoretical_prob;

        printf("  %2d   | %8d |   %7.4f   |    %7.4f    |   %2d   |  %+8.4f   \n",
               sum, counts[sum], simulated_prob, theoretical_prob, 
               theoretical_ways[sum], difference);
    }

    printf("----------------------------------------------------------------------------\n");
    printf("Note: Theoretical probabilities are based on 36 equally likely outcomes\n");
    printf("      when rolling two fair 6-sided dice.\n");
    printf("============================================================================\n");
}

// Function to display theoretical explanation
void print_theoretical_explanation() {
    printf("\n");
    printf("============================================================================\n");
    printf("                    THEORETICAL PROBABILITY EXPLANATION                    \n");
    printf("============================================================================\n");
    printf("When rolling two 6-sided dice, there are 6 × 6 = 36 possible outcomes.\n");
    printf("Each outcome is equally likely if the dice are fair.\n\n");

    printf("Sum |  Combinations                          | Ways | Probability\n");
    printf("----+----------------------------------------+------+-------------\n");
    printf(" 2  | (1,1)                                  |  1   | 1/36  = 2.78%%\n");
    printf(" 3  | (1,2), (2,1)                           |  2   | 2/36  = 5.56%%\n");
    printf(" 4  | (1,3), (2,2), (3,1)                    |  3   | 3/36  = 8.33%%\n");
    printf(" 5  | (1,4), (2,3), (3,2), (4,1)             |  4   | 4/36  = 11.11%%\n");
    printf(" 6  | (1,5), (2,4), (3,3), (4,2), (5,1)      |  5   | 5/36  = 13.89%%\n");
    printf(" 7  | (1,6), (2,5), (3,4), (4,3), (5,2), ... |  6   | 6/36  = 16.67%%\n");
    printf(" 8  | (2,6), (3,5), (4,4), (5,3), (6,2)      |  5   | 5/36  = 13.89%%\n");
    printf(" 9  | (3,6), (4,5), (5,4), (6,3)             |  4   | 4/36  = 11.11%%\n");
    printf("10  | (4,6), (5,5), (6,4)                    |  3   | 3/36  = 8.33%%\n");
    printf("11  | (5,6), (6,5)                           |  2   | 2/36  = 5.56%%\n");
    printf("12  | (6,6)                                  |  1   | 1/36  = 2.78%%\n");
    printf("============================================================================\n");
    printf("KEY INSIGHT: Sum of 7 is most common (6 ways), while 2 and 12 are rarest\n");
    printf("            (only 1 way each). The distribution is symmetric around 7.\n");
    printf("============================================================================\n");
}

int main() {
    // Initialize random seed using current time
    // This ensures different results each time the program runs
    srand(time(NULL));

    // Configuration: Number of simulations to run
    const int NUM_SIMULATIONS = 1000000;  // 1 million rolls

    // Array to store counts for each possible sum
    // Index represents the sum (2-12), so we need size 13 (indices 0-12)
    // We'll use indices 2-12 and ignore 0-1
    int sum_counts[13] = {0};  // Initialize all counts to zero

    printf("Starting Monte Carlo Simulation...\n");
    printf("Simulating %d rolls of two dice...\n", NUM_SIMULATIONS);

    // Main simulation loop: Roll two dice NUM_SIMULATIONS times
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        // Roll two dice using our function
        int die1 = roll_one_die();
        int die2 = roll_one_die();

        // Calculate the sum
        int sum = die1 + die2;

        // Increment the count for this sum
        // This is the key: we use the sum as the array index!
        sum_counts[sum]++;

        // Optional: Show progress every 100,000 rolls
        if ((i + 1) % 100000 == 0) {
            printf("Progress: %d rolls completed...\n", i + 1);
        }
    }

    printf("\nSimulation complete!\n");

    // Display the theoretical explanation first
    print_theoretical_explanation();

    // Display the results in a formatted table
    print_distribution(sum_counts, NUM_SIMULATIONS);

    // Statistical analysis
    printf("\n");
    printf("============================================================================\n");
    printf("                          STATISTICAL ANALYSIS                             \n");
    printf("============================================================================\n");

    // Find the most and least common sums in our simulation
    int max_count = sum_counts[2];
    int min_count = sum_counts[2];
    int max_sum = 2;
    int min_sum = 2;

    for (int sum = 3; sum <= 12; sum++) {
        if (sum_counts[sum] > max_count) {
            max_count = sum_counts[sum];
            max_sum = sum;
        }
        if (sum_counts[sum] < min_count) {
            min_count = sum_counts[sum];
            min_sum = sum;
        }
    }

    printf("Most common sum: %d (appeared %d times, %.4f%%)\n", 
           max_sum, max_count, (max_count * 100.0) / NUM_SIMULATIONS);
    printf("Least common sum: %d (appeared %d times, %.4f%%)\n", 
           min_sum, min_count, (min_count * 100.0) / NUM_SIMULATIONS);

    // Calculate average sum
    long long total_sum = 0;
    for (int sum = 2; sum <= 12; sum++) {
        total_sum += (long long)sum * sum_counts[sum];
    }
    double average = (double)total_sum / NUM_SIMULATIONS;
    printf("Average sum per roll: %.4f (Theoretical: 7.0)\n", average);

    printf("============================================================================\n");
    printf("\nCONCLUSION: This simulation demonstrates the Law of Large Numbers.\n");
    printf("With 1 million trials, our simulated probabilities converge very close\n");
    printf("to the theoretical values, validating our stochastic model!\n");
    printf("============================================================================\n");

    return 0;
}
