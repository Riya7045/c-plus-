class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        
        for(char &ch : s) {
            count[ch-'a']++;
        }
        
        for(char &ch : t) {
            count[ch-'a']--;
        }
        //NOTE : You can also do above in only one for loop.
        /*
            for(int i = 0; i<n; i++) {
                count[s[i]-'a']++;
                count[t[i]-'a']--;
            }
        */
        
        // Check if all elements in the array are 0 --> You can write a for loop as well
        //This is just for learning purpose
        bool allZeros = all_of(begin(count), end(count), [](int element) {
            return element == 0;
        });
        
        return allZeros;
    }
};