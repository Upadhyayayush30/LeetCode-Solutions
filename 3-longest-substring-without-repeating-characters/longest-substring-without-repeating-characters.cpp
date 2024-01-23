#define NO_OF_CHARS 256
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        int res=0;
        vector<int>lastIndex(NO_OF_CHARS,-1);
        int j=0;
        for(int i=0;i<n;i++){
                j=max(j,lastIndex[s[i]]+1);

                res=max(res,i-j+1);
                lastIndex[s[i]]=i;
            }
            return res;
        }
    
}; 