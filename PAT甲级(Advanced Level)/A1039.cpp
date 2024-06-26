#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectC[M];
int getID(char name[]) {
	int id = 0;
	for(int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}


int main () {
	int n, k;
	int courseI, num;
	char name[5];
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++) {
		scanf("%d %d", &courseI, &num);
		for(int j = 0; j < num; j++) {
			scanf("%s", name);
			int id = getID(name);
			selectC[id].push_back(courseI);
		}	
	}
	
	for(int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getID(name);
		sort(selectC[id].begin(), selectC[id].end());
		printf("%s %d", name, selectC[id].size());
		for(int j = 0; j < selectC[id].size(); j++) {
			printf(" %d", selectC[id][j]);
		}
		printf("\n");
	}
	return 0;
}
