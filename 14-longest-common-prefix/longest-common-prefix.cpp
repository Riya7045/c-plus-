class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "" ;
        for(int i = 0 ; i < strs[0].size() ; i++){
            char c = strs[0][i] ; 
            bool flag = 1 ;
            for(int j = 0 ; j < strs.size() ; j++){
                if(strs[j][i] != c)
                    flag = 0;
            }
            if(flag == 1)
                ans += c ;
            else 
                break ; 
        } 
        return ans ;
    }
};