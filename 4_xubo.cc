#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int> > energe(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp;
            cin >> tmp;
            energe[i][j] = tmp;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - b + 1; j++) {
            int sum = 0, minNum = INT_MAX;
            for (int l = i; l < i + a; l++) {
                for (int r = j; r < j + b; r++) {
                    if (energe[l][r] < minNum) 
                        minNum = energe[l][r];
                    sum += energe[l][r];
                }
            }
        }
    }
}