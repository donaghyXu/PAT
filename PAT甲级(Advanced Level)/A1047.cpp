#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> course[2510];
char stu[40010][5];

bool cmp(int a, int b) {
	return strcmp(stu[a], stu[b]) < 0;
}
int main() {
	int n, k, num, courseID;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%s %d", stu[i], &num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &courseID);
			course[courseID].push_back(i);
		}
	}
	for(int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); j++) {
			printf("%s\n", stu[course[i][j]]);
		}
	}
	return 0;
}
