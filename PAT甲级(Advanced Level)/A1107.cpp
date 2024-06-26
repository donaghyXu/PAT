#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int father[maxn];
int isRoot[maxn] = {0};
int course[maxn] = {0};
int findFather(int f) {
	if(f == father[f]) return f;
	else {
		int s = findFather(father[f]);
		father[f] = s;
		return s;
	}
}

void Union(int a, int b) {
	int sA = findFather(a);
	int sB = findFather(b);
	if(sA != sB) father[sA] = sB;
}

void init(int n) {
	for(int i = 1; i <= n; i++) {
		father[i] = i;
	}
}

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, num, temp;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++) {
		scanf("%d: ", &num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &temp);
			if(course[temp] == 0)
				course[temp] = i;
			Union(i, findFather(course[temp]));
		}
	}
	for(int i = 1; i <= n; i++) {
		isRoot[findFather(i)]++;
	}
	int res = 0;
	for(int i = 1; i <= n; i++) {
		if(isRoot[i] != 0) res++;
	}
	printf("%d\n", res);
	sort(isRoot + 1, isRoot + n + 1, cmp);
	for(int i = 1; i <= res; i++) {
		printf("%d", isRoot[i]);
		if(i < res) printf(" ");
	}
	return 0;
}
