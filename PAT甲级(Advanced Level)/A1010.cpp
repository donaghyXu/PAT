#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL hashTable[256];
LL inf = (1LL << 62) - 1;
LL covertToTen(char a[], LL n, LL t) {
	LL res = 0, s = 1;
	int len = strlen(a);
//	for(int i = len - 1; i >= 0; i--) {
//		res += hashTable[a[i]] * s; 
//		s = s * n;
//		if(res < 0 || res > t)	return -1;
//	}
	for(int i = 0; i < len; i++) {
		res = res * n + hashTable[a[i]]; 
		if(res < 0 || res > t)	return -1;
	}
	return res;
}

int findLargestDigit(char b[]) {
	int len = strlen(b);
	int res = -1;
	for(int i = 0; i < len; i++) {
		if(hashTable[b[i]] > res)
			res = hashTable[b[i]];
	}
	return res + 1;
}

int cmp(char b[], LL n, LL res) {
	int len = strlen(b);
	LL num = covertToTen(b, n, res);
	if(num < 0) return 1;
	if(res > num)	return -1;
	else if(res == num)	return 0;
	else return 1;
}
int binarySearch(char b[], LL left, LL right, LL res) {
	LL mid;
	while(left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(b, mid, res);
		if(flag == 0) return mid;
		else if(flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
int main() {
	char n1[15], n2[15];
	char k[15];
	int tag, radix;
	LL res;
	scanf("%s %s %d %d", n1, n2, &tag, &radix);
	for(char c = '0'; c <= '9'; c++) {
		hashTable[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++) {
		hashTable[c] = c - 'a' + 10;
	}
	LL low;
	if(tag == 1) {
		res = covertToTen(n1, radix, inf);
		strcpy(k, n2);	
	} else {
		res = covertToTen(n2, radix, inf);
		strcpy(k, n1);
	}
//	printf("%lld\n", res1);
	low = findLargestDigit(k);
	LL high = max(low, res) + 1;
	LL res2 = binarySearch(k, low, high, res);
	if(res == -1)	printf("Impossible\n");
	else printf("%lld\n", res2);
	return 0;
}
