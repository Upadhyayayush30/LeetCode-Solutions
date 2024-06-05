class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize the result vector
        vector<string> result;
        
        // Initialize a vector to keep track of the minimum frequency of each character
        vector<int> minFreq(26, INT_MAX);
        
        // Iterate over each word
        for (const string& word : words) {
            // Initialize a vector to count the frequency of each character in the current word
            vector<int> charCount(26, 0);
            
            // Count the frequency of each character in the current word
            for (char c : word) {
                charCount[c - 'a']++;
            }
            
            // Update the minimum frequency of each character
            for (int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], charCount[i]);
            }
        }
        
        // Collect the common characters based on the minimum frequencies
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minFreq[i]; j++) {
                result.push_back(string(1, i + 'a'));
            }
        }
        
        return result;
    }
};
