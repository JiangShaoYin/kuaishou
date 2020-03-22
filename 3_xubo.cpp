#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
#include <istream>
using namespace std;
int processNum(string num, int& beautifulType) {
    int orderedCnt = 1, sameCnt = 1;
    int maxOCnt = 0, maxSCnt = 0;
    for (int i = 4; i < 11; i++) {
        if (num[i] - num[i-1] == 1) {
            orderedCnt++;
        } else orderedCnt = 1;
        if (orderedCnt > maxOCnt) maxOCnt = orderedCnt;
    }
    for (int i = 4; i < 11; i++) {
        if (num[i] == num[i-1]) {
            sameCnt++;
        } else sameCnt = 1;
        if (sameCnt > maxSCnt) maxSCnt = sameCnt;
    }
    if (maxOCnt < 3 && maxSCnt < 3) {
        beautifulType = 0;
        return -1;
    }
    beautifulType = (maxSCnt >= maxOCnt ? 2 : 1);
    return (maxSCnt >= maxOCnt ? maxSCnt : maxOCnt);  
}
struct cmp {
    bool operator()(const pair<string, pair<int, int> >& a, const pair<string, pair<int, int> >& b) {
        if (a.second.first != b.second.first)
            return a.second.first > b.second.first;
        else {
            return a.second.second >= b.second.second;
        }
    }
};
int main() {
    string input;
    vector<string> nums;
    vector<pair<string, pair<int, int> > > beautifulNums;
    while (cin >> input) {
        istringstream iss(input);
        int integer;
        char ch;
        while (iss >> integer) {
            nums.push_back(std::to_string(integer));
            iss >> ch;
        }
    }
    for (auto num : nums) {
        int beautifulType = 0; //豹子号还是顺子号还是普通号， 普通号为0，顺子号为1，豹子号为2
        int weight = processNum(num, beautifulType);
        if (beautifulType != 0) {
            beautifulNums.push_back(make_pair(num, make_pair(weight, beautifulType)));
        }
    }
    if (beautifulNums.empty()) {
        cout << "null" << endl;
        return 0;
    }
    sort(beautifulNums.begin(), beautifulNums.end(), cmp());
    for (int i = 0; i < beautifulNums.size(); i++) {
        cout << beautifulNums[i].first;
        if (i != beautifulNums.size() - 1)
          cout << ",";
    }
    cout << endl;
    return 0;
}
