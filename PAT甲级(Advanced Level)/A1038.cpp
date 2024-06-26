#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	string str[10010];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	string res;
	for(int i = 0; i < n; i++) {
		res += str[i];
	}
	while(res.size() != 0 && res[0] == '0') {
		res.erase(res.begin());
	}
	if(res.size() == 0)	printf("0\n");
	else printf("%s\n",res.c_str());
	return 0;
}
