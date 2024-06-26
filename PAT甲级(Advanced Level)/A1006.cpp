#include <cstdio> 
struct Person{
	char id[16];
	int hh, mm, ss;
}temp, res1, res2;
bool more(Person temp1, Person temp2) {
	if(temp1.hh != temp2.hh) return temp1.hh > temp2.hh;
	else if(temp1.mm != temp2.mm) return temp1.mm > temp2.mm;
	else return temp1.ss > temp2.ss;
}

void init() {
	res2.hh = 0; res2.mm = 0; res2.ss = 0;
	res1.hh = 24; res1.mm = 60; res1.ss = 60;
}
int main() {
	int m;
	init();
	scanf("%d", &m);	
	for(int i = 0; i < m; i++) {
		scanf("%s",temp.id);
		/*scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		if(more(temp,res1) == false) res1 = temp;
		
		scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		if(more(temp,res2) == true) res2 = temp;*/
		for(int i = 0; i < 2; i++) {
			scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
			if(more(temp,res1) == false) res1 = temp;
			if(more(temp,res2) == true) res2 = temp;
		}		
	}
	printf("%s %s\n", res1.id,res2.id);
	return 0;
}
