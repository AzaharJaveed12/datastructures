/*

codeforces :: https://codeforces.com/contest/339/problem/D

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

class SegmentTree {
    private :
        VLL segmentTree;
        LL n;
        VLL arr;
        bool top;
        void build(int p,int L,int R,bool OR = false){
            if(L == R) {
                segmentTree[p] = arr[L];
                return;
            }
            build(2*p , L , (L + R)/2 ,!OR );
            build(2*p + 1 , (L + R)/2 + 1, R ,!OR);
            int left = segmentTree[2*p] , right = segmentTree[2*p + 1];
            // Condition to find MinSigmentTree
            //segmentTree[p] = (arr[left]<=arr[right]?left:right);
            if(OR){
                segmentTree[p] = left | right;
            }else{
                segmentTree[p] = left ^ right;
            }
        }

        void update(int p,int L,int R,int idx,int value,bool OR=false){
            if(L == idx && R == idx){
                segmentTree[p] = value;
                arr[idx] = value;
                return;
            }
            // Update Right Side
            if( idx > (L + R)/2) update(2*p + 1,(L+R)/2 + 1,R,idx,value,!OR);
            // Update Left Side
            if(idx <= ((L + R)/2)) update(2*p , L , (L + R)/2, idx,value,!OR);
            // Update segmentTree from Left and Right ::
            int minLeft = segmentTree[2*p],minRight = segmentTree[2*p + 1];
            if(OR){
                segmentTree[p] = minLeft | minRight;
            }else{
                segmentTree[p] = minLeft ^ minRight;
            }
        }

    public :
        SegmentTree(const VLL arr,bool top){
            n = arr.size();
            this -> top =top;
            this -> arr = arr;
            segmentTree.resize(4*n);
            build(1,0,n-1,top); 
        }
        void updateElement(int idx,int value){
            update(1,0,n-1,idx,value,top);
        }
        int getElementAt(int i){
            return segmentTree[i];
        }
        VLL getSegmentTree(){
            return segmentTree;
        }
};


int main(){
	LL n,m;
    cin>>n>>m;
    bool top = n%2;
    n = 1<<n;
    VLL v(n,0);
    FOR(n){
        cin>>v[i];
    }
    //PV(v);
    SegmentTree st(v,top);
    VLL S = st.getSegmentTree();
   // for(auto it:S) cout<<it<<" ";cout<<"\n"; 
    while(m--){
        int a,b;
        cin>>a>>b;
     //   DEB2(a,b);
        a--;
        st.updateElement(a,b);
        cout<<st.getElementAt(1)<<"\n";    
    }
	return 0;
}


