#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
 
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
 
typedef long long ll;
 
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 1e7 + 555;
const double PI = acos(-1.0);
struct Node{
	int v;
	Node * next, * prev;
	Node(int x){
		v = x;
		next = prev = NULL;
	}
};
Node * head, * tail;
int cnt = 0;
 
void push(int x){
	Node * w = new Node(x);
	if(cnt == 0) head = tail = w;
	else{
		tail->next = w;
		w->prev = tail;
		tail = w;
	}
	cnt++;
}
void pop(){
	if(cnt != 0){
		head = head->next;
		cnt--;
		if(cnt == 0) head = tail = NULL;
	}
}
int front(){
	return head->v;
}
bool empty(){
	return cnt == 0;
}
 
int ask(int t){
    push(t);
    while (head->v < t - 3000)
        pop();
    return cnt;
}
 
void solve()
{
	int T;
	cin >> T;
	while(T--){
		int x;
		cin >> x;
		cout << ask(x) << endl;
	}
}
 
int main()
{
    Red;
    solve();
    return 0;
}