#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;
bool judge(char c) {
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	return false;
}
int main() {
	string str;
	getline(cin, str);
	map<string, int> count;
	int i = 0;
	while(i < str.length()) {
		string word;
		while(i < str.length() && judge(str[i]) == true) {
			if(str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			word += str[i];
			i++;
		}
		if(word != "") {
			if(count.find(word) != count.end())
				count[word]++;
			else 
				count[word] = 1;
		}
		while(i < str.length() && judge(str[i]) == false)
			i++;
	}
	string res;
	int max = 0;
	for(map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
		if(it->second > max) {
			max = it->second;
			res = it->first;
		}
	}
	printf("%s %d", res.c_str(), max);
	return 0;
}
