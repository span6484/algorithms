class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int fir = INT_MAX;
        int sec = INT_MAX;
        for(auto num : nums) {
            if(num <= fir) fir = num;
            else if(num <= sec) sec = num;
            else return true;
        }
        return false;
    }
};