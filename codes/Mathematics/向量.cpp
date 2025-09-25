#define F first
#define S second
#define mp make_pair
//用pair表示向量
template<typename T>
pair<T, T> operator+(pair<T, T> a, pair<T, T> b){
    return mp(a.F + b.F, a.S + b.S);
}

template<typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b){
    return mp(a.F - b.F, a.S - b.S);
}

template<typename T>
pair<T, T> operator*(pair<T, T> a, T b){
    return mp(a.F * b, a.S * b);
}

template<typename T>
pair<T, T> operator/(pair<T, T> a, T b){
    return mp(a.F / b, a.S / b);
}

template<typename T>
T dot(pair<T, T> a, pair<T, T> b){
    return a.F * b.F + a.S * b.S;
}

template<typename T>
T cross(pair<T, T> a, pair<T, T> b){
    return a.F * b.S - a.S * b.F;
}

template<typename T>
T abs2(pair<T, T> a){
    return a.F * a.F + a.S * a.S;
}

//三點共線
template<typename T>
bool collinearity(pair<T, T> p1, pair<T, T> p2, pair<T, T> p3){
    return cross(p1, p2) * cross(p1, p3) == 0;
}

//點是否在線段上
template<typename T>
bool inLine(pair<T, T> a, pair<T, T> b, pair<T, T> p){
    return collinearity(a, b, p) && dot(a - p, b - p) <= 0;
}

//線段相交
template<typename T>
bool intersect(pair<T, T> a, pair<T, T> b, pair<T, T> c, pair<T, T> d){
    return (cross(b - a, c - a) * cross(b - a, d - a) < 0 && cross(d - c, a - c) * cross(d - c, b - c) < 0)
            || inLine(a, b, c) || inLine(a, b, d) || inLine(c, d, a) || inLine(c, d, b);
}

//線段交點
template<typename T>
pair<T, T> intersection(pair<T, T> a, pair<T, T> b, pair<T, T> c, pair<T, T> d){
    assert(intersect(a, b, c, d));
    return a + cross(a - c, d - c) * (b - a) / cross(d - c, b - a);
}

//凸多邊形包含測試
template<typename T>
T inPolygon(vector<pair<T, T>> polygon, pair<T, T> p){
    for(int i = 0; i < polygon.size(); i++)
        if(cross(p - polygon[i], polygon[(i - 1 + polygon.size()) % polygon.size()] - polygon[i]) *
           cross(p - polygon[i], polygon[(i + 1) % polygon.size()] - polygon[i]) > 0)
            return false;
    return true;
}

//三角形面積
template<typename T>
T triangleArea(pair<T, T> a, pair<T, T> b, pair<T, T> c){
    return abs(cross(b - a, c - a));
}

//多邊形面積
template<typename T>
T area(vector<pair<T, T>> p){
    T ans = 0;
    for(int i = 0; i < p.size(); i++) ans += cross(p[i], p[(i + 1) % p.size()]);
    return ans / 2;
}
