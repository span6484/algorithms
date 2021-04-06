class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vec;
        string res;
        for(auto & num : nums) {
            vec.emplace_back(to_string(num));
        }
        sort(vec.begin(), vec.end(), [](string& x, string& y) { return x+y < y+x; } );
        for(auto& s : vec) {
            res += s;
        }
        return res;
    }
};