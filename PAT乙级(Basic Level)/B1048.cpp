#include <cstdio> 
#include <cstring>
int main() {
	char a[110], b[110], res[110];
	scanf("%s %s", a, b);
	int lenA = strlen(a);
	int lenB = strlen(b);
//	printf("A:%d, B:%d", lenA, lenB);
	int n, temp, k, count = 0;
	if(lenB > lenA) n = lenB - lenA;
	else n = 0;
	for(int i = lenB - 1, j = lenA - 1; i >= n; i--, j--) {
//		printf("i:%d,j:%d\n", i ,j);
		if(lenB > lenA) k = i;
		else k = j;
		if(count % 2 == 0) {
			temp = ((a[j] - '0') + (b[i] -'0')) % 13;
//			printf("temp:%d\n", temp);
			if(temp == 10)	res[k] = 'J';
			else if(temp == 11)	res[k] = 'Q';
			else if(temp == 12) res[k] = 'K';
			else res[k] = temp + '0';
//			printf("temp:%d\n", temp);			
		} else {
			temp = (b[i] - '0') - (a[j] - '0');
			if(temp < 0) temp += 10;
//			printf("temp:%d\n", temp);
			res[k] = temp + '0';
		}
		count++;
	}
	int num = lenB;
	if(count < lenB) {
		for(int i = 0; i < lenB - count; i++) {
			res[i] = b[i];
		}
	}	
	if(count < lenA) {
		for(int i = lenA - count - 1; i >= 0; i--) {
			if(num % 2 == 0) 	res[i] = a[i];
			else res[i] = (0 - (a[i] - '0') + 10) + '0';
			num++;
		}
	}
	int len = lenB > lenA? lenB : lenA;
	for(int i = 0; i < len; i++) {
		printf("%c", res[i]);
	}
	return 0;
}
