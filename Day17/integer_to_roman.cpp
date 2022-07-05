Problem Link:: https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
       map<int, string> mp = {
           {1 , "I"}, {5 , "V"}, {4 , "IV"},  {9 , "IX"}, {10 , "X"}, {40 , "XL"},{50 , "L"}, 
           {90, "XC"), {100 , "C"},  {400 , "CD"},  {500 , "D"}, {900 ,  "CM"}, {1000 , "M"}
       };
       for(auto it = mp.rbegin(); it!=mp.rend(); it++){
           while(it->first<=num){
                    ans += it->second;
                    num -= it->first;
            }
        }
        return ans;
    }
};
