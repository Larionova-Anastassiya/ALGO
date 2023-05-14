#include <bits/stdc++.h>
using namespace std;

pair<int , int> getRange(vector<int> &nums, int lx, int rx) {
    pair<int, int> res = {-1, -2};

    if(nums.back() < lx || nums[0] > rx)
        return res;

    int l = -1, r = nums.size()-1;

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(nums[mid] >= lx)
            r = mid;
        else
            l = mid;
    }
    res.first = r;

    l = 0;
    r = nums.size();

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(nums[mid] <= rx)
            l = mid;
        else
            r = mid;
    }

    res.second = l;

    return res;
}



int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0 ; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        pair<int, int> firstRange = getRange(nums, l1, r1);
        pair<int, int> secondRange = getRange(nums, l2, r2);
        int c = 0;
        c += max(0, firstRange.second - firstRange.first + 1);
        c += max(0, secondRange.second - secondRange.first + 1);
        if(firstRange.second >= secondRange.second && firstRange.first <= secondRange.first)
            c -= max(0, secondRange.second - secondRange.first + 1);
        else if(secondRange.second >= firstRange.second && secondRange.first <= firstRange.first)
            c -= max(0, firstRange.second - firstRange.first + 1);
        else if(firstRange.first <= secondRange.first && firstRange.second >= secondRange.first)
            c -= max(0, firstRange.second - secondRange.first + 1);
        else if(secondRange.first <= firstRange.first && secondRange.second >= firstRange.first)
            c -= max(0, secondRange.second - firstRange.first + 1);
        cout << c << endl;
    }

    return 0;
}
