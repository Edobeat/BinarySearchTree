#include <iostream>
using namespace std;

struct Node {
	Node* left;
	int data;
	Node* right;

	Node(int val) {
		this->data = val;
		this->left = this->right = nullptr;
	}
};

class BST {
	Node* root;
public:
	BST() {
		root = nullptr;
	}

	Node* _insert(Node* root, int element) {
		if (!root) {
			root = new Node(element);
		}
		if (root->data > element) {
			root->left = _insert(root->left, element);
		}
		else if (root->data < element) {
			root->right = _insert(root->right, element);
		}

		return root;
	}

	void insert(int ele) {
		root = _insert(root, ele);
	}

	void inOrder() {
		_inOrder(root);
	}

	void _inOrder(Node* root) {
		if (root) {
			_inOrder(root->left);
			std::cout << root->data << " ";
			_inOrder(root->right);
		}
	}

	void removeEle(int ele) {
		root = remove(root, ele);
	}

	Node* remove(Node* root, int ele) {
		if (!root) {
			return nullptr;
		}

		if (root->data > ele) {
			root->left = remove(root->left, ele);
		}
		else if (root->data < ele) {
			root->right = remove(root->right, ele);
		}
		else {
			if (!root->left && !root->right) {
				delete root;
				return nullptr;
			}
			else if (!root->left) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (!root->right) {
				Node* tmp = root->left;
				delete root;
				return tmp;
			}
			else {
				Node* tmp = root->right;
				while (tmp->left) {
					tmp = tmp->left;
				}

				root->data = tmp->data;
				root->right = remove(root->right, tmp->data);
			}
		}
		return root;
	}


}
;


int main()
{
	BST t;
	t.insert(10);
	t.insert(2);
	t.insert(15);
	t.insert(0);
	t.insert(4);
	t.insert(13);
	t.insert(16);
	t.inOrder();
	std::cout << "\n\n\n";
	t.removeEle(16);
	t.removeEle(15);
	t.removeEle(10);
	t.removeEle(100);
	t.inOrder();
}
