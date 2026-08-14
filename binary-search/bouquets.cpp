#include <bits/stdc++.h>
using namespace std;
/*
Input:
n m k
bloomDay[0] bloomDay[1] ... bloomDay[n-1]
Output:
Minimum number of days needed, or -1 if impossible.
*/
class Solution {
private:
    bool possible(vector<int>& bloomDay, int m, int k, int val) {
        int n = bloomDay.size();
        int currTaken = 0;
        for (int i = 0; i < n; i++) {
            if (m <= 0) return true;
            if (bloomDay[i] <= val) {
                currTaken++;
                if (currTaken % k == 0) {
                    currTaken = 0;
                    m--;
                }
            }
            else {
                currTaken = 0;
            }
        }
        return m <= 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < (long long)m * k) return -1;
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(bloomDay, m, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
//Time Complexity: O(n * log(max(bloomDay)))
//Space Complexity: O(1) excluding the input array
};
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++) cin >> bloomDay[i];
    Solution sol;
    cout << sol.minDays(bloomDay, m, k) << '\n';
    return 0;
}