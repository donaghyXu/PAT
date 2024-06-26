#include <cstdio>
#include <cstring>
struct bign{
	int d[1010];
	int len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] -'0';
	}
	return a;
}

bign multi(bign a, int b) {
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++) {
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void print(bign a) {
	for(int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
}
int main() {
	char str[25];
	scanf("%s", str);
	bign a = change(str);
	bign res = multi(a, 2);
	int hashTable[15] = {0};
	bool flag = true;
	for(int i = 0; i < a.len; i++) {
		hashTable[a.d[i]]++;
	}
	for(int i = 0; i < res.len; i++) {
		hashTable[res.d[i]]--;
	}
	for(int i = 0; i < 10; i++) {
		if(hashTable[i] != 0) {
			flag = false; 
			break;
		}
	}
	if(flag == true) printf("Yes\n");
	else printf("No\n");
	print(res);
	return 0;
}
