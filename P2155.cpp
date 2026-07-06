#include <cstdio>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define F2(i, a, b) for (int i = (a); i < (b); ++i)
int T, Mod, n, m;
int primes[664580], pnum = 0;
bool isn_prime[10000001];
int pi[664580], inv[10000001];
int in[664580], fct[10000001];
int pos[10000001];
void init()
{
    isn_prime[0] = isn_prime[1] = 1;
    F(i, 2, 10000000)
    {
        if (!isn_prime[i])
            primes[++pnum] = i;
        for (int j = 1; j <= pnum && primes[j] * i <= 10000000; ++j)
        {
            isn_prime[primes[j] * i] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
    inv[1] = 1;
    for (int i = 2; i < Mod && i <= 10000000; ++i)
        inv[i] = 1ll * (Mod - Mod / i) * inv[Mod % i] % Mod;
    pi[0] = 1;
    F(i, 1, pnum)
    pi[i] = 1ll * pi[i - 1] * (primes[i] - 1) % Mod;
    in[0] = 1;
    F(i, 1, pnum)
    if (primes[i] != Mod) in[i] = 1ll * in[i - 1] * inv[primes[i] % Mod] % Mod;
    else in[i] = in[i - 1];
    fct[0] = 1;
    F(i, 1, 10000000)
    if (i != Mod) fct[i] = 1ll * fct[i - 1] * i % Mod;
    else fct[i] = fct[i - 1];
    F(i, 2, 10000000)
    if (isn_prime[i]) pos[i] = pos[i - 1];
    else pos[i] = pos[i - 1] + 1;
}
int main()
{
    scanf("%d%d", &T, &Mod);
    init();
    while (T--)
    {
        scanf("%d%d", &n, &m);
        if (n >= Mod && m < Mod)
            puts("0");
        else
            printf("%d\n", 1ll * fct[n] * pi[pos[m]] % Mod * in[pos[m]] % Mod);
    }
    return 0;
}
