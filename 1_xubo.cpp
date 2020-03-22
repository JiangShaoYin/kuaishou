#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 获取队中从前到后每个人与前方身高高于自己的人的最短距离
     * @param height int整型vector 队中从前到后每个人与前方身高高于自己的人的最短距离
     * @return int整型vector
     */
    vector<int> DistanceToHigher(vector<int>& height) {
        if (height.empty()) return vector<int>();
        const int m = height.size();
        vector<int> ret(m, 0);
        for (int i = 1; i < m; i++) {
            int pre = i - 1;
            bool finded = false;
            if (height[pre] > height[i]) {
                ret[i] = 1;
                finded = true;
            } else while (ret[pre] != 0) {
              pre = pre - ret[pre];
              if (height[pre] > height[i]) {
                  ret[i] = i - pre;
                  finded = true;
                  break;
              }
            }
            if (!finded) ret[i] = 0;
        }
        return ret;
    }
};