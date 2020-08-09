#include <iostream>
#include<time.h>
using namespace std;

// 阶乘
int fact(int n) {
    if(n == 1) return 1;
    return n * fact(n - 1);
}

int main() {
    clock_t st1, et1, st2, et2;
    int fact_num;
    cout << "input fact_num : " << endl;
    cin >> fact_num;
    st1 = clock();
    cout << fact(fact_num) << endl;
    et1 = clock();
    cout << "Cost Time : " << (double)(et1 - st1) /  CLOCKS_PER_SEC << "s" << endl;
    return 0; 
}