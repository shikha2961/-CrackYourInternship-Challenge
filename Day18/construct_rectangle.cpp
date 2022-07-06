// Problem Link:: https://leetcode.com/problems/construct-the-rectangle/


// Time Complexity:: O(logn)
// Space Complexity:: O(1)

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int i=sqrt(area); i>0; i--){
            if((area%i)==0){
                return {area/i, i};
            }
        }
        return {};
    }
};

// L-W min
// L>=W
// area = L*W
// W<=sqrt(area)

    
    
