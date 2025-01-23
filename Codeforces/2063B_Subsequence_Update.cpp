#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1e9+7

int ceil(int a, int b){
    if(a%b==0) return a/b;
    return a/b + 1;
}

ll n, m, k, l, r;

bool comparator (ll a, ll b) {
    return a>b;
}

ll minsum (vector<ll>& arr1, vector<ll>& arr2) {
    ll sum = 0;
    ll i=0;
    for(;i< min(arr1.size(), arr2.size()); i++){
            if(arr1[i]<arr2[i]) sum += arr1[i];
            else sum += arr2[i];
    }
    while(i<arr2.size()) {
        sum += arr2[i];
        i++;
    }
    return sum;
}

void solve() {
    cin >> n >> l >> r;

    vector<ll> left, middle, right;
    for(ll i=1; i<=n; i++) {
        ll x;
        cin >> x;
        if(i<l) left.push_back(x);
        else if(i>=l && i<=r) middle.push_back(x);
        else right.push_back(x);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    sort(middle.begin(), middle.end(), comparator);

    ll leftsum = INT_MAX;
    if(left.size()>0) leftsum = minsum(left, middle);
    ll rightsum = INT_MAX;
    if(right.size()>0) rightsum = minsum(right, middle);
    
    if(left.size()==0 && right.size()==0) {
        ll ss=0;
        for(auto it : middle) ss += it;
        cout << ss << endl;
        return;
    }
    cout << min(leftsum, rightsum) << endl;


}

int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}