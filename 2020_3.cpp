#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define pb push_back
using namespace std;
//using LL = long long;
//using pii = pair<int, int>;
//
//inline int lowbit(int x) { return x & (-x); }
//template <typename A>
//inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
//template <typename A, typename B, typename C>
//inline A fpow(A x, B p, C lyd) {
//    A ans = 1;
//    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
//    return ans;
//}
//
//mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
/*记录车出站的时间顺序，然后重新遍历进站的车，假设当前遍历到了第i辆进站的车，
 * 那么前i-1辆车一定比第i辆先进站，如果前i辆车的最晚出站时间t大于第i辆车的出站时间，那么第i辆就超车了*/

int n;
vector<int> a, b, position;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    position.resize(n + 1);
    for (int i = 1; i <= n; i++) { //进入隧道顺序
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {  //出隧道顺序
        cin >> b[i];
        position[b[i]] = i;         //记录出隧道位置序号，放在position数组中
    }
    int t = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (position[a[i]] < t)
//            cout << "t:" << t;
            ans++;
        t = max(t, position[a[i]]);
    }
    cout << ans << endl;

    return 0;
}