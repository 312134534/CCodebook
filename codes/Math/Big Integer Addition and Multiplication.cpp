vector<int> strToVec(string str, int sz) {
    vector<int> r(sz, 0);
    int strLength = str.length();
    for (int i = strLength - 1, idx = 0; i >= 0; --i, ++idx) {
        r[idx] = str[i] - '0';
    }
    return r;
}
// for example
// strToVec("677", 4) -> 7 7 6 0
// strToVec("8829", 4) -> 9 2 8 8

// addition
string add(string x, string y) {
    ll n = max(x.length(), y.length());
    vector<ll> xdigit = strToVec(x, n + 1);
    vector<ll> ydigit = strToVec(y, n + 1);
    vector<ll> result(n + 1, 0);
    ll carry = 0;
    for (ll i = 0; i < n + 1; ++i) {
        result[i] = xdigit[i] + ydigit[i] + carry;
        if (result[i] >= 10) {
            result[i] %= 10;
            carry = 1;
        }
        else carry = 0;
    }
    ll start;
    for (ll i = n; i >= 0; --i) {
        if (result[i] != 0) {
            start = i;
            break;
        }
    }
    string r = "";
    for (ll i = start; i >= 0; --i) {
        r += result[i] + '0';
    }
    return r;
}

// multiplication
string product(string x, string y) {
    ll xlength = x.length();
    ll ylength = y.length();
    ll n = max(xlength, ylength);
    vector<ll> xdigit = strToVec(x, xlength);
    vector<ll> ydigit = strToVec(y, ylength);
    vector<ll> result(2*n, 0);
    for (ll i = 0; i < xlength; ++i) {
        for (ll j = 0; j < ylength; ++j) {
            result[i + j] += xdigit[i]*ydigit[j];
            if (result[i + j] >= 10) {
                result[i + j + 1] += result[i + j]/10;
                result[i + j] %= 10;
            }
        }
    }
    ll start;
    for (ll i = 2*n - 1; i >= 0; --i) {
        if (result[i] != 0) {
            start = i;
            break;
        }
    }
    string r = "";
    for (ll i = start; i >= 0; --i) {
        r += result[i] + '0';
    }
    return r;
}
