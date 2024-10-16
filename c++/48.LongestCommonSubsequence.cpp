/*
1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common
subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative order
of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both
strings.

Example 1:
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Constraints:
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

// Logic :
/*
what if we just check the text2 in text1 using nested for loops
initialise a variable length=0
length++ for every possible value which is true
else nothing

return length
*/

// Why This Fails:
/* approach would work for counting the number of common characters between the
 * two strings, but it wouldn't handle the requirement that the subsequence must
 * be contiguous in relative order. For example, if text1 was "abcde" and text2
 * was "cde", your approach would fail to check the sequence properly, as it
 * might count characters individually but not in order.
 */

// DP-> check for individual characters, but also their relative order
// order is crucial to determine which characters form a valid subsequence.

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    // Create a 2D DP table to store the lengths of LCS for substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the DP table from the bottom up
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          // If characters match, extend the LCS of the previous substrings
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          // If characters don't match, take the max LCS length so far
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    // The value in dp[m][n] will be the length of the LCS for text1 and text2
    return dp[m][n];
  }
};

int main() {
  string text1 = "abcde";
  string text2 = "ace";
  cout << "Length of LCS: " << Solution.longestCommonSubsequence(text1, text2)
       << endl;
  return 0;
}

// Time Complexity: O(m*n)
// Space Complexity:O(m*n)
