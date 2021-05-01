
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if(!employees.size()) return 0;
        unordered_map<int, Employee*> memo;
        for(auto& employee : employees) {
            memo[employee->id] = employee;
        }
        int sum = 0;
        queue<int> que;
        que.push(id);
        while(!que.empty()) {
            int idNum = que.front(); que.pop();
            auto emp = memo[idNum];
            sum += emp->importance;
            auto subList = emp->subordinates;
            for(auto it = subList.begin(); it != subList.end(); it++) {
                que.push(*it);
            }
        }
        return sum;
        
    }
};