#include <cstdio>
#include <cmath>
bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	int mSize, n, tableSize, temp;
	scanf("%d %d", &n, &mSize);
	if(isPrime(n))
		tableSize = n;
	else {
		while(!isPrime(n)) {
			n++;
		}
		tableSize = n;
	}
	int hashTable[tableSize] = {0};
	for(int i = 0; i < mSize; i++) {
		scanf("%d", &temp);
		if(hashTable[temp % tableSize] == 0) {
			if(i == 0) printf("%d", temp % tableSize);
			else printf(" %d", temp % tableSize);
			hashTable[temp % tableSize]++;
		} else {
			int step;
			for(step = 1; step < tableSize; step++) {
				int m = (temp + step * step) % tableSize;
				if(hashTable[m] == 0) {
					hashTable[m]++;
					if(i == 0) printf("%d", m);
					else printf(" %d", m);
					break;
				}
			}
			if(step >= tableSize) {
				if(i > 0) printf(" ");
				printf("-");
			}		
		}
	}
	return 0;
}
