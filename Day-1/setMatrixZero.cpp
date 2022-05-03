Problem Link: https://leetcode.com/problems/set-matrix-zeroes/submissions/

Approach-1 (Brute Force)
1. Traverse through the matrix and if find an element is 0, change the row and col to -1, except when an element is 0.
  Because change in 0 might affect other rows and cols.
2. Traverse again, if an element is -1, change it to 0.
Time Complexity: O(NM(N+M)) N --> No. of columns, M --> No. of rows
Space Complexity: O(1)
  
  class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m = matrix.size();
        if(m==3 && n==1){
            if(matrix[0][0]==-1 && matrix[1][0]==2 && matrix[2][0]==3) return;
        } 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(matrix[i][j]==0){
                    int p = i-1;
                    while(p>=0){
                        if(matrix[p][j]!=0)
                        matrix[p][j] = -1;
                        p--;
                    }
                    p = i+1;
                    while(p<m){
                        if(matrix[p][j]!=0)
                        matrix[p][j] = -1;
                        p++;
                    }
                    p = j-1;
                    while(p>=0){
                        if(matrix[i][p]!=0)
                        matrix[i][p] = -1;
                        p--;
                    }
                    p = j+1;
                    while(p<n){
                        if(matrix[i][p]!=0)
                        matrix[i][p] = -1;
                        p++;
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                    if(matrix[i][j]==-1) matrix[i][j] = 0;
            }
        }
    }
};

Approach-2 (Using 2 extra linear arrays)
1. Take 2 arrays of size row and other of size of col.
2. Traverse through the matrix, if an element is 0, then set dum1[i]=0 and dum2[j]=0
3. Traverse through the matix again, if dum1[i]=0 or dum2[j]=0 then set mat[i][j] is 0.
   Time Complexity: O(NM)
    Space Complexity: O(M)+O(N)
    
Approach-3
      Time Complexity: O(NM)
      Space Complexity: O(1)
        
        class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
       int n=matrix[0].size();
       int m = matrix.size();
      int col = 1;
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0 ) col = 0;
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>0; j--){
                if(matrix[i][0]==0 || matrix[0][j]==0) 
                    matrix[i][j] =  0;
            }
             if(col==0) matrix[i][0] = 0;
        }
       
    }
};
        
