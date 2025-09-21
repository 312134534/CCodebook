// Binary Indexed Tree (Fenwick Tree)
class Fenwick
{
public:
    vector<int> bit;
    int n;
    Fenwick(int n) : bit(n + 1, 0), n(n){}
    void update(int idx, int value)
    {
        for(; idx <= n; idx += idx & -idx) bit[idx] += value; 
    }
    int query(int idx)// sum of [1, idx]
    {
        int sum = 0;
        for(; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }
};