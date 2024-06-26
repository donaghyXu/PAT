#include <cstdio>
int main() {
	int hashTable[10010] = {0};
	int a[100010], n;
	bool isPrint = false;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		hashTable[a[i]]++;
	}
	for(int i = 0; i < n; i++) {
		if(hashTable[a[i]] == 1) {
			printf("%d\n", a[i]);
			isPrint = true;
			break;
		}
	}	
	if(isPrint == false) printf("None\n");		
	return 0;
}
