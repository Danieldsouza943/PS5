# PS5: DNA Sequence Alignment
## Contact
Name: Daniel Dsouza
Section: 201
Time to Complete: about 6 hours
Partner: NA

## Description
This project implements DNA sequence alignment using dynamic programming to compute the optimal alignment score, between two DNA sequences. The program takes in two DNA strings and returns both the edit distance between and the alignment of the two strings.

### Features
Utilized a 2D matrix (vector of vectors) to calculate the edit distance and applied the Needleman-Wunsch method to trace back the correct alignment from the generated matrix.

### Testing
I wrote tests for each of the public functions in the class first.

### Issues
Encountered some challenges with printing the complete aligned string, but these issues were resolved promptly. Overall, this assignment reinforced the efficient handling of dynamic programming problems and memory management. However, all the issues were resolved in a reasonable time.


## Analysis

### Example
Do one additional test case by hand. It should be constructed in such a way that you know the correct output before running your program on it, and it should be a "corner case" that helps check if your program handles all special situations correctly. 

Please list:
 - a copy of the test case input
 - the expected test case output
 - whether your program ran correctly on it or not
 - optionally, any other remarks

### Specs
Your Computer
Memory: 16.0 GB (15.9 GB usable) (7.7GB in WSL)
Processors: Intel(R) Core(TM) i7-7500U CPU @ 2.70GHz   2.90 GHz

Partner's Computer - NA
Memory: (ex: 8gb, DDR4) - NA
Processors: (ex: i5-8500 @ 3.00 GHz x6) - NA

### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

| data file     | distance | memory (mb) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
|ecoli2500.txt  |    118   |     24MB    |      0.29      |      NA      |
|ecoli5000.txt  |    160   |   95.77MB   |      0.76      |      NA      |
|ecoli7000.txt  |    194   |    186MB    |      1.41      |      NA      |
|ecoli10000.txt |    223   |    382MB    |      2.98      |      NA      |
|ecoli20000.txt |   3135   |    1.5GB    |      11.50     |      NA      |
|ecoli50000.txt |  killed  |    killed   |       NA       |      NA      |
|ecoli100000.txt|  killed  |    killed   |       NA       |      NA      |

Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
I ran the program with Valgrind and the Massif tool to measure memory usage, while the program itself recorded the execution time for each run. I gathered data from runs using the files ecoli2500.txt, ecoli5000.txt, ecoli10000.txt, and ecoli20000.txt.

Applying the doubling method to this data, I observed that both time and memory approximately quadrupled as the input size doubled. This suggests a quadratic relationship, so I determined the exponent b  to be 2. Using this value of b and my recorded data, I calculated the constant a for each run, then averaged these values to get a reliable estimate for the parameters of the function a * N^b

With these values, I was able to estimate the maximum string length N that the program could handle within a one-day computation limit for both time and memory constraints.
 - a = 0.000000139s
 - b = 2
 - largest N = 788405

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle if limited to 8GiB of RAM.
 - a = 0.00000383MB
 - b = 2
 - largest N = 45703

### Valgrind
Run Valgrind and list any errors you see.  Identify whether the memory usage reported by Valgrind almost matches the calculations in the previous section.

## Pair Programming
If you worked with a partner, do you have any remarks on the pair programming method? E.g., how many times did you switch, what are the tradeoffs of driving vs. navigating, etc.?

## Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

