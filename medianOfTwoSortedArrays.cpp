// BRUTE FORCE SOLUTION 
// TIME COMPLEXITY : O(M+N)
// SPACE COMPLEXITY:O(M+N)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Declare a list for the merged result
        vector<int> merged;
        int i = 0;
        int j = 0;

        // Merge the two sorted arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        // Add the remaining elements from nums1, if any
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add the remaining elements from nums2, if any
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        // Determine the median element
        int size = merged.size();

        if (size % 2 != 0) { // Odd size
            return merged[size / 2];
        } else { // Even size
            int mid1 = size / 2 - 1; // First middle element index
            int mid2 = size / 2;     // Second middle element index
            return (merged[mid1] + merged[mid2]) / 2.0;
        }
    }
};
