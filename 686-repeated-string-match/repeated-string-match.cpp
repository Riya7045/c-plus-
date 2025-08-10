#include <iostream>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a; // Start with one copy of a
        int count = 1;       // This is our repeat counter

        // Keep appending a until repeated is at least as long as b
        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        // Check if b is a substring now
        if (repeated.find(b) != string::npos) 
            return count;

        // Append one more time to handle overlapping b
        repeated += a;
        count++;

        // Check again
        if (repeated.find(b) != string::npos) 
            return count;

        // If still not found, it's impossible
        return -1;
    }
};