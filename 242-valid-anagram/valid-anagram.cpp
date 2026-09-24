class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int>counter;
        for(int ch:s){
            counter[ch]=counter[ch]+1;
        }
        for(int ch:t){
            if(counter.find(ch)==counter.end()||counter[ch]==0){
                return false;
            }
            counter[ch]=counter[ch]-1;
        }
        return true;
    }
};