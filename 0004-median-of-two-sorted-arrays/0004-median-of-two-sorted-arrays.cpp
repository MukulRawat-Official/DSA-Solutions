class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // Merge the sorted arrays into a single array
        vector<int> mergedArray(nums1.size() + nums2.size());
        
        int idxNums1 = 0; // Index for nums1
        int idxNums2 = 0; // Index for nums2
        
        // Merge the arrays while maintaining the sorted order
        for(int i = 0; i < mergedArray.size(); i++) {
            if (idxNums2 != nums2.size() && (idxNums1 == nums1.size() || nums2[idxNums2] < nums1[idxNums1])) {
                mergedArray[i] = nums2[idxNums2++];
            } else {
                mergedArray[i] = nums1[idxNums1++];
            }
        }
        
        // Calculate the median of the merged array
        if (mergedArray.size() % 2 == 1) {
            return mergedArray[mergedArray.size() / 2];
        } else {
            return ((mergedArray[mergedArray.size() / 2]) + (mergedArray[mergedArray.size() / 2 - 1])) / 2.0;
        }
    }
};