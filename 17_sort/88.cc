class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m-1, ptr2 = n-1;
        int ptr = m + n - 1;
        while(ptr1 >= 0 && ptr2 >= 0) {
            nums1[ptr--] = nums1[ptr1] > nums2[ptr2] ? nums1[ptr1--] : nums2[ptr2--];
        }
        for(int i = 0; i <= ptr2; i++) {
            nums1[i] = nums2[i];
        }
    }
};