// CSES Cut and Paste
// Given a string, your task is to process operations
// where you cut a substring and paste it to the end of the string.
// What is the final string after all the operations?

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template<class T> using vec = vector<T>;
#define ff first
#define ss second
#define pb push_back
#define rep(n) for (ll _ = 1; _ <= n; ++_)

// --------------------------------------------------

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Node {
public:
    Node* l,* r;
    ll val, pri, sz;
    Node(ll _val) {
        l = r = nullptr;
        val = _val;
        pri = rng();
        sz = 1;
    }
    void pull() {
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;
    }
};

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pri < b-> pri) {
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void splsz(Node* T, Node*& a, Node*& b, ll s) {
    if (!T) {
        a = b = nullptr;
        return;
    }

    ll lsz = T->l ? T->l->sz : 0;
    if (lsz + 1 <= s) {
        a = T;
        splsz(T->r, a->r, b, s - (lsz + 1));
        a->pull();
    } else {
        b = T;
        splsz(T->l, a, b->l, s);
        b->pull();
    }
}

void move_to_tail(Node*& root, ll l, ll r) {  // 1-indexed
    Node* left,* mid,* right;
    splsz(root, left, mid, l - 1);
    splsz(mid, mid, right, r - l + 1);
    root = merge(left, right);
    root = merge(root, mid);
}

void inorder(Node* root, string& res) {
    if (!root) return;
    inorder(root->l, res);
    res += char(root->val);
    inorder(root->r, res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    Node* root = nullptr;
    for (ll i = 0; i < n; ++i) {
        root = merge(root, new Node(s[i]));
    }

    rep (q) {
        ll l, r;
        cin >> l >> r;
        move_to_tail(root, l, r);
    }

    string res = "";
    inorder(root, res);
    cout << res << '\n';

    return 0;
}

// ==================================================
// ==================================================

// CSES Substring Reversals
// Given a string, your task is to process operations
// where you reverse a substring of the string.
// What is the final string after all the operations?

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template<class T> using vec = vector<T>;
#define ff first
#define ss second
#define pb push_back
#define rep(n) for (ll _ = 1; _ <= n; ++_)

// --------------------------------------------------

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Node {
public:
    Node* l,* r;
    ll val, pri, sz;
    bool rev_tag;
    Node(ll _val) {
        l = r = nullptr;
        val = _val;
        pri = rng();
        sz = 1;
        rev_tag = false;
    }
    void pull() {
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;
    }
    void push() {
        if (rev_tag) {
            swap(l, r);
            if (l) l->rev_tag = !l->rev_tag;
            if (r) r->rev_tag = !r->rev_tag;
            rev_tag = false;
        }
    }
};

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pri < b->pri) {
        a->push();
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->push();
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void splsz(Node* T, Node*& a, Node*& b, ll s) {
    if (!T) {
        a = b = nullptr;
        return;
    }
    T->push();
    ll lsr = T->l ? T->l->sz : 0;
    if (lsr + 1 <= s) {
        a = T;
        splsz(T->r, a->r, b, s - (lsr + 1));
        a->pull();
    } else {
        b = T;
        splsz(T->l, a, b->l, s);
        b->pull();
    }
}

void rev_range(Node*& root, ll l, ll r) {  // 1-indexed
    Node* left,* mid,* right;
    splsz(root, left, mid, l - 1);
    splsz(mid, mid, right, r - l + 1);
    mid->push();  // this line isn't neccessary
    if (mid) mid->rev_tag = !mid->rev_tag;
    root = merge(left, mid);
    root = merge(root, right);
}

void inorder(Node* root, string& res) {
    if (!root) return;
    root->push();
    inorder(root->l, res);
    res += char(root->val);
    inorder(root->r, res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    Node* root = nullptr;
    for (ll i = 0; i < n; ++i) {
        root = merge(root, new Node(s[i]));
    }

    rep (q) {
        ll l, r;
        cin >> l >> r;
        rev_range(root, l, r);
    }

    string res = "";
    inorder(root, res);
    cout << res << '\n';

    return 0;
}

// ==================================================
// ==================================================

// CSES Reversals and Sums
// Given an array of n integers, you have to process following operations:
// reverse a subarray
// calculate the sum of values in a subarray

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template<class T> using vec = vector<T>;
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define rep(n) for (ll _ = 1; _ <= n; ++_)

// --------------------------------------------------

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Node {
public:
    Node* l,* r;
    ll val, pri, sz;
    ll sum;
    bool rev_tag;
    Node(ll _val) {
        l = r = nullptr;
        val = _val;
        pri = rng();
        sz = 1;
        sum = _val;
        rev_tag = false;
    }
    void pull() {
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;

        sum = val;
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
    void push() {
        if (rev_tag) {
            swap(l, r);
            if (l) l->rev_tag = !l->rev_tag;
            if (r) r->rev_tag = !r->rev_tag;
            rev_tag = false;
        }
    }
};

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pri < b->pri) {
        a->push();
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->push();
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void splsz(Node* root, Node*& a, Node*& b, ll s) {
    if (!root) {
        a = b = nullptr;
        return;
    }
    root->push();
    ll lsr = root->l ? root->l->sz : 0;
    if (lsr + 1 <= s) {
        a = root;
        splsz(root->r, a->r, b, s - (lsr + 1));
        a->pull();
    } else {
        b = root;
        splsz(root->l, a, b->l, s);
        b->pull();
    }
}

void rev_range(Node*& root, ll l, ll r) {  // 1-indexed
    Node* left,* mid,* right;
    splsz(root, left, mid, l - 1);
    splsz(mid, mid, right, r - l + 1);
    if (mid) mid->rev_tag = !mid->rev_tag;
    root = merge(left, mid);
    root = merge(root, right);
}

ll qry_range_sum(Node*& root, ll l, ll r) {
    Node* left,* mid,* right;
    splsz(root, left, mid, l - 1);
    splsz(mid, mid, right, r - l + 1);
    ll res = 0;
    if (mid) res = mid->sum;
    root = merge(left, mid);
    root = merge(root, right);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    Node* root = nullptr;
    for (ll i = 0; i < n; ++i) {
        ll val; cin >> val;
        root = merge(root, new Node(val));
    }

    rep (q) {
        ll act, l, r;
        cin >> act >> l >> r;
        if (act == 1) {
            rev_range(root, l, r);
        } else if (act == 2) {
            cout << qry_range_sum(root, l, r) << endl;
        }
    }

    return 0;
}

// ==================================================
// ==================================================

// SPOJ ORDERSET
// In this problem, you have to maintain a dynamic set of numbers
// which support the two fundamental operations
//     INSERT(S,x): if x is not in S, insert x into S
//     DELETE(S,x): if x is in S, delete x from S
// and the two type of queries
//     K-TH(S) : return the k-th smallest element of S
//     COUNT(S,x): return the number of elements of S smaller than x

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template<class T> using vec = vector<T>;
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define rep(n) for (ll _ = 1; _ <= n; ++_)

// --------------------------------------------------

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Node {
public:
    Node* l,* r;
    ll val, pri, sz;
    Node(ll _val) {
        l = r = nullptr;
        val = _val;
        pri = rng();
        sz = 1;
    }
    void pull() {
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;
    }
};

Node* merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b;
    if (a->pri < b->pri) {
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void split(Node* root, Node*& a, Node*& b, ll k) {
    if (!root) {
        a = b = nullptr;
        return;
    }
    if (root->val <= k) {
        a = root;
        split(root->r, a->r, b, k);
        a->pull();
    } else {
        b = root;
        split(root->l, a, b->l, k);
        b->pull();
    }
}

void splsz(Node* root, Node*& a, Node*& b, ll s) {
    if (!root) {
        a = b = nullptr;
        return;
    }
    ll lsr = root->l ? root->l->sz : 0;
    if (lsr + 1 <= s) {
        a = root;
        splsz(root->r, a->r, b, s - (lsr + 1));
        a->pull();
    } else {
        b = root;
        splsz(root->l, a, b->l, s);
        b->pull();
    }
}

ll count(Node*& root, ll k) {
    Node* left,* mid, *right;
    split(root, left, mid, k - 1);
    split(mid, mid, right, k);
    ll res = 0;
    if (mid) res = mid->sz;
    root = merge(left, mid);
    root = merge(root, right);
    return res;
}

ll count_lt(Node*& root, ll k) {  // count less than
    Node* left,* right;
    split(root, left, right, k - 1);
    ll res = 0;
    if (left) res = left->sz;
    root = merge(left, right);
    return res;
}

ll kth_smallest(Node*& root, ll k) {
    assert(root && 1 <= k && k <= root->sz);
    Node* left,* mid,* right;
    splsz(root, left, mid, k - 1);
    splsz(mid, mid, right, 1);
    ll res = mid->val;
    root = merge(left, mid);
    root = merge(root, right);
    return res;
}

void insert(Node*& root, ll k) {
    Node* left,* right;
    split(root, left, right, k);
    Node* a = new Node(k);
    root = merge(left, a);
    root = merge(root, right);
}

void remove_multi(Node*& root, ll k) {
    Node* left,* mid,* right;
    split(root, left, mid, k - 1);
    split(mid, mid, right, k);
    root = merge(left, right);
}

void remove_single(Node*& root, ll k) {
    Node* left,* mid,* right;
    split(root, left, mid, k - 1);
    splsz(mid, mid, right, 1);
    if (!mid || mid->val != k) {
        root = merge(left, mid);
        root = merge(root, right);
    } else {
        root = merge(left, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // The element can be duplicated in the treap
    // of the implementation of this program

    // But the element cannot be duplicated in this problem
    // (Use "count" to check whether the element exists)

    ll q; cin >> q;

    Node* root = nullptr;

    rep (q) {
        char act; cin >> act;
        ll k; cin >> k;
        if (act == 'I') {
            if (count(root, k) == 0) {
                insert(root, k);
            }
        } else if (act == 'D') {
            remove_single(root, k);
        } else if (act == 'K') {
            if (!root || k > root->sz) {
                cout << "invalid" << endl;
            } else {
                cout << kth_smallest(root, k) << endl;
            }
        } else if (act == 'C') {
            cout << count_lt(root, k) << endl;
        }
    }

    return 0;
}
