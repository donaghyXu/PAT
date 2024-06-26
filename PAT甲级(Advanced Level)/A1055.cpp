#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Person{
	char name[10];
	int age;
	int worth;
}per[100010], valid[100010];

bool cmp(Person a, Person b) {
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}
int main() {
	int n, k;
	int Age[100010] = {0};
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%s %d %d", per[i].name, &per[i].age, &per[i].worth);
	}
	sort(per, per + n, cmp);
	int validNum = 0;
	for(int i = 0; i < n; i++) {
		if(Age[per[i].age] < 100) {
			Age[per[i].age]++;
			valid[validNum++] = per[i];
		}
	}
	int m, age1, age2;

	for(int i = 0; i < k; i++) {
		scanf("%d %d %d", &m, &age1, &age2);
		bool flag = false;
		int printNum = 0;
		printf("Case #%d:\n", i + 1);
		for(int j = 0; j < validNum && printNum < m; j++) {
			if(valid[j].age >= age1 && valid[j].age <= age2) {
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
				printNum++;
				flag = true;
			}
		}
		if(flag == false) printf("None\n");
	}
	return 0;
}
