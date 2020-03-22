#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int num;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    if (nums.size() < 2) {
        cout << "-1" << endl;
        return 0;
    }
    int maxNum = max(nums[0], nums[1]), secondNum = min(nums[0], nums[1]);
    int cnt = 0;
    if (nums[0] > nums[1]) {
        cout << "1 ";
        cnt++;
    }
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] >= maxNum) {
            secondNum = maxNum;
            maxNum = nums[i];
        } else if (nums[i] >= secondNum) {
            cout << i << " ";
            secondNum = nums[i];
            cnt++;
        }
    }
    if (cnt == 0) cout << "-1" << endl;
}