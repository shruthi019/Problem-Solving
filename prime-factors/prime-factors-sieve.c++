#include<iostream>
#include <vector>
using namespace std;
bool prime[10000];

vector<int> primeno() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i=2; i*i <= 10000; i++) {
        if (prime[i]) {
            for (int p = i+i ;p <= 10000; p += i) {
                prime[p] = false;
            }
        }
    }
    vector<int> primes;
    primes.clear();
    for (int i = 0; i < 10000; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> all_prime_factors(int m, vector<int> &primes) {
    vector<int> prime_factors;
    prime_factors.clear();
    
    int i = 0;
    int p = primes[0];
    
    while (p*p <= m) {
        if (m % p == 0) {
            prime_factors.push_back(p);
            while (m % p == 0) {
                m = m / p;
            }
        }
        i++;
        p = primes[i];
    }
    if (m != 1) {
        prime_factors.push_back(m);
    }
    return prime_factors;
}

int main() {
    vector<int> primes = primeno();
    int n;
    cin >> n;
    vector<int> prime_factors = all_prime_factors(n, primes);
    for(int x: prime_factors){
        cout << x << ", ";
    }
    return 0;
}
