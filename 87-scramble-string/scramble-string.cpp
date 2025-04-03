class Solution {
public:
    unordered_map<string, bool> mp;
    bool check(string s, string t) {
        if (s == t)
            return true;
        string key = s + "|" + t;
        if (mp.count(key))
            return mp[key];
        bool res = false;
        int m = s.size();
        for (int idx{}; idx < m - 1; idx++) {
            bool notSwap = check(s.substr(0, idx + 1), t.substr(0, idx + 1)) &&
                           check(s.substr(idx + 1), t.substr(idx + 1));
            bool swap = check(s.substr(idx + 1), t.substr(0, m - idx - 1)) &&
                        check(s.substr(0, idx + 1), t.substr(m - idx - 1));

            if (swap || notSwap) {
                res = true;
                break;
            }
        }
        return mp[key] = res;
    }
    bool isScramble(string s, string t) {
        if (s.size() != t.size())
            return false;
        return check(s, t);
    }
};