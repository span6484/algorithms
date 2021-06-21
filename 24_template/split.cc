#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s) {
    istringstream in(s);
    vector<string> vec;
    string tmp;
    while(getline(in, tmp, ' ')) {
        if(tmp.size()) vec.push_back(tmp);
    }
    return vec;
}

void test01() {
    vector<string> res = split("aa bb c");
    for(auto& r : res) {
        cout << r << endl;
    }
}

void test02() {
    vector<string> res = split(" aa  bb   c    ");
    for(auto& r : res) {
        cout << r << endl;
    }
}


int main() {
    // test01();
    test02();
}