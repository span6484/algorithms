// 注意二分法
// 找一个target是否在里面是[)
// 当自己在内部比较时，[], 和r作比较

// todo 
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size()-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(numbers[mid] < numbers[r]) {
                r = mid;
            } else if(numbers[mid] > numbers[r]) {
                l = mid+1;
            } else {
                r--;
            }
        }
        return numbers[l];
    }
};