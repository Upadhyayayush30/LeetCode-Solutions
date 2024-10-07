class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>result;
        int maxOfcandies=0;   //MAX OF CANDIES ARRAY
        int n =candies.size();
        maxOfcandies=*max_element(candies.begin(),candies.end());
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxOfcandies){    //IF GREATER THEN PUSH TRUE ELSE FALSE
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
            
        }
        return result;
    }

};