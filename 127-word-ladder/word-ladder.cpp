
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to a set for faster lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If the endWord is not in the wordList, return 0
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        // Initialize a queue for BFS, storing {currentWord, steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we reach the endWord, return the steps
            if (word == endWord) 
                return steps;

            // Generate all possible next words
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If the transformed word is in the set
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, steps + 1});
                        wordSet.erase(word); // Remove to avoid revisiting
                    }
                }
                word[i] = originalChar; // Restore the original character
            }
        }

        // If no transformation sequence is found, return 0
        return 0;
    }
};