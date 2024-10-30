#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define TASK "dynamic"

const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9 + 7;
const ll LINF = (ll)1e18 + 7;
const int MOD = (int)1e9 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord(const char *s) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new (size_t n){
	char *res = mem + mpos;
mpos += n;
assert(mpos <= MAX_MEM);
return (void *)res;
}
inline void operator delete (void *) { } // !

int main() {
	file();
	int n, m, w, b;
	n = readInt(), m = readInt();
	vector<pair<int, int> > M1, M2;
	for (int i = 0; i < m; ++i) {
		w = readInt(), b = readInt();
		if (b) {
			M1.push_back({ w, i });
		} else {
			M2.push_back({ w, i });
		}
	}
	sort(all(M1));
	sort(all(M2));
	int k = 0;
	for (int i = 1; i < (int)M1.size(); ++i) {
		if (k == (int)M2.size()) {
			break;
		}
		for (int j = 0; j < i; ++j) {
			if (M2[k].first < M1[i].first) {
				writeInt(-1);
				return 0;
			}
			++k;
			if (k == (int)M2.size()) {
				break;
			}
		}
	}
	vector<pair<int, int> > ans(m);
	for (int i = 0; i < (int)M1.size(); ++i) {
		ans[M1[i].second] = { i, i + 1 };
	}
	k = 0;
	for (int i = 1; i < (int)M1.size(); ++i) {
		if (k == (int)M2.size()) {
			break;
		}
		for (int j = 0; j < i; ++j) {
			ans[M2[k].second] = { i + 1, j };
			++k;
			if (k == (int)M2.size()) {
				break;
			}
		}
	}
	for (auto i : ans) {
		writeInt(i.first + 1, ' ');
		writeInt(i.second + 1, '\n');
	}
	return 0;
}