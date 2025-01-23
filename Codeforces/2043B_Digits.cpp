#include<bits/stdc++.h>
using namespace std;

int ceil(int a, int b){
    if(a%b==0) return a/b;
    return a/b + 1;
}

unsigned long long factorial(int n) {
  if (n < 0) {
    return 0;
  }
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

bool isDivisibleBy3(long long& total, int d) {
    long long sum  = total * d;
    return (sum % 3 == 0);
}

bool isDivisibleBy5(int d) {
    return (d == 5);
}

bool isDivisibleBy7(long long total, int d) {
    int remainder = 0;
    while(total--) {
        remainder = (remainder * 10 + (d)) % 7;
    }
    return (remainder == 0);
}

bool isDivisibleBy9(long long total, int d) {
    long long sum = total * d;
    return (sum % 9 == 0);
}

void solve() {
    long long int n,d;
    cin >> n >> d;
    
    long long total = factorial(n);
    cout << "1 ";
    if(isDivisibleBy3(total, d)) cout << "3 ";
    if(isDivisibleBy5(d)) cout << "5 ";
    if(isDivisibleBy7(total, d)) cout << "7 ";
    if(isDivisibleBy9(total ,d)) cout << "9";
    cout << endl;
}

int main (){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
