Problem:: https://leetcode.com/problems/reverse-words-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   string reverseWords(string);
};
// Time Complexity:: O(N)
// Space Complexity:: O(N)
string Solution :: reverseWords(string s) {
        string result = "";
        int i = s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            int cnt = 0;
            if(i<0) break;
            while(i>=0 && s[i]!=' '){
                cnt++;
                i--;
            }
            if(result.empty())
                result.append(s.substr(i+1, cnt));
            else
                result.append(" " + s.substr(i+1, cnt));
        }
        return result;
}

int main(){
    string str;
    getline(cin, str);
    Solution obj;
    string ans = obj.reverseWords(str);
    cout<<"After Reversing The Words "<<endl<<ans<<endl;
    return 0;
}
