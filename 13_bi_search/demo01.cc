#include <vector>
#include <iostream>
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort

int main() {
    std::vector<int> v = { 1, 2, 2, 2, 4, 4, 5, 7 };
    std::cout << *std::lower_bound(v.begin(), v.end(), 3) << std::endl;  // first index of i, such that A[i] >= x
    std::cout << *std::upper_bound(v.begin(), v.end(), 4) << std::endl;  // first index of i, such taht A[i] > x


}