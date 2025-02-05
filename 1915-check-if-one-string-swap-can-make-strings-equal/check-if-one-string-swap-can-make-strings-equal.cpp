class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true; // If both strings are already equal, return true
        
        string s3 = s1;
        string s4 = s2;
        int count = 0; // Declare count properly
        int str = -1;  // Variable to store the first mismatch index

        sort(s3.begin(), s3.end());
        sort(s4.begin(), s4.end());

        if (s3 == s4) { // Check if the sorted versions of the strings match
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) {
                    count++;
                    if (count == 1) {
                        str = i; // Store first mismatch index
                    } else if (count == 2) {
                        swap(s1[str], s1[i]); // Swap the two mismatched characters
                        return s1 == s2; // Check if swapping makes the strings equal
                    } else {
                        return false; // More than two mismatches means we can't swap to fix it
                    }
                }
            }
        }
        return false; // If sorting doesn't match, return false
    }
};
