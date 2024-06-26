#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

struct Fraction{
	LL up, down;
};

Fraction simply(Fraction fc) {
	if(fc.up == 0) fc.down = 1;
	else {
		LL d = gcd(abs(fc.up), fc.down);
		fc.up /= d;
		fc.down /= d;
	}
	return fc;
}

Fraction add(Fraction a, Fraction b) {
	Fraction res;
	res.up = a.up * b.down + b.up * a.down;
	res.down = a.down * b.down;
	return simply(res);
}

Fraction sub(Fraction a, Fraction b) {
	Fraction res;
	res.up = a.up * b.down - b.up * a.down;
	res.down = a.down * b.down;
	return simply(res);
}

Fraction mul(Fraction a, Fraction b) {
	Fraction res;
	res.up = a.up * b.up;
	res.down = a.down * b.down;
	return simply(res);
}

Fraction div(Fraction a, Fraction b) {
	Fraction res;
	LL temp;
	temp = b.up;
	b.up = b.down;
	b.down = temp;
	if(b.down < 0) {
		b.down = -b.down;
		b.up = -b.up;
	}
	res.up = a.up * b.up;
	res.down = a.down * b.down;
	return simply(res);
}

void showResult(Fraction result) {
	Fraction res = simply(result);
	if(res.down == 1) {
		if(res.up < 0) printf("(%lld)", res.up);
		else printf("%lld", res.up);
	}
	else if(abs(res.up) > res.down) {
		if(res.up < 0) printf("(%lld %lld/%lld)", res.up / res.down, abs(res.up) % res.down, res.down);
		else printf("%lld %lld/%lld", res.up / res.down, abs(res.up) % res.down, res.down);
	} else {
		if(res.up < 0) printf("(%lld/%lld)", res.up, res.down);
		else printf("%lld/%lld", res.up, res.down);
	}
	
} 
int main() {
	Fraction a, b, res, temp1, temp2;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	temp1 = simply(a); temp2 = simply(b);
	
	res = add(temp1, temp2);
	showResult(temp1);
	printf(" + ");
	showResult(temp2);
	printf(" = ");
	showResult(res);
	printf("\n");
	
	res = sub(temp1, temp2);
	showResult(temp1);
	printf(" - ");
	showResult(temp2);
	printf(" = ");
	showResult(res);
	printf("\n");
	
	res = mul(temp1, temp2);
	showResult(temp1);
	printf(" * ");
	showResult(temp2);
	printf(" = ");
	showResult(res);
	printf("\n");
	
	res = div(temp1, temp2);
	showResult(temp1);
	printf(" / ");
	if(temp2.up == 0) printf("0 = Inf\n");
	else {
		showResult(temp2);
		printf(" = ");
		showResult(res);
		printf("\n");
	}
	return 0;
}
