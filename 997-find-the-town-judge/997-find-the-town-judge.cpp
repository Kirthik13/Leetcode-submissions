class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
//         vector<int>town(n+1,0);
//                 vector<int>F(n+1,0);
//         int ans=0;
//         int c=0;
//         for(auto i:v)
//         {
//             F[i[0]]=1;
//             town[i[1]]++;
//         }
        
//         for(int i=1;i<=n;i++)
//         {
//             if(!F[i])
//             {
//                 c++;
//                 ans=i;
//             }
//         }
        
//         if(c!=1 or town[ans]!=n-1)
//         {
//             return -1;
            
//         }
        
        
        vector<int>town(n+1);
            vector<int>people(n+1);
        for(auto &i:v)
        {
            ++people[i[0]];
            ++town[i[1]];

        }
        int ans=-1,c{};
        for(int i=1;i<=n;i++)
        {
            if(people[i]==0)
            {
                ans=i;
                c++;
            }
        }
        
        if(c!=1 or town[ans]!=n-1)
        {
            return -1;
        }
        return ans;

    }
};