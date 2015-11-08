#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)
#define trace1(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                     << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                    << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
ll MOD = int(1e9) + 7;

int debug = 1;
const int N = int(1e6) + 5;
using namespace std;
int speed[1005],p[105],h[105];
int n,m,q;
int check(int tim)
{
        int i,j;
        int req = 0;
        rep(i,n)
        {
                if(p[i] == 0)
                        continue;
                int tempcost = q + 1;
                rep(j,m)
                {
                        if(speed[j] == 0)
                                continue;
                        if(p[i]*speed[j] > 0)
                                continue;
                        int pos = abs(p[i]),spe = abs(speed[j]);
                        int timreq = ((pos+spe-1)/spe);
                        if(timreq <= tim)
                                tempcost = min(tempcost,abs(h[i]-j));
                }
                req += tempcost;
        }
        return req <= q;
}
int main()
{
        int i,j,t;
        ios::sync_with_stdio(false);
        cin>>t;
        int t1 = t;
        while(t--)
        {

                cin>>n>>m>>q;
                rep(i,m)cin>>speed[i];
                rep(i,n)cin>>p[i]>>h[i];
                int ans = -1 , lo = 0 , hi =  int(1e7);
                int mid;
                while(lo <= hi)
                {
                        mid = (lo+hi)/2;
                        if(check(mid))
                        {
                                hi = mid - 1;
                                ans = mid;
                        }
                        else
                                lo = mid + 1;
                }
                if(ans == -1)
                cout<<"Case #"<<t1-t<<": "<<"IMPOSSIBLE"<<endl;

                else
                cout<<"Case #"<<t1-t<<": "<<ans<<endl;
        }
}
