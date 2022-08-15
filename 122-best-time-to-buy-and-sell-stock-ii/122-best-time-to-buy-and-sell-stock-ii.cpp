class Solution {
public:
    int fn(vector<int>& v,int idx,int n,int status,vector<vector<int>>&dp)
    {
        if(idx>=n)
        {
            return 0;
        }
         if(  dp[idx][status]!=-1)return dp[idx][status];
        int curr=0;
        
        if(status==0)
        {
            
           int buy=fn(v,idx+1,n,1,dp)-v[idx];
           int notbuy=fn(v,idx+1,n,0,dp);
        
            curr=max(buy,notbuy);
            
        }
        if(status)
        {
          int sell=fn(v,idx+1,n,0,dp)+v[idx];
           int notsell=fn(v,idx+1,n,1,dp);
        
            curr=max(sell,notsell);
        }
    return dp[idx][status]=curr;
    }
    int maxProfit(vector<int>& v) {
        
        int n=v.size();
        vector<int>dp(2,0);
        
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int status=1;status>=0;status--)
            {
                 int curr=0;
        
                if(status==0)
                {

                   int buy=dp[1]-v[idx];
                   int notbuy=dp[0];

                    curr=max(buy,notbuy);

                }
                if(status)
                {
                  int sell=dp[0]+v[idx];
                   int notsell=dp[1];

                    curr=max(sell,notsell);
                }
                
                dp[status]=curr;
            }
        }
        
        return dp[0];
        // return fn(v,0,n,0,dp);
    }
};