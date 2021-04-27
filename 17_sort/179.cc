class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string res;
        for(auto& i : nums) {
            res += to_string(i);
        }
        return res[0] == '0' ? "0" : res;
    }
};