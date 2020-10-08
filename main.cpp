#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t = 1; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        int ans = 0;
        for(int i = 0; i < (n+1)/2; i++)
            for(int j = 0; j < (m+1)/2; j++)
            {
                map<pair<int,int>,bool> mp;
                vector<int> num;
                mp[{i,j}] = 1;
                num.push_back(a[i][j]);
                if(mp[{n-1-i,j}] == 0)
                {
                    mp[{n-1-i,j}] = 1;
                    num.push_back(a[n-1-i][j]);
                }
                if(mp[{i,m-1-j}] == 0)
                {
                    mp[{i,m-1-j}] = 1;
                    num.push_back(a[i][m-1-j]);
                }
                if(mp[{n-1-i,m-1-j}] == 0)
                {
                    mp[{n-1-i,m-1-j}] = 1;
                    num.push_back(a[n-1-i][m-1-j]);
                }
                sort(num.begin(),num.end());
                int idx = num.size() - 1;
                idx /= 2;
                for(auto x:num)
                    ans += abs(x - num[idx]);
            }
        cout << ans << endl;
    }    
}
