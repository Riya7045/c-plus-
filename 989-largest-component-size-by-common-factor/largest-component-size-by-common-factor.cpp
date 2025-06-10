class UnionFind {
    public:
    vector<int> par, sz;
    UnionFind(int n) : par(n), sz(n,1) {
        iota(begin(par), end(par), 0);
    }
    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool Union(int x, int y) {
        int xp = find(x), yp = find(y);
        if(xp == yp) return false;
        if(sz[xp] > sz[yp]) par[yp] = par[xp], sz[xp] += sz[yp];
        else par[xp] = par[yp], sz[yp] += sz[xp];
        return true;
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = size(nums), ans = 1;
        UnionFind uf(n + 1);
        unordered_map<int, vector<int>> mp;             // stores {p : [indices of nums for which p is prime factor]}
        for(int i = 0; i < n; i++) {                    // prime factorize nums[i]
            int cur = nums[i];
            if(cur % 2 == 0) {                          // 2 is prime factor of nums[i]
                mp[2].push_back(i);
                while(cur % 2 == 0) cur >>= 1;
            }
            for(int p = 3; p <= sqrt(cur); p += 2)      // now check for all odd numbers if it is factor of nums[i]
                if(cur % p == 0) {                      // p is prime factor of nums[i]
                    mp[p].push_back(i);
                    while(cur % p == 0) cur /= p;
                }
            
            if(cur > 1) mp[cur].push_back(i);           // nums[i] itself is prime
        }
        
        for(auto& [prime, ids] : mp)                    // union all element index that have same prime
            for(int i = 0; i < size(ids)-1; i++) 
                uf.Union(ids[i], ids[i+1]);
        
        return *max_element(begin(uf.sz), end(uf.sz));  // return largest component
    }
};