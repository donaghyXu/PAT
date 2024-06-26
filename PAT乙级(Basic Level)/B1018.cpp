#include <cstdio>
int change(char c) {
	if(c == 'B') return 0;	//²¼ 
	else if(c == 'C') return 1;	//Ê¯Í· 
	else return 2;	//¼ôµ¶ 
}
int main() {
	int n;
	scanf("%d", &n);
	int a1[3] = {0}, b1[3] = {0};
	int a2[3] = {0}, b2[3] = {0};
	char c1, c2;
	int d1, d2;
	for(int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c", &c1, &c2);
		d1 = change(c1);
		d2 = change(c2);
		if((d1 + 1) % 3 == d2) {
			a1[0]++;
			b1[2]++;
			a2[d1]++;
		} else if(d1 == d2) {
			a1[1]++;
			b1[1]++;
		} else {
			a1[2]++;
			b1[0]++;
			b2[d2]++;
		}
	}
	printf("%d %d %d\n", a1[0], a1[1], a1[2]);
	printf("%d %d %d\n", b1[0], b1[1], b1[2]);
	int res1 = 0, res2 = 0;
	char c[3] = {'B', 'C', 'J'};
	for(int i = 2; i >= 0; i--) {
		if(a2[i] >= a2[res1]) 
			res1 = i;	
		if(b2[i] >= b2[res2])
			res2 = i;
	}
	printf("%c %c\n", c[res1], c[res2]);
	return 0;
}
