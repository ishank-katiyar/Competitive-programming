#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A> A rnd(A x, A y) { return uniform_int_distribution<A> (x, y) (rng); }

static const int buf_len = (1 << 14);
static const int buf_max = (1 << 04);
static char buf_out[buf_len];
static char buf_num[buf_max];
static int buf_pos = 0;

inline void writeChar(int x) {
    if (buf_pos == buf_len) fwrite(buf_out, 1, buf_len, stdout), buf_pos = 0;
    buf_out[buf_pos++] = x;
}

inline void writeInt(int x, char end = 0) {
    if (x < 0) writeChar('-'), x = -x;
    int n = 0;
    do buf_num[n++] = x % 10 + '0'; while(x /= 10);
    while (n--) writeChar(buf_num[n]);
    if (end) writeChar(end);
}

struct Flusher{~Flusher(){if(buf_pos)fwrite(buf_out, 1, buf_pos, stdout),buf_pos=0;}}flusher;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = rnd ((int) 1, (int) 1e7);
	while (n--) cout << rnd(1, 9);
	// while (n--) writeInt(rnd(1, 9));
	cout << '\n';
	// writeChar('\n');
	n = rnd ((int) 1, (int) 1e7);
	while (n--) cout << rnd(1, 9);
	// while (n--) writeInt(rnd(1, 9));
	cout << '\n';
	// writeChar('\n');
	// Flusher();
	return 0;
}