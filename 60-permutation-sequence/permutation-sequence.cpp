class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1; i<=n; i++){ //step 1: make string 
            s.push_back(i + '0');
        }
        for(int i=1; i<k; i++){
            next_permutation(s.begin(), s.end()); // count k-1 more next permutation.
        }
        return s;
        
    }
};