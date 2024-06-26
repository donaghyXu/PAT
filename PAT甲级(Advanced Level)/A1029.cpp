#include <cstdio>
const int maxn = 1000010;
int str1[maxn], str2[maxn];
int str3[maxn];
int main() {
	int n, m;	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &str1[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &str2[i]);
	}
	int mid = (n + m - 1) / 2;	
	int i = 0, j = 0, k = 0;
	while(i < n && j < m) {
		if(str1[i] <= str2[j]) {
			str3[k++] = str1[i++];
			if(k == mid + 1) break;
		}
//			str3[k++] = str1[i++];
		else {
			str3[k++] = str2[j++];	
			if(k == mid + 1) break;
		}
//			str3[k++] = str2[j++];			 
	}
	while(i < n) {
		str3[k++] = str1[i++];
		if(k == mid + 1) break;
	}
	while(j < m) {
		str3[k++] = str2[j++];
		if(k == mid + 1) break;
	}
	printf("%d\n", str3[mid]);
	return 0;
}
