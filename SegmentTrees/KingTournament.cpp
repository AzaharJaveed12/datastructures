/*

    CODEFORCES : https://codeforces.com/contest/356/problem/A
    NOTDONE.
*/

#include<bits/stdc++.h>
#define LL             long long
#define II             pair<int,int>
#define VI             vector<int>
#define VVI            vector<VI>
#define VLL            vector<LL>
#define VII            vector<II>
#define VVLL           vector<VLL>
#define VVII           vector<vector<II>>
#define VS             vector<string>
#define MMS0(a)        memset(a,0,sizeof(a))
#define MMS1(a)        memset(a,-1,sizeof(a))
#define AR             array
#define PB             push_back
#define FF             first
#define SS             second
#define FOR(n)         for(int i=0;i<n;i++)
#define RFOR(n,a)      for(int i=n;i>=a;i--)
#define FR(i,a,n,c)    for(int i=a;i<n;i+=c)
#define RFR(i,n,a,c)   for(int i=n;i>=a;i-=c)
#define DEB1(a)        cout<<#a<<" "<<a<<"\n"
#define DEB2(a,b)      cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"
#define DEB3(a,b,c)    cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<"\n"
#define MOD7           (int)1e9+7
#define MOD9           (int)1e9+9
#define INF9            (int)1e9
#define NINF9           (int)-1e9
#define LINF18            (ll)1e18
#define LNINF18           (ll)-1e18
#define PV(v)          for(auto it:v)cout<<it<<" ";cout<<"\n"
#define PMP(v)         for(auto it:v)cout<<it.ff<<":"<<it.ss<<" ";cout<<"\n"           
#define L_B            lower_bound
#define U_B            upper_bound
#define _              0
#define FIO            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ALL(a)         a.begin(),a.end()
#define PPB            pop_back
#define MKP            make_pair

using namespace std;



int main(){
    int n,m;
    cin>>n>>m;
    set<int> st;
    //FOR(n+2) st.insert(i);
    for(int i=1;i<=n;i++) st.insert(i);
    VI ans(n,0);
    FOR(m){
        int a,b,x;
        cin>>a>>b>>x;
     //   DEB3(a,b,x);
        for(auto it = st.lower_bound(a);it != st.end();){
                if(it== st.end()) break;
                if(it == st.upper_bound(b)) break; 
               // cout<<*it<<"#-----#";
                auto next = it;
                it++;
                if((*next) != x ) {
                    ans[(*next) - 1] = x;
                 //   cout<<(*next)<<" "<<x<<"\n";
                    st.erase(next);
                }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}