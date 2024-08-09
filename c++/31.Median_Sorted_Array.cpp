/*
4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

/* Soln->
 Median is the middle element of the sorted array.

 to dono array ko merge karna hai

 to dono array ko sort karna hai
append the 2nd array into 1s array

 sort the array.

 for median just log the middle element
 middle element=nums[(totalSize/2)];
 */
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();

    std::vector<int> mergedArr(size1 + size2);

    std::copy(nums1.begin(), nums1.end(), mergedArr.begin());
    std::copy(nums2.begin(), nums2.end(), mergedArr.begin() + size1);
    std::sort(mergedArr.begin(), mergedArr.end());
    int totalSize = size1 + size2;
    if (totalSize % 2 == 0) {
      return (mergedArr[totalSize / 2 - 1] + mergedArr[totalSize / 2]) / 2.0;
    } else {
      return mergedArr[totalSize / 2];
    }
  }
};
