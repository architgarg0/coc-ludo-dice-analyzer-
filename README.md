# 🎲 Ludo Dice Distribution Analyzer

A Monte Carlo simulation in C that analyzes the probability distribution of rolling two six-sided dice.

## 📋 Overview

This project proves that rolling a 7 in Ludo is more common than rolling 2 or 12. By simulating 1,000,000 dice rolls, you'll see that:
- **Sum of 7**: Most likely (16.67%)
- **Sum of 2 or 12**: Rarest (2.78% each)

## 🚀 Quick Start

### Compilation
```bash
gcc -o ludo_dice ludo_dice_analyzer.c
```

### Run
```bash
./ludo_dice
```

## 🎯 Key Concepts

### The Array Indexing Trick
Instead of multiple if-else statements, use the sum as the array index:
```c
int sum_counts[13] = {0};
sum_counts[sum]++;  // sum is the index!
```

### Monte Carlo Simulation
- Roll two dice 1,000,000 times
- Count each sum
- Compare simulated probability with theoretical probability
- Demonstrates the Law of Large Numbers

### Random Number Generation
```c
srand(time(NULL));              // Seed once
int die = (rand() % 6) + 1;     // Generate 1-6
```

## 📊 Theoretical Probabilities

| Sum | Ways | Probability |
|-----|------|-------------|
| 2 | 1 | 2.78% |
| 3 | 2 | 5.56% |
| 4 | 3 | 8.33% |
| 5 | 4 | 11.11% |
| 6 | 5 | 13.89% |
| **7** | **6** | **16.67%** |
| 8 | 5 | 13.89% |
| 9 | 4 | 11.11% |
| 10 | 3 | 8.33% |
| 11 | 2 | 5.56% |
| 12 | 1 | 2.78% |

**Why 7?** There are 6 ways to roll a 7: (1,6), (2,5), (3,4), (4,3), (5,2), (6,1)

## 💻 Program Structure

| Function | Purpose |
|----------|---------|
| `roll_one_die()` | Simulates rolling a single die (1-6) |
| `print_distribution()` | Displays probability table |
| `print_theoretical_explanation()` | Shows mathematical breakdown |
| `main()` | Runs the simulation |

## 🔧 How It Works

1. **Initialize**: Seed random generator, create array
2. **Simulate**: Roll two dice 1M times, count each sum
3. **Analyze**: Calculate percentages, compare with theory
4. **Display**: Print formatted results

## 🎓 Concepts Tested

- **C Skills**: for loops, arrays, functions, rand(), printf()
- **Math**: Probability, stochastic modeling, expected value
- **Software Engineering**: Clean code, modular design

## 📝 Sample Output

```
  Sum  |  Count   | Simulated % | Theoretical % |  Ways
   2   |    27846 |    2.7846   |     2.7778    |    1
   7   |   166780 |   16.6780   |    16.6667    |    6
  12   |    27817 |    2.7817   |     2.7778    |    1

Most common sum: 7 (appeared 166780 times, 16.6780%)
Least common sum: 2 (appeared 27846 times, 2.7846%)
Average sum per roll: 7.0001 (Theoretical: 7.0)
```

## 🚀 Extensions

- **Beginner**: Try 10,000 rolls instead of 1M
- **Intermediate**: Simulate 3 dice (sums 3-18)
- **Advanced**: Detect biased/unfair dice using chi-squared test

## 📚 Key Takeaways

✓ Arrays efficiently store categorical data using the value as index  
✓ Monte Carlo simulation validates mathematical theory  
✓ With enough trials, simulation converges to theoretical probability  
✓ Real applications: game design, risk analysis, scientific modeling  

---

**Happy coding!** 🎲
