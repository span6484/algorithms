class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        qsortHelper(nums, 0, nums.size());
    }
    void qsortHelper(vector<int>& nums, int left, int right) {
        if(left >= right-1) return;
        int mid = partition(nums, left, right);
        qsortHelper(nums, left, mid);
        qsortHelper(nums, mid+1, right);
    }
    int partition(vector<int>& nums, int left, int right) {
        int midVal = nums[right-1];
        int i = left;
        for(int j = left; j < right-1; j++) {
            if(nums[j] < midVal) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right-1]);
        return i;
    }
};