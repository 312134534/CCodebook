using ll = long long;

class vec {
public:
    ll x, y;
    vec() {}
    vec(ll _x, ll _y) : x(_x), y(_y) {}
    vec operator+(const vec& v) const {
        return vec(this->x + v.x, this->y + v.y);
    }
    vec operator-(const vec& v) const {
        return vec(this->x - v.x, this->y - v.y);
    }
    ll operator*(const vec& v) const {
        return this->x * v.x + this->y * v.y;
    }
    ll operator^(const vec& v) const {
        return this->x * v.y - this->y * v.x;
    }
    bool operator<(const vec& v) const {
        if (this->x != v.x) return this->x < v.x;
        return this->y < v.y;
    }
    vec& operator=(const vec& v) {
        this->x = v.x;
        this->y = v.y;
        return *this;
    }
};

ll sign(ll x) {
    if (x == 0) return 0;
    if (x < 0) return -1;
    return 1;
}

ll ori(const vec& o, const vec& a,const vec& b) {
    return sign((a - o) ^ (b - o));
}

bool isCollinear(const vec& a, const vec& b,const vec& c) {
    return ori(a, b, c) == 0;
}

bool isOnSeg(const vec& a, const vec& b,const vec& p) {
    return isCollinear(a, b, p) && sign((p - a) * (p - b)) <= 0;
}
