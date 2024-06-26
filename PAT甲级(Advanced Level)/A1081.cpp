#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

struct fenShu{
	LL up;
	LL down;
};
fenShu simply(fenShu fs) {
	if(fs.down < 0) {
		fs.down = -fs.down;
		fs.up = -fs.up;
	}
	if(fs.up == 0) {
		fs.down = 1;
	} else {
		int d = gcd(abs(fs.up),abs(fs.down));
		fs.up /= d;
		fs.down /= d;
	}
	return fs;
}

fenShu add(fenShu a, fenShu b) {
	fenShu result;
	result.up = a.up * b.down + b.up * a.down;
	result.down = a.down * b.down;
	return simply(result);
}

void showResult(fenShu fs) {
//	simply(fs);
	if(fs.down == 1) printf("%lld\n", fs.up);
	else if(abs(fs.up) > fs.down) printf("%lld %lld/%lld\n", fs.up / fs.down, abs(fs.up) % fs.down, fs.down);
	else printf("%lld/%lld\n", fs.up, fs.down);
}
int main() {
	int n;
	scanf("%d", &n);
	fenShu res, temp;
	res.up = 0; res.down = 1;
	for(int i = 0; i < n; i++) {
		scanf("%lld/%lld", &temp.up, &temp.down);
		res = add(res, temp);
	}
	showResult(res);
	return 0;
}
