class Solution {
public:
    string longestPalindrome(string s) {
          int n=s.size();
      
       bool dp[n][n];
        string ans;
        for(int i=n-1;i>=0;i--)
        {
            int maxj=i;
            for(int j=i;j<n;j++)
            {
               dp[i][j]=(s[i]==s[j] and (j-i<3 or dp[i+1][j-1] ));
               if(dp[i][j] )
               {
                   maxj=j;
               }
              
            }
            if(ans.size()==0 or ans.size()<maxj-i+1)
            {
                    
                    ans=s.substr(i,maxj-i+1);
            }
            
           
        }
        return ans;
    }
};