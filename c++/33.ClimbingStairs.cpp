/*
 70. Climbing Stairs
Easy
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

/*
 * n steps -> subtract either 1 or 2 steps at a time
 * also if we have a number of steps that is a multiple of 3, we can climb 1 or
2 steps at a time
 * if(n<2){
            return 1;
        }
        if(n==2){
            return 2;
        }

earlier proposed solution:

class Solution {
public:
    int climbStairs(int n) {
        if(n<2){
            return 1;
        }
        if(n==2){
            return 2;
        }

        if(n>2){
            return climbStairs(n-2)+climbStairs(n-1);
        }
        return n;
    }
};

problem with this solution: Time limit exceeded

so what can be alter approach
take it as a array
with the first element being the number of steps to reach the top=0
and the second element being the number of steps to reach the top=1
and then the nth element being the number of steps to reach the top=[n-1]+[n-2]


Step by Step Algorithm
Initialization of dp array: We create an array dp of size (n + 1) and initialize
all its elements to 0.

dp = [0] * (n + 1)
Base Cases: We set the values of dp[0] and dp[1] to 1. This is because there's
only one way to climb 0 or 1 step.

dp[0] = 1
dp[1] = 1
Iterative Step: We iterate from 2 to n (inclusive) to fill in the dp array with
the number of ways to climb i steps.

for i in range(2, n + 1):
    dp[i] = dp[i-1] + dp[i-2]
For each step i, the number of ways to reach that step is the sum of the number
of ways to reach i-1 steps (if we climb 1 step from i-1) and the number of ways
to reach i-2 steps (if we climb 2 steps from i-2). Return Result: We return the
last element of the dp array, which represents the number of ways to climb n
steps.

return dp[-1]
This algorithm utilizes dynamic programming to efficiently compute the number of
ways to climb the staircase. It avoids redundant calculations by storing
previously computed results in the dp array.

Time complexity: O(n)
Space complexity: O(n)
 */

class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
