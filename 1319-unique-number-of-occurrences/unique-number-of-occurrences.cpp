class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> occurrences;

        for (int num : arr) {
            occurrences[num]++;
        }
        std::unordered_set<int> uniqueSet;
        for (const auto& entry : occurrences) {
            if (!uniqueSet.insert(entry.second).second) {
                return false;
            }
        }
        return true;
    }
        
    
};

