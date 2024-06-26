#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
	int data, height;
	node* lchild;
	node* rchild;
} *root;

int getHeight(node* root) {
	if(root == NULL) return 0;
	return root->height;
}

void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int data) {
	if(root == NULL) {
		root = new node;
		root->data = data;
  		root->height = 1;
  		root->lchild = root->rchild = NULL;
		return;
	}
	if(data < root->data) {
		insert(root->lchild, data);
		updateHeight(root);
		if(getBalanceFactor(root) == 2) {
			if(getBalanceFactor(root->lchild) == 1) 
				R(root);
			else if(getBalanceFactor(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	} else {
		insert(root->rchild, data);
		updateHeight(root);
		if(getBalanceFactor(root) == -2) {
			if(getBalanceFactor(root->rchild) == -1) 
				L(root);
			else if(getBalanceFactor(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main() {
	int n, temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		insert(root, temp);
	}
	printf("%d\n", root->data);
	return 0;
}
