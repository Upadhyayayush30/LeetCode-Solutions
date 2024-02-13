class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            if(words[i]==tmp){
                return words[i];
            }

        }
        return "";  
    }
};