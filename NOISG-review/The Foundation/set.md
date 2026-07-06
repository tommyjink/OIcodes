# Codebreaker Problem Set

## 1. FizzBuzz

- **Link**: [FizzBuzz](https://codebreaker.xyz/problem/fizzbuzz)

- **Problem Description**:

  Given three integers $N, A$, and $B$. For every integer $i$ from $1$ to $N$:

  - If $i$ is a multiple of both $A$ and $B$, print `FizzBuzz`.
  - If $i$ is a multiple of $A$ (but not $B$), print `Fizz`.
  - If $i$ is a multiple of $B$ (but not $A$), print `Buzz`.
  - Otherwise, print the number $i$.

- **Input**:

  A single line containing three integers: $N, A, B$.

- **Output**:

  $N$ lines, each representing the result for the corresponding number.

- **Sample Input**:

  ```
  7 2 3
  ```

- **Sample Output**:

  ```
  1
  Fizz
  Buzz
  Fizz
  5
  FizzBuzz
  7
  ```

## 2. Old PSLE Grading System

- **Link**: [PSLE](https://codebreaker.xyz/problem/psle)

- **Problem Description**:

  Create a program that takes in a score $s$ and outputs the corresponding grade based on the following scale:

  - **A***: 91 and above
  - **A**: 75 to 90
  - **B**: 60 to 74
  - **C**: 50 to 59
  - **D**: 35 to 49
  - **E**: 20 to 34
  - **U**: Below 20

- **Input**:

  A single non-negative integer not exceeding 100, $s$.

- **Output**:

  The grade that corresponds to the score.

- **Sample Input**:

  ```
  90
  ```

- **Sample Output**:

  ```
  A
  ```

## 3. Maximum

- **Link**: [Maximum](https://codebreaker.xyz/problem/maximum)

- **Problem Description**:

  Input 2 numbers, and output the maximum of the two numbers.

- **Input**:

  The input will consist of 2 integers, $a$ and $b$, one on each line.

- **Output**:

  Output either $a$ or $b$, whichever has the larger value.

- **Sample Input**:

  ```
  5
  3
  ```

- **Sample Output**:

  ```
  5
  ```

## 4. Sum of Integers

- **Link**: [Sum of Integers](https://codebreaker.xyz/problem/sumint)

- **Problem Description**:

  Gary the snail needs you to write a program to sum up how many times he has meowed in $d$ days.

- **Input**:

  The first line is the number of days $d$ ($1 \le d \le 10000$).

  The following line contains $d$ space-separated numbers $d_i$ ($0 \le d_i \le 100000$).

- **Output**:

  The total sum of the integers.

- **Sample Input**:

  ```
  10
  37 17 38 47 29 83 13 2 8 72
  ```

- **Sample Output**:

  ```
  346
  ```

## 5. Right Angled Triangle

- **Link**: [Right Angled Triangle](https://codebreaker.xyz/problem/rightangtri)

- **Problem Description**:

  This problem requires you to print right angled triangles using stars (`*`).

- **Input**:

  A single integer $n$ ($0 < n < 501$) representing the height and width of the triangle.

- **Output**:

  Print a right angled triangle with height $n$ and width $n$.

- **Sample Input**:

  ```
  3
  ```

- **Sample Output**:

  ```
  *
  **
  ***
  ```

------