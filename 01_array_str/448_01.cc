class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        vector<int> res;
        for(int i = 1; i <= nums.size(); i++) {
            s.insert(i);
        }
        for(auto num : nums) {
            s.erase(num);
        }
        for(auto it = s.begin(); it != s.end(); it++) {
            res.push_back(*it);
        }
        return res;
    }
};