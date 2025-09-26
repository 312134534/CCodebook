#include <chrono>
#include <random>
using namespace std;
using ll = long long;

// mt19937 is a random number generator
// chrono::steady_clock::now().time_since_epoch().count() is used as a seed
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// dist describes a range of random numbers
uniform_int_distribution<ll> dist(lb, ub);

dist(rng) // use rng to generate a random integer in [lb, ub]
