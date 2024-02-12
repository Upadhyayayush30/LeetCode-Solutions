class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ctr=0;
        int elem=0;
        for(int i=0;i<n;i++){
            if(ctr==0){
                elem=nums[i];
                ctr=1;
            }
            else if(elem==nums[i]){
                ctr++;
            }
            else{
                ctr--;
            }
        }
        return elem;
    }
};