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
/*
APPROACH WITHOUT USING GCD FUNCTION AND CALCULATING MANUALLY
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if concatenation of str1+str2 equals str2+str1
        if (str1 + str2 != str2 + str1) {
            return ""; // If not, return empty string
        }
        
        // Calculate GCD of lengths manually
        int len1 = str1.length();
        int len2 = str2.length();
        
        // Manually find the GCD using the Euclidean algorithm
        while (len2 != 0) {
            int temp = len2;
            len2 = len1 % len2;
            len1 = temp;
        }
        
        // Return the substring from the beginning of str1 of length len1
        return str1.substr(0, len1);
    }
};
*/