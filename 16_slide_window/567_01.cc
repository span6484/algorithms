class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> memo(128, 0);
        int counter = s1.size();
        int left = 0, right = 0;
        for(auto c : s1) {
            memo[c]++;
        }
        while(right < s2.size()) {
            if(memo[s2[right]] > 0) {
                counter--;
            }
            memo[s2[right]]--;
            right++;
            while(counter == 0) {
                if(right - left == s1.size()) return true;
                memo[s2[left]]++;
                if(memo[s2[left]] > 0) {
                    counter++;
                }
                left++;
            }
        }
        return false;
    }
};