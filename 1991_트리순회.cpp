#include<iostream>

using namespace std;

typedef struct {
	char key;
	int left;
	int right;
}node;

int n;
node* Node;

void preorder(int ptr) {
	if (ptr >= 0) {
		cout << Node[ptr].key;
		preorder(Node[ptr].left);
		preorder(Node[ptr].right);
	}
}
void inorder(int ptr) {
	if (ptr>=0) {
		inorder(Node[ptr].left);
		cout << Node[ptr].key;
		inorder(Node[ptr].right);
	}
}
void postorder(int ptr) {
	if (ptr >= 0) {
		postorder(Node[ptr].left);
		postorder(Node[ptr].right);
		cout << Node[ptr].key;
	}
}

int main() {
	
	cin >> n;
	Node = new node[n + 1];

	for (int i = 0; i < n; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		Node[root-65] = { root,-1, -1 };
		if (left != 46) Node[root - 65].left = left - 65;
		if (right != 46) Node[root - 65].right = right - 65;
	}

	preorder(0); // 0<- 65-65이므로 루트 A를 나타냄
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);

	return 0;
}