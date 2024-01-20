class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long l[n];
        long long r[n];
        int mod=1000000007;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++)
        {
            int c=1;
            while(!st.empty() && st.top().first>arr[i])
            {
                c+=st.top().second;
                st.pop();
            }
            st.push({arr[i],c});
            l[i]=c;
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--)
        {
            int c=1;
            while(!st.empty() && st.top().first>=arr[i])
            {
                c+=st.top().second;
                st.pop();
            }
            st.push({arr[i],c});
            r[i]=c;
        }
        long long res=0;
        for(int i=0;i<n;i++)
            res=(res%mod+((arr[i]%mod)*(l[i]*r[i])%mod)%mod)%mod;
        return res%mod;
    }
};
