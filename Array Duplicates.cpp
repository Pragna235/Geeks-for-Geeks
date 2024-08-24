//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// #define endl "\n"
// int mod = 1000ll * 1000ll * 1000ll + 7;
// const int inf = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
// #define cout std::cout
// #define cin std::cin

// bool arrayEnded = false;

// long long readInt(long long l, long long r, char endd) {
//     long long x = 0;
//     int cnt = 0;
//     int fi = -1;
//     bool is_neg = false;
//     // integer must not be started from zero
//     while (true) {
//         char g = getchar();
//         if (g == '-') {
//             assert(fi == -1);
//             is_neg = true;
//             continue;
//         }
//         if ('0' <= g && g <= '9') {
//             x *= 10;
//             x += g - '0';
//             if (cnt == 0) {
//                 fi = g - '0';
//             }
//             cnt++;
//             assert(fi != 0 || cnt == 1);
//             assert(fi != 0 || is_neg == false);

//             assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
//         } else if (g == endd || g == '\n' || g == -1) {
//             if (is_neg) {
//                 x = -x;
//             }

//             if (!(l <= x && x <= r)) {
//                 cerr << l << ' ' << r << ' ' << x << '\n';
//                 assert(1 == 0);
//             }
//             // -1  -> this is the last character i.e null
//             if (g == '\n' or g == -1) { // if array ended
//                 arrayEnded = true;
//             }
//             return x;
//         } else {
//             assert(false);
//         }
//     }
// }

// string readString(int l, int r, char endd) {
//     string ret = "";
//     int cnt = 0;
//     while (true) {
//         char g = getchar();
//         assert(g != -1); // if invalid character
//         if (g == endd) {
//             break;
//         }
//         cnt++;
//         ret += g;
//     }
//     assert(l <= cnt && cnt <= r);
//     return ret;
// }

// long long readIntSp(long long l, long long r) {
//     return readInt(l, r, ' ');
// }

// long long readIntLn(long long l, long long r) {
//     return readInt(l, r, '\n');
// }

// string readStringLn(int l, int r) {
//     return readString(l, r, '\n');
// }

// string readStringSp(int l, int r) {
//     return readString(l, r, ' ');
// }

// vector<long long> readArray() {
//     arrayEnded = false;
//     int n = 0;
//     vector<long long> arr;
//     while (true) {
//         n++;
//         // change the array of elements accordingly
//         arr.push_back(readInt(0, 100000, ' '));
//         if (arrayEnded)
//             break;
//     }

//     return arr;
// }

// int sumN = 0;


// } Driver Code Ends
class Solution {
  public:
    vector<int> duplicates(vector<long long> arr) {
    int n = arr.size();
    map<long long, int> mpp;
    vector<int> temp;
    
    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    
    // Check which elements occur more than once
    for (auto it : mpp) {
        if (it.second > 1) {
            temp.push_back(it.first);
        }
    }
    
    // If no elements found, return -1
    if (temp.size() == 0) {
        temp.push_back(-1);
    }
    
    return temp;
}

};


//{ Driver Code Starts.

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> ans = obj.duplicates(arr);
    for (int i : ans)
        cout << i << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}

// int32_t main() {
//     // #ifndef ONLINE_JUDGE
//     //     freopen("input.txt", "r", stdin);
//     //     freopen("output.txt", "w", stdout);
//     // #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);
//     int T = 1;
//     T = readInt(1, 2000, '\n'); // if multiple test cases
//     if (T == 1) {
//         cout << -1 << endl;
//         return 0;
//     }
//     cerr << "#Testcases read successfully" << endl;
//     while (T--) {
//         solve();
//         // cout<<'\n';
//     }
//     cerr << sumN << '\n';
//     assert(sumN <= 2000000);
//     cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
//     return 0;
// }
// } Driver Code Ends
