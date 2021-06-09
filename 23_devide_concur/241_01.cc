class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> count;
        for(int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if(c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(auto & l : left) {
                    for(auto& r : right) {
                        if(c == '+') {
                            count.push_back(l + r);
                        } else if(c == '-') {
                            count.push_back(l - r);
                        } else if(c == '*') {
                            count.push_back(l * r);
                        }
                    }
                }
            }
        }
        if(count.size() == 0) count.push_back(stoi(expression));
        return count;
    }
};