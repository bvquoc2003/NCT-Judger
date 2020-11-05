#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

struct node  { 
	int key; 
	struct node *left, *right;
}; 
struct node *newNode(int item) { 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
}
struct node* insert(struct node* node, int key) { 
	if (node == NULL) return newNode(key); 
	if (key < node->key) node->left = insert(node->left, key); 
	else if (key > node->key) node->right = insert(node->right, key); 
	return node; 
} 
int solve_height(node* node) {
    if (node == NULL) return 0;
    return 1 + max(solve_height(node->left),solve_height(node->right));
}

int n, h_max;

void build_tree(int id, int l, int r, int hi){
    if (l == r){
        Write(l);
        putchar(' ');
        return;
    }
    if (r-l <= 1<<(h_max-hi) - 1) {
        Write(l); putchar(' ');
        build_tree(id >> 1 + 1, l+1, r, hi + 1);
    }
    else {
        int m = r - (1 << (h_max-hi)) + 1;
        Write(m); putchar(' ');
        build_tree(id >> 1, l, m-1, hi+1);
        build_tree(id >> 1 + 1, m+1, r, hi+1);
    }
}

signed main(void) {
    FastIO;
    freopen("BST.INP","r",stdin);
    freopen("BST.OUT","w",stdout);
    Read(n); Read(h_max);
    if (n <= 10) {
        vector <int> hv;
        FOR(i,1,n) hv.push_back(i);
        bool ok = false;
        do {
            if (ok) break;
            node *root = NULL;
            for (int x: hv) insert(root,x);
            root = insert(root, hv[0]);
            FOR(i, 1, hv.size()-1) insert(root, hv[i]);
            int h = solve_height(root);
            if (h <= h_max) {
                ok = true;
                for (int x: hv) {
                    Write(x);
                    putchar(' ');
                }
            }
        } while(next_permutation(hv.begin(),hv.end()));
        if (!ok) {
            putchar('-');
            putchar('1');
        }
        exit(0);
    }
    if ((1 << h_max)-1 < n) {
        putchar('-');
        putchar('1');
    } else build_tree(1,1,n,1);
    return 0;
}

/*
build (l,r,h) {
    if (l==r) {
        cout << 2^(h-1)+1 << ' ';
        return;
    }
    int m = max(l,r-2^(h-1)+1);
    cout << m << ' ';
    build(l,m-1,h-1);
    build(m+1,r,h-1);
}
*/