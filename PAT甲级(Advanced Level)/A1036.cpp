#include <cstdio>
struct Student{
	char name[11];
	char gender;
	char id[11];
	int score;
}temp, res1, res2;

int main() {
	int n;
	scanf("%d", &n);
	res1.score = -1;
	res2.score = 101;
	for(int i = 0; i < n; i++) {
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.score);
		if(temp.gender == 'F' && temp.score > res1.score) res1 = temp;
		if(temp.gender == 'M' && temp.score < res2.score) res2 = temp;		
	}
	if(res1.score != -1) printf("%s %s\n", res1.name, res1.id);
	else printf("Absent\n");
	if(res2.score != 101) printf("%s %s\n", res2.name, res2.id);
	else printf("Absent\n");
	if(res1.score != -1 && res2.score != 101) printf("%d\n",res1.score - res2.score);
	else printf("NA\n");
	return 0;
}
