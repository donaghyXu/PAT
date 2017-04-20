#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000;
int hashTable[N] = {0}; 	//散列表存放数，0代表未验证，-1代表被覆盖
//验证3n+1猜想 
void valid(int n) {
	while(n != 1) {
		if(n % 2 == 0) {
			n = n / 2;
			hashTable[n] = -1;	//将被覆盖的数设为-1 
		} else {
			n = (3 * n + 1) / 2;
			hashTable[n] = -1;
		}
	}
}

//按从大到小排序 
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if(hashTable[temp] == 0) hashTable[temp] = temp;	//如果未被验证，就把数本身赋给自己	 
		valid(temp);	//进行验证 
	} 
	sort(hashTable, hashTable + N, cmp);	//没被覆盖的数就是自身，被覆盖的就是-1，未验证的就是0 
	
	for(int i = 0; i < n; i++) {
		if(hashTable[i] > 0) cnt++;	//统计有多少个关键数 
	}
	
	for(int i = 0; i < cnt; i++) {
		if(hashTable[i]) printf("%d", hashTable[i]);
		if(i != cnt - 1) printf(" ");
	}
	return 0;
} 
