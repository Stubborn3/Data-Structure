#include <iostream>
using namespace std;

struct node{
	int info;
	node *right, *left;
};

class BinarySearchTree{
	private:
		node *ptr, *ptr1;
		int swap;
	public:
		node *root;
		int value;
		int found;
		BinarySearchTree(){
			ptr = root = NULL;
		}
		~BinarySearchTree(){
			delete ptr, root;	
		}
		void InsertBinarySearchTree(node *temp){
			if(root == NULL){
				temp = new node;
				temp->info = value;
				temp->left = NULL;
				temp->right = NULL;
				root = temp;
				return;
			}
			if(temp->info == value){
				cout << "Enter the unique number not duplicate number " << endl;
				return;
			}
			if(temp->info < value){
				if(temp->right != NULL){
					InsertBinarySearchTree(temp->right);
					return;
				}
				else{
					temp->right = new node;
					temp->right->info = value;
					temp->right->right = NULL;
					temp->right->left = NULL;
					return;
				}
			}
			if(temp->info > value){
				if(temp->left != NULL){
					InsertBinarySearchTree(temp->left);
					return;
				}
				else{
					temp->left = new node;
					temp->left->info = value;
					temp->left->left = NULL;
					temp->left->right = NULL;
					return;
				}
			}
		}
			
		void PrintBST_PreOrder(node *temp){
			if(root == NULL){
				cout << "Tree is empty" << endl;
				return;
			}
			cout  << "    " << temp->info << endl;
			if(temp->left != NULL){
				cout << "    /" << endl;
				PrintBST_PreOrder(temp->left);
			}
			if(temp->right != NULL){
				cout << "     \\" << endl;
				PrintBST_PreOrder(temp->right);
			}
		}
		
		void DeleteSearchTrue(node *temp){
			if(root == NULL){
				cout << "Tree is empty" << endl;
				return;
			}
			if(temp->info == value){
				found = 1;
			}
			if(temp->info > value){
				if(temp->left != NULL){
					DeleteSearchTrue(temp->left);
				}
			}
			
			if(temp->info < value){
				if(temp->right != NULL){
					DeleteSearchTrue(temp->right);
				}
			}
		}
		
		void DeletionBinarySearchTree(node *temp){
			if(root == NULL){
				cout << "Tree is empty" << endl;
				return;
			}	
			// Delete Left Right and Root ------------------------------------------------------------------
			if(temp->info < value){
				if(temp->info != value){
					ptr = temp;
					DeletionBinarySearchTree(temp->right);
					return;
				}
			}
			if(temp->info > value){
				if(temp->info != value){
					ptr = temp;
					DeletionBinarySearchTree(temp->left);
					return;
				}
			}
			// Case 1:
			if(temp->info == value && temp->right == NULL && temp->left == NULL){
				if(root == temp){
					delete root;
					root = NULL;
					return;
				}
				delete temp;
				temp = NULL;
				ptr->left = NULL;
				ptr->right = NULL;
				return;
			}
			// Case 2:	
			if(temp->info == value && temp->left == NULL && temp->right != NULL){
				if(temp == root){
					root = temp->right;
					delete temp;
					temp = NULL;
					return;
				}
				ptr->right = temp->right;
				delete temp;
				temp = NULL;
				return;
			}
			if(temp->info == value && temp->left != NULL && temp->right == NULL){
				if(temp == root){
					root = temp->left;
					delete temp;
					temp = NULL;
					return;
				}
				ptr->left = temp->left;
				delete temp;
				temp = NULL;
				return;
			}
			// Case 3:
			if(temp->info == value && temp->right != NULL && temp->left != NULL){
				ptr = temp->right;
				if(ptr->left == NULL){
					swap = temp->info;
					temp->info = ptr->info;
					ptr->info = swap;
					if(ptr->right == NULL){
						temp->right = NULL;
						delete ptr;
						ptr = NULL;
						return;
					}
					temp->right = ptr->right;
					delete ptr;
					ptr = NULL;
					return;
				}
				else{
					while(ptr->left->left != NULL){
						ptr = ptr->left;
					}
					swap = temp->info;
					temp->info = ptr->left->info;
					ptr->left->info = swap;
					if(ptr->left->right == NULL){
						delete ptr->left;
						ptr->left = NULL;
						return;
					}
					temp = ptr->left;
					ptr->left = ptr->left->right;
					delete temp;
					temp = NULL;
					return;	
				}
			}
		}
		//--------------------------------------------------------------------
		
		int height(node *temp){
			int lh = 0;
			int rh = 0;
			int h = 0;
			if(temp->left != NULL) {
				lh++;
				lh += height(temp->left);
			}
			if(temp->left == NULL && temp->right == NULL){
				lh--;
			}
			if(temp->right != NULL) {
				rh++;
				rh += height(temp->right);
			}
			if (lh >= rh){
				h = rh + lh;
				return h;
			}
			if (rh >= lh){
				h = rh + lh;
				return h;
			}
		}
		
		void balance(node *temp){
			int leftHeight = 0;
			int rightHeight = 0;
			if (root == NULL){
				return;
			}
			if(temp->left == NULL && temp->right == NULL){
				return;
			}
			if (temp->left != NULL){
				leftHeight = height(temp->left)+1;
			}
			if (temp->right != NULL){
				rightHeight = height(temp->right)+1;	
			}
			cout << "parent: " << temp->info << endl;
			cout << "leftChild: " << leftHeight << " rightChild: " << rightHeight << endl;
		}
		
		void inordert(node* temp){
			if(temp->left != NULL){
				
				inordert(temp->left);
			}
			balance(temp);
			if(temp->right != NULL){
				inordert(temp->right);
			}
		}
}; 

int main(){
	
	BinarySearchTree BST;
	while(3){
		int num, count;
		cout << "Insert the value:(1) " << "Delete the value:(2) " << "Print the tree:(3) " <<"Exit: Press (any other value) " << endl;
		cin >> num;
		if(num == 1){
			cout << "Enter the nodes Insert?" << endl;
			cin >> count;
			for(int i = 0; i < count; i++){
				cout << "Enter the value" << endl;
				cin >> BST.value;
				BST.InsertBinarySearchTree(BST.root);
			}
			cout << "aa" << endl;
			BST.inordert(BST.root);
		}
		else if(num == 3){
			BST.PrintBST_PreOrder(BST.root);
		}
		else if(num == 2){
			cout << "Enter the Delete value" << endl;
			cin >> BST.value;
			BST.found = 0;
			BST.DeleteSearchTrue(BST.root);
			if(BST.found == 1){
				BST.DeletionBinarySearchTree(BST.root);
				cout << BST.value << " is deleted" << endl;
			}
			else{
				cout << "Value is not in a tree" << endl;
			}
		}
		else{
			exit(0);	
		}
	}
	return 0;
}
