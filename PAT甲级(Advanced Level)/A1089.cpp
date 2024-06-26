#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int origin[111], tempOri[111], final[111];
int n;
bool isSame(int a[], int b[]) {
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

bool insertSort() {
	bool flag = false;
	for(int i = 1; i < n; i++) {
		if(i != 1 && isSame(tempOri, final))
			flag = true;
		int temp = tempOri[i], j = i;
		while(j > 0 && temp < tempOri[j - 1]) {
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true) return true;
	}
	return false;
}

bool mergeSort() {
	bool flag = false;
	for(int i = 2; i / 2 <= n; i *= 2) {
		if(i != 2 && isSame(tempOri, final))
			flag = true;
		for(int j = 0; j < n; j += i) {
			sort(tempOri + j, tempOri + min(j + i, n));
		}
		if(flag == true) return true;
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &final[i]);
	}
	if(insertSort()) {
		printf("Insertion Sort\n");
		for(int i = 0; i < n; i++) {
			printf("%d", tempOri[i]);
			if(i < n - 1) printf(" ");
		}
		printf("\n");
	}
	for(int i = 0; i < n; i++) {
		tempOri[i] = origin[i];
	}
	if(mergeSort()) {
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++) {
			printf("%d", tempOri[i]);
			if(i < n - 1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
