#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool bin_search_bool(vector<ll> a, ll val) {
  ll l = 0;
  ll r = a.size();
  while (l <= r) {
    ll mid = (l + r +1) / 2;
    if (a[mid] == val) {
      return true;
    }
    else if (a[mid] < val) {
      l = mid +1;
    }
    else {
      r = mid -1;
    }
  }
  return false;
}
vector<ll> binary(ll n) {
  vector<ll> nums(n);
  vector <ll> res;
  for (ll i = 0; i < n; i++) {
    nums[i] = i;
  }
  for (ll i = 2; i < n; i++) {
    if (nums[i] != -1) {
      res.push_back(i);
      for (ll j = i + i; j < n; j = j + i) {
        nums[j] = -1;
      }
    }
  }/*
  for (ll i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  */
  return res;
}
int main()
{
  ll n;
  cin >> n;
  auto pri=binary(n);
  for (ll i = 0; i < pri.size(); i++) {
    if (bin_search_bool(pri,n - pri[i])) {
      cout << pri[i] << " " << n - pri[i];
      return 0;
    }
  }
}