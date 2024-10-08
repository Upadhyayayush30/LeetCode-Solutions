/*class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(char &ch: s){
            if(ch=='['){
                st.push(ch);
            }
            else if(!st.empty()){
                st.pop();//balancing the closing bracket ] with an open bracket in the stack
            }
        }
        //size of stack == number of open brackets
        return (st.size()+1)/2;
    }
};*/
class Solution {
public:
    int minSwaps(string s) {
        int size=0;
        for(char &ch: s){
            if(ch=='['){
                size++;
            }
            else if(size>0){
                size--;//balancing the closing bracket ] with an open bracket in the stack
            }
        }
        //size of stack == number of open brackets
        return (size+1)/2;
    }
};