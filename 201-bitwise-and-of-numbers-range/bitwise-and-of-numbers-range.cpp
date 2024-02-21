
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cntr = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cntr++;
        }
        return (left << cntr);
    }
};
