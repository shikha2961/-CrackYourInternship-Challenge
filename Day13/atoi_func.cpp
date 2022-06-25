Problem: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        int n=s.length();
        int i=0;
        while(i<n && s[i]==' ')i++;
        int sign = 1;
        if(i<n)
        {
            if(s[i]=='-')sign=-1,i++;
            else if(s[i]=='+')i++;
            
            while(i<n && isdigit(s[i]))
            {
                ans = ans*10 + (s[i]-'0');
                i++;
                if(ans > INT_MAX && sign == -1)return INT_MIN;
                if(ans > INT_MAX && sign ==1)return INT_MAX;
            }
        }
        ans*=sign;
            return ans;
    }
};
