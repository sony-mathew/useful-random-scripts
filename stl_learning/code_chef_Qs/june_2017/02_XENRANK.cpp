/*
https://www.codechef.com/JUNE17/problems/XENRANK/

Xenny reverse-engineered all the binaries released by the International Security Agency (ISA) during summer vacation just to pass time. As a reward, the ISA gave him infinite ByteCoins.

Out of sheer boredom and a sense of purposelessness in life, Xenny decided to arrange the Coins on a 2-Dimensional Euclidean Plane. The boredom was so strong that he arranged these coins in a specific pattern, as opposed to the usual, monotonous way of storing coins in a Piggy Bank.

On each integer co-ordinate (x, y) where x ≥ 0 and y ≥ 0, a single coin was placed. And each coin was assigned a rank. The following pattern was followed in the arrangement:

Let's denote the co-ordinates of the kth coin by (xk, yk) and its rank by Rk.


For any 2 coins i, j:

if (xi + yi) < (xj + yj) or ( (xi + yi) == (xj + yj) and xi < xj)

then Ri < Rj. We sort all the coins by this comparison.

The index of the coin (C) in this sorted list of coins (1-indexed) is its rank.

Each query is as follows: Given (U, V). Among the coins that are lying on or inside the rectangle with its diagonal end-points being (0, 0) and (U, V), which is the coin that has the maximum rank?

Input
The first line contains an integer, T - the number of testcases.

Each testcase contains 2 space-separated integers: U, V.

Output
For each testcase, print the rank of the maximum ranked coin, on a new line.
Constraints
Subtask 1: (40 points)

1 ≤ T ≤ 100
1 ≤ U, V ≤ 100
Subtask 2: (60 points)

1 ≤ T ≤ 100
1 ≤ U, V ≤ 109
Sample Testcase
Input:
1
1 2

Output:
8

*/
#include <iostream>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main() {
  long long int t, u, v, sum, max_rank, min_rank;
  cin >> t;
  REP(i, t) {
    cin >> u >> v;
    sum = u + v + 1;
    max_rank = ((sum * (sum + 1))/2);
    min_rank = max_rank - (sum - 1);
    cout << (min_rank + u) << endl;
  }
  return 0;
}