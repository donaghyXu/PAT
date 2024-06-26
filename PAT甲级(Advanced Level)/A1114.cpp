#include <cstdio>
#include <algorithm>
using namespace std;
struct Data {
	int id, fId, mId;
	int childId[10];
	int m, area;
}data[1010];
struct fam {
	int id, people;
	double avg, area;
}res[10000];
int father[10000];
bool isVisited[10000];
bool isRoot[10000];
int findFather(int x) {
	if(x == father[x]) return x;
	else {
		int s = findFather(father[x]);
		father[x] = s;
		return s;
	}
}

void Union(int a, int b) {
	int sA = findFather(a);
	int sB = findFather(b);
	if(sA < sB) 
		father[sB] = sA;
	else 
		father[sA] = sB;
}

void init() {
	for(int i = 0; i < 10000; i++) {
		father[i] = i;
	}
}

bool cmp(fam a, fam b) {
	double avgAreaA = a.area * 1.0 / a.people;
	double avgAreaB = b.area * 1.0 / b.people;
	if(avgAreaA != avgAreaB) return avgAreaA > avgAreaB;
	else if(a.id != b.id) return a.id < b.id;
}
int main() {	
	int n;
	scanf("%d", &n);
	init();
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d", &data[i].id, &data[i].fId, &data[i].mId);
		isVisited[data[i].id] = true;
		if(data[i].fId != -1) {
			Union(data[i].id, data[i].fId);
			isVisited[data[i].fId] = true;
		}
		if(data[i].mId != -1) {
			Union(data[i].id, data[i].mId);
			isVisited[data[i].mId] = true;
		}
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; i++) {
			scanf("%d", &data[i].childId[j]);
			Union(data[i].id, data[i].childId[j]);
			isVisited[data[i].childId[j]] = true;
		}
		scanf("%d %d", &data[i].m, &data[i].area);
	}
	//printf("wanbi\n");
	for(int i = 0; i < n; i++) {
		int id = findFather(data[i].id);
		isRoot[id] = true;
		res[id].id = id;
		res[id].avg += data[i].m;
		res[id].area += data[i].area;
	}
	int num = 0;
	for(int i = 0; i < 10000; i++) {
		if(isVisited[i] == true) {
			res[findFather(i)].people++;
		}
		if(isRoot[i] == true) {
			num++;
		}
	}
	printf("%d\n", num);
	sort(res, res + 10000, cmp);
	for(int i = 0; i < num; i++) {
		printf("%04d %d %.3f %.3f\n", res[i].id, res[i].people, (double)(res[i].avg * 1.0 / res[i].people), (double)(res[i].area * 1.0 / res[i].people));
	}
 	return 0;
}
