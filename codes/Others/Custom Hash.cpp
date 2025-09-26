#include <chrono>

// ==============================
// ==============================

class custom_hash {
private:
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
public:
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// for example:
// unordered_map<ll, ll, custom_hash> mp;

// ==============================
// ==============================

class custom_hash {
private:
    static const uint64_t FIXED_RANDOM;
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
public:
    size_t operator()(uint64_t x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t> p) const {
        uint64_t h1 = splitmix64(p.first + FIXED_RANDOM);
        uint64_t h2 = splitmix64(p.second + FIXED_RANDOM + 1);
        return h1 ^ (h2*47);
    }
};
const uint64_t custom_hash::FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
// for example:
// unordered_map<pll, ll, custom_hash> mp;
