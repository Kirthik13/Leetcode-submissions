class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int>pq;
        
        for(auto &i:v)
        {
            pq.push(i);
        }
        while(pq.size()>1)
        {
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y)
            {
                pq.push(abs(y-x));
            }
        }
        return pq.size()==1?pq.top():0;
    }
};