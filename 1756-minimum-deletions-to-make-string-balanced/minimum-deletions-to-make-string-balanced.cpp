class Solution {
public:
    int minimumDeletions(string s) {
        int b_count=0;
        int minDel=0;
        for(char ch : s){
            if(ch=='b'){
                b_count++;
            }
            else{ //if ch=='a'
                minDel=min(minDel+1,b_count);
            }
        }
        return minDel;
    }
};