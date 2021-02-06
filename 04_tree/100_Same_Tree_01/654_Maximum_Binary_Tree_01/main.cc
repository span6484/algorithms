class Solution {
public:
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if(lo >= hi) return nullptr;
        int maxVal = INT_MIN;
        int idx;
        for(int i = lo; i < hi; i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(maxVal);
        root->left = build(nums, lo, idx);
        root->right = build(nums, idx+1, hi);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};