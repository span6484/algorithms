class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(!N % 2) return {};
        if(N == 1) return { new TreeNode(0) };
        if(memo.count(N)) return memo[N];
        vector<TreeNode*> res;
        for(int i = 1; i < N; i = i + 2) {
            for(auto l : allPossibleFBT(i)) {
                for(auto r : allPossibleFBT(N - i - 1)) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        memo[N] = res;
        return memo[N];
    }
private:
        unordered_map<int, vector<TreeNode*> > memo;

};