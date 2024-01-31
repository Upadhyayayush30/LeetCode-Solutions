class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int id = st.top(); st.pop();
                res[id] = i - id;
            }
            st.push(i);
        }

        return res;        
    }
};