class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){           //IF LENGTH IS NOT SAME MEANS RETURN EMPTY I.E STRING CAN'T BE FORMED USING OTHER ONE
            return "";
        }
        else{
            return str1.substr(0,gcd(str1.length(),str2.length())); // RETURN FROM STARTING LENGTH OF  SUBSTRINGS I.E 0 TO THE GCD OF SUBSTRINGS OBTAINED
        }
    }
};