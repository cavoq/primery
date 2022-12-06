# Prime Generator
Comparison of different algorithms for generating prime numbers in a given range from [x, y].

## Supported Algorithms

### *Trial Division Algorithm*

**1. Description**

Trial division is an algorithm used to generate prime numbers in a given range from start to end. It works by dividing each number in the given range by all prime numbers less than or equal to the square root of the number itself. If the number is not divisible by any of the prime numbers, then it is considered to be a prime number. 

**2. Time complexity**

The time complexity of the optimized version of the trial division algorithm when used to generate prime numbers in a given range from start to end is **O(n log log n)**. This is because the algorithm must check each number in the given range, and then divide each number by all prime numbers up to the square root of the number itself. This means that the time complexity is dependent on the number of prime numbers in the range, which is directly proportional to loglogn.