class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    queue<int> q;
    vector<bool> used(1001, false), have(1001, false);
    for (int b : initialBoxes) {
        have[b] = true;
        if (status[b]) q.push(b);
    }
    int ans = 0;
    while (!q.empty()) {
        int b = q.front(); q.pop();
        if (used[b]) continue;
        used[b] = true;
        ans += candies[b];
        for (int k : keys[b]) {
            status[k] = 1;
            if (have[k] && !used[k]) q.push(k);
        }
        for (int x : containedBoxes[b]) {
            have[x] = true;
            if (status[x] && !used[x]) q.push(x);
        }
    }
    return ans;
}
};