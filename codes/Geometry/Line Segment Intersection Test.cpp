bool isSegInter(const vec& a, const vec& b,const vec& c,const vec& d) {
    ll ori1 = ori(a, b, c);
    ll ori2 = ori(a, b, d);
    ll ori3 = ori(c, d, a);
    ll ori4 = ori(c, d, b);
    if (isCollinear(a, b, c) && isCollinear(a, b, d)) {
        return isOnSeg(a, b, c) || isOnSeg(a, b, d) ||
               isOnSeg(c, d, a) || isOnSeg(c, d, b);
    }
    return ori1 * ori2 <= 0 && ori3 * ori4 <= 0;
}
