#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
using namespace std;
#define ll long long
#define rt register int
#define reep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
namespace fast_IO {
	inline char read() {
		return getchar();
		static const int IN_LEN = 1000000;
		static char buf[IN_LEN], *s, *t;
		if (s == t) {
			t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
			if (s == t) return -1;
		}
		return *s++;
	}
	template<class T>
	inline void read(T &x) {
		static bool iosig;
		static char c;
		for (iosig = false, c = read(); !isdigit(c); c = read()) {
			if (c == '-') iosig = true;
			if (c == -1) return;
		}
		for (x = 0; isdigit(c); c = read())
			x = ((x + (x << 2)) << 1) + (c ^ '0');
		if (iosig) x = -x;
	}
	const int OUT_LEN = 10000000;
	char obuf[OUT_LEN], *ooh = obuf;
	inline void print(char c) {
		if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
		*ooh++ = c;
	}
	template<class T>
	inline void print(T x) {
		static int buf[30], cnt;
		if (x == 0) {
			print('0');
		}
		else {
			if (x < 0) print('-'), x = -x;
			for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
			while (cnt) print((char)buf[cnt--]);
		}
	}
	inline void flush() {
		fwrite(obuf, 1, ooh - obuf, stdout);
	}
}
using namespace fast_IO;
int n, as=-1E9;
int main() {
	read(n);
	rep(i, 1, n){
		static int x;
		read(x);
		if(x<0 || (int)sqrt(x)*(int)sqrt(x)!=x) as=max(as, x);
	}
	printf("%d", as);
	return 0;
}