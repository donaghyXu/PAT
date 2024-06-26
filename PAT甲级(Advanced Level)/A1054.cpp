#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<int, int> count;
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int str;
			scanf("%d", &str);
			if(count.find(str) != count.end()) count[str]++;
			else count[str] = 1;
		}
	}
	int cnt = 0;
	int max;
	for(map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
		if(it->second > cnt) {
			max = it->first;
			cnt = it->second;
		}
	}
	printf("%d\n", max);
}
