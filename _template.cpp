#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define S second
#define F first
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
using namespace std;
typedef vector<ll> vi;  
typedef vector<vector<ll>> vvi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#ifdef DEBUG
    #define debug(...) (std::cout << "DBG : ", show(std::cout, #__VA_ARGS__, __VA_ARGS__))
 
    template<typename H1>
    std::ostream& show(std::ostream& out, const char* label, H1&& value) {
        return out << label << "=" << std::forward<H1>(value) << '\n';
    }
 
    template<typename H1, typename ...T>
    std::ostream& show(std::ostream& out, const char* label, H1&& value, T&&... rest) {
    const char* pcomma = strchr(label, ',');
    return show(out.write(label, pcomma - label) << "="
                                                << std::forward<H1>(value)
                                                << ',',
                pcomma + 1,
                std::forward<T>(rest)...);
    }
    template <class T> void show(const T& v) { for (auto& item : v) { cout << item << ' ';} cout << endl; }
#else
    #define debug(...) 42
    #define show(x) 43
#endif // DEBUG
 
 
void testcase(){
    
}
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // freopen("output.txt", "w",stdout);
    // freopen("input.txt", "r", stdin);
    
    ll tt = 1;
    cin>>tt;
    while(tt--){
 
        // testcase();
 
        // cout << testcase() << endl;
 
        // if(testcase()){
        //     yes
        // } else {
        //     no
        // }
        
        
    }
 
    return 0;
}