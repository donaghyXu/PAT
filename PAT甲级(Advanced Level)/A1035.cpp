#include <cstdio>
#include <cstring>
struct User {
	char username[15];
	char pwd[15];
	bool isChange;
}user[1005];
int main() {
	int n, count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s %s", user[i].username, user[i].pwd);
		int len = strlen(user[i].pwd);
		for(int j = 0; j < len; j++) {
			if(user[i].pwd[j] == 'l') {
				user[i].pwd[j] = 'L';
				user[i].isChange = true;
//				printf("1");
			} else if(user[i].pwd[j] == 'O') {
				user[i].isChange = true;
				user[i].pwd[j] = 'o';
//				printf("2");
			} else if((user[i].pwd[j] - '0') == 0) {
				user[i].pwd[j] = '%';
				user[i].isChange = true;
//				printf("3");
			} else if((user[i].pwd[j] - '0') == 1) {
				user[i].pwd[j] = '@';
				user[i].isChange = true;
//				printf("4");
			} 
		}
		if(user[i].isChange == true)	count++;
	}
//	printf("count:%d", count);
	if(count != 0) {
		printf("%d\n", count);
		for(int i = 0; i < n; i++) {
			if(user[i].isChange == true)	printf("%s %s\n", user[i].username, user[i].pwd);
		}
	} else if(n == 1){
		printf("There is 1 account and no account is modified\n");
	} else {
		printf("There are %d accounts and no account is modified\n", n);
	}
	return 0;
}
