#include<bits/stdc++.h>

using namespace std;

int main(){
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    cout<<*(st.lower_bound(2))<<" "<<*(st.upper_bound(5))<<"\n";
    st.erase(2);
    cout<<*(st.lower_bound(2))<<" "<<*(st.upper_bound(5))<<"\n";
    return 0;

}