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

using namespace std;

class SegmentTree {
    private :
        VI segmentTree;
        int n;
        VI arr;
        
        void build(int p,int L,int R){
            if(L == R) {
                segmentTree[p] = L;
                return;
            }
            build(2*p , L , (L + R)/2 );
            build(2*p + 1 , (L + R)/2 + 1, R);
            int left = segmentTree[2*p] , right = segmentTree[2*p + 1];
            // Condition to find MinSigmentTree
            segmentTree[p] = (arr[left]<=arr[right]?left:right);
        }

        int RMQ(int p,int L,int R,int i,int j){
            if(i > R | j < L) return -1; // Out of range.
            if(L >= i && R <= j) return segmentTree[p];

            int minLeft = RMQ(2*p , L , (L+R)/2,i , j);
            int minRight = RMQ(2*p + 1, (L + R)/2 + 1,R, i , j);
            if(minLeft == -1) return minRight;
            // Right is outOf bound
            if(minRight == -1) return minLeft;
            //Condition comparing minLeft and minRight case.
            return (arr[minLeft]<=arr[minRight])?minLeft:minRight;
        }

        void update(int p,int L,int R,int idx,int value){
            if(L == idx && R == idx){
                segmentTree[p] = idx;
                arr[idx] = value;
                return;
            }
            // Update Right Side
            if( idx > (L + R)/2) update(2*p + 1,(L+R)/2 + 1,R,idx,value);
            // Update Left Side
            if(idx <= ((L + R)/2)) update(2*p , L , (L + R)/2, idx,value);
            // Update segmentTree from Left and Right ::
            int minLeft = segmentTree[2*p],minRight = segmentTree[2*p + 1];
            segmentTree[p] = (arr[minLeft] <= arr[minRight])?minLeft:minRight;
        }

    public :
        SegmentTree(const VI arr){
            n = arr.size();
            this -> arr = arr;
            segmentTree.resize(4*n);
            build(1,0,n-1); 
        }

        void updateElement(int idx,int value){
            update(1,0,n-1,idx,value);
        }

        VI getSegmentTree() const {
            return this->segmentTree;
        }
        
        int getMin(int i,int j){
            return arr[RMQ(1,0,n-1,i,j)];
        }
};


int main(){
    int t;

    return 0;
}


