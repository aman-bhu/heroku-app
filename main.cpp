#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t = 1; //cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto &x:a)
            cin >> x;
        vector<int> mark;
        int max_col = -1,mn = 1e18, ind;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > max_col)
            {
                mark.push_back(i);
                max_col = a[i];
            }
            else
            {   
                if(mn > a[i])
                {
                    mn = a[i];
                    ind = i;
                }
            }
        }
        int ans, mx = -1;
        if(mn != 1e18)
        {
            mx = mark.size();
            ans = ind;
        }
        mark.push_back(n);
        for(int i = 0; i < mark.size()-1; i++)
        {
            int j = mark[i];
            int k = mark[i+1];
            max_col = (i == 0 ? -1 : a[mark[i-1]]);
            int cnt = 0;
            for(int l = j+1; l < k; l++)
                if(a[l] > max_col)
                {
                    cnt++;
                    max_col = a[l];
                }
            int here = mark.size() - 2 + cnt;
            if(mx < here)
            {
                mx = here;
                ans = j;
            }
        }
        cout << a[ans];
    }    
}
