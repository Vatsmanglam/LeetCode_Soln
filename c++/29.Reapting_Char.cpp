/*
424. Longest Repeating Character Replacement
Medium
Topics
Companies
You are given a string s and an integer k. You can choose any character of the
string and change it to any other uppercase English character. You can perform
this operation at most k times.

Return the length of the longest substring containing the same letter you can
get after performing the above operations.



Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.


Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

/* Approach
Initialization:
left pointer is initialized to 0.
max_freq keeps track of the maximum frequency of any character in the current
window. char_count is an unordered map to count the frequency of each character
in the current window. max_length keeps track of the maximum length of the valid
window found so far. Iterate with the right pointer: Update the count of the
character at the right pointer in char_count. Update max_freq to be the maximum
frequency of any character in the current window. Shrink the window if
necessary: Check if the current window size minus max_freq < 𝑘. If so, it means
we need more than k replacements to make all characters in the current window
the same, so we shrink the window from the left. Update the count of the
character at the left pointer and move the left pointer to the right. Update the
maximum length: After adjusting the window, update max_length to be the maximum
length of the valid window found so far.

Complexity
Time complexity:O(n)

Space complexity:O(1)
                   */
class Solution {
public:
  int characterReplacement(string s, int k) {
    int left = 0;
    int max_freq = 0;
    unordered_map<char, int> char_count;
    int max_length = 0;

    for (int right = 0; right < s.length(); ++right) {
      char_count[s[right]]++;
      max_freq = max(max_freq, char_count[s[right]]);

      // If the current window size minus the most frequent character count is
      // greater than k, shrink the window
      while ((right - left + 1) - max_freq > k) {
        char_count[s[left]]--;
        left++;
      }

      // Update max_length after adjusting the window
      max_length = max(max_length, right - left + 1);
    }

    return max_length;
  }
};
