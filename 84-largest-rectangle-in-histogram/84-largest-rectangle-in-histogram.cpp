class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size();
int i=0;

int ans=INT_MIN;
stack<int>st;
for(int i=0;i<=n;i++)
{
    while(!st.empty() and ((i==n) or v[st.top()]>=v[i]))
    {
        int h=v[st.top()];
        st.pop();
        int w;
        if(st.empty()) 
        {
            w=i;
        }
        else {
            w=i-st.top()-1;
        }
        ans=max(ans,w*h);
    }
    st.push(i);
}
        return ans;
    }
};