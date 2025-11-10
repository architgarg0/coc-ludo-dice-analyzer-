# Ludo Dice Distribution Analyzer

## Project Title & Description

The Ludo Dice Distribution Analyzer is a Monte Carlo simulation program written in C that scientifically analyzes the probability distribution of rolling two six-sided dice. The program simulates 1,000,000 dice rolls to determine the true probability of each possible sum (2 through 12) and compares the simulated results with the theoretical mathematical probabilities.

This project validates an intuitive observation many Ludo players have made: rolling a sum of 7 is far more common than rolling 2 or 12. By running millions of simulations, the program proves this through empirical data, demonstrating that simulation results converge to theoretical probabilities.

## Concepts Used

### C Programming Concepts

- For loops: Used to simulate 1,000,000 iterations of dice rolling
- Arrays: Used to store and count occurrences of each possible sum (indices 2-12)
- Functions: Modular code with separate functions for rolling dice, printing results, and displaying theoretical explanations
- Random number generation: rand() function with srand(time(NULL)) for seeding
- Control structures: if/else statements for comparisons and conditions
- printf(): Formatted output to display results in professional table format
- Standard libraries: stdio.h, stdlib.h, time.h

### Mathematics & Statistical Concepts

- Probability Distribution: Analysis of how probabilities are distributed across possible outcomes
- Stochastic Modeling: Using random sampling to model real-world phenomena
- Monte Carlo Simulation: Running repeated random experiments to obtain numerical results
- Law of Large Numbers: Demonstrating that empirical probability converges to theoretical probability with large sample sizes
- Expected Value: Calculating the mean of the distribution (7.0)
- Combinatorics: Understanding the 36 possible outcomes when rolling two dice
- Sample Space: Identifying all possible outcomes and their frequencies

## How to Compile

To compile the program, use the following gcc command:

```
gcc -Wall coc-ludo_dice_analyzer-.c -o ludo_dice
```

Explanation of flags:
- gcc: The GNU C Compiler
- -Wall: Enable all compiler warnings to catch potential issues
- ludo_dice_analyzer.c: The source C file
- -o ludo_dice: Specifies the output executable name

Alternative compilation command with optimization:

```
gcc -Wall -O2 coc-ludo_dice_analyzer-.c -o ludo_dice
```

The -O2 flag enables optimization for faster execution during runtime.

## How to Run

After successful compilation, execute the program using:

```
./ludo_dice
```

On Windows systems, use:

```
ludo_dice.exe
```

## Expected Output

The program produces a detailed probability distribution report showing:

1. The count of each sum (2 through 12) from the 1,000,000 simulations
2. The simulated probability percentage for each sum
3. The theoretical probability percentage for each sum
4. The number of ways each sum can be achieved
5. The difference between simulated and theoretical values
6. Statistical analysis including most common sum, least common sum, and average sum

Example output format:

```
============================================================================
                    PROBABILITY DISTRIBUTION REPORT                        
============================================================================
Total Simulations: 1000000
----------------------------------------------------------------------------
  Sum  |  Count   | Simulated % | Theoretical % |  Ways  | Difference    
----------------------------------------------------------------------------
   2   |    27846 |    2.7846   |     2.7778    |    1   |   +0.0068   
   3   |    55150 |    5.5150   |     5.5556    |    2   |   -0.0406   
   4   |    83826 |    8.3826   |     8.3333    |    3   |   +0.0493   
   5   |   110386 |   11.0386   |    11.1111    |    4   |   -0.0725   
   6   |   139203 |   13.9203   |    13.8889    |    5   |   +0.0314   
   7   |   166780 |   16.6780   |    16.6667    |    6   |   +0.0113   
   8   |   138761 |   13.8761   |    13.8889    |    5   |   -0.0128   
   9   |   111307 |   11.1307   |    11.1111    |    4   |   +0.0196   
  10   |    83290 |    8.3290   |     8.3333    |    3   |   -0.0043   
  11   |    55634 |    5.5634   |     5.5556    |    2   |   +0.0078   
  12   |    27817 |    2.7817   |     2.7778    |    1   |   +0.0039   
----------------------------------------------------------------------------

============================================================================
                          STATISTICAL ANALYSIS                             
============================================================================
Most common sum: 7 (appeared 166780 times, 16.6780%)
Least common sum: 2 (appeared 27846 times, 2.7846%)
Average sum per roll: 7.0001 (Theoretical: 7.0)
============================================================================
```

## Program Architecture

The program is organized into four main components:

### roll_one_die()
Simulates rolling a single six-sided die by generating a random integer between 1 and 6 using the rand() function.

### print_theoretical_explanation()
Displays the mathematical foundation of the problem, showing all possible dice combinations and their corresponding probabilities for each sum.

### print_distribution(int counts[], int num_rolls)
Accepts the count array and total number of simulations, then calculates and displays the probability distribution table with comparisons between simulated and theoretical values.

### main()
Orchestrates the entire program by initializing the random seed, running the simulation loop 1,000,000 times, and calling the display functions to present results.

## Key Algorithm: Array Indexing Technique

The core insight of this project is using the dice sum value as the array index:

```c
int sum_counts[13] = {0};
for (int i = 0; i < 1000000; i++) {
    int die1 = roll_one_die();
    int die2 = roll_one_die();
    int sum = die1 + die2;
    sum_counts[sum]++;  // Use sum as the index
}
```

This elegant approach eliminates the need for multiple if-else statements and provides O(1) time complexity for incrementing counters.

## Theoretical Background

When rolling two fair six-sided dice, there are exactly 36 equally likely outcomes. The possible sums range from 2 to 12, but they do not have equal probability:

- Sum of 2: 1 way (1,1) = 2.78%
- Sum of 3: 2 ways (1,2), (2,1) = 5.56%
- Sum of 4: 3 ways (1,3), (2,2), (3,1) = 8.33%
- Sum of 5: 4 ways = 11.11%
- Sum of 6: 5 ways = 13.89%
- Sum of 7: 6 ways (1,6), (2,5), (3,4), (4,3), (5,2), (6,1) = 16.67%
- Sum of 8: 5 ways = 13.89%
- Sum of 9: 4 ways = 11.11%
- Sum of 10: 3 ways = 8.33%
- Sum of 11: 2 ways = 5.56%
- Sum of 12: 1 way (6,6) = 2.78%

The distribution is symmetric around 7 and follows a triangular probability distribution. This project validates this theory through computational simulation.

## Files Included

- ludo_dice_analyzer.c: The complete C source code
- README.md: This documentation file

## Requirements

- GCC compiler (or equivalent C compiler)
- Standard C library (included with most systems)
- No external libraries required

## Compilation and Execution Summary

Complete workflow:

```
Step 1: Compile
$ gcc -coc-Wall ludo_dice_analyzer-.c -o ludo_dice

Step 2: Run
$ ./ludo_dice

Step 3: View Results
The program automatically displays the probability distribution report
```

## Validation

The program has been validated by comparing simulated probabilities with theoretical values across 1,000,000 trials. The differences between simulated and theoretical values are consistently less than 0.1%, confirming both the correctness of the implementation and the accuracy of the underlying mathematical model.
