class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int i = 0, j = sz-1;
        int res = 0;
        while(i < j) {
            res = max(res, min(height[i], height[j]) * (j-i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};