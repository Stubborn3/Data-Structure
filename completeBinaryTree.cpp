#include <iostream>
using namespace std;

struct node{
	int info;
	node *left, *right;
	int index;
};

class completeBinaryTree{
	private:
		node *ptr, *hCheck;
		int count, Height, totalNode, h, number, dex, checkIndex, swap;
		bool flag;
	public:
		node *root;
		int value;
		completeBinaryTree(){
			root = ptr = hCheck = NULL;
			count = Height = totalNode = h = number = dex = checkIndex = swap = 0;
		}
		
		~completeBinaryTree(){
			delete root, ptr, hCheck;
		}
		
		int power(int h){
			if(h == 0){
				return 1;
			}
			else{
				return 2 * power(h-1);
			}
		}
		
		void insertCompleteBinaryTree(node *temp){
			flag = false;
			if(root == NULL){
					temp = new node;
					temp->info = value;
					temp->index = ++dex;
					temp->left = NULL;
					temp->right = NULL;
					root = temp;
					count++;
					totalNode++;
					return;
			}
			if(count == totalNode){
				count = 0;
				totalNode = power(Height+1);
				Height++;
				cout << "Height: " << Height << endl;
				cout << "totalNode: " << totalNode << endl;
				while(temp->left != NULL){
					temp = temp->left;
				}
				ptr = new node;
				ptr->info = value;
				ptr->index = ++dex;
				ptr->left = NULL;
				ptr->right = NULL;
				temp->left = ptr;
				count++;
				return;
			}
			if(count != totalNode){
				insertionSearch(temp);
				cout << "ptr->info:: " << ptr->info << endl;
				if(ptr->left != NULL && ptr->right == NULL){
					cout << "right: " << endl;  
					temp = new node;
					temp->info = value;
					temp->index = ++dex;
					ptr->right = temp;
					temp->left = NULL;
					temp->right = NULL;
					count++;
					return;
				}
				if(ptr->left == NULL && ptr->right == NULL ){
					cout << "left: " << endl;  
					temp = new node;
					temp->info = value;
					temp->index = ++dex;
					ptr->left = temp;
					temp->left = NULL;
					temp->right = NULL;
					count++;
					return;
				}
			}
			
		}
		
		void insertionSearch(node *temp){
   			if(temp->left!=NULL && h < Height){
   				h++;
   				insertionSearch(temp->left);
				h--; 
			}
			if((temp->left==NULL && h == Height-1) || (temp->right==NULL && h == Height-1)){
				if(flag == false){
					ptr = temp;
					flag = true;
					return;
				} 
			}
			if( temp->right!=NULL  ){
   				h++;
   				insertionSearch(temp->right);
				h--;
			}
   			
		}
		
		void buildMinHeap(){
			node *temp;
			if(root == NULL || root->left == NULL){
				return;
			}
			cout << "index " << dex << endl;
			checkIndex = dex/2;
			
			while(checkIndex != 0){
				searchBuildHeap(root);
				if(ptr->right == NULL){
					if(ptr->left->info < ptr->right->info && ptr->info > ptr->left->info){
						swap = ptr->info;
						ptr->info = ptr->left->info;
						ptr->left->info = swap;
						temp = ptr->left;
					}
					
				}
				else{
					if(ptr->left->info < ptr->right->info && ptr->info > ptr->left->info){
						swap = ptr->info;
						ptr->info = ptr->left->info;
						ptr->left->info = swap;
						temp = ptr->left;
					}
					if(ptr->left->info > ptr->right->info && ptr->info > ptr->right->info){
						swap = ptr->info;
						ptr->info = ptr->right->info;
						ptr->right->info = swap;
						temp = ptr->right;
					}
				}
				while((temp->left != NULL && temp->info > temp->left->info) || (temp->right != NULL && temp->info > temp->right->info)){
					if(temp->right == NULL){
						if(temp->left->info < temp->right->info && temp->info > temp->left->info){
							swap = temp->info;
							temp->info = temp->left->info;
							temp->left->info = swap;
							temp = temp->left;
						}
					}
					else{
						if(temp->left->info < temp->right->info && temp->info > temp->left->info){
							swap = temp->info;
							temp->info = temp->left->info;
							temp->left->info = swap;
							temp = temp->left;
						}
						else if(temp->left->info > temp->right->info && temp->info > temp->right->info){
							swap = temp->info;
							temp->info = temp->right->info;
							temp->right->info = swap;
							temp = temp->right;	
						}
					}
				}
				checkIndex--;		
			}
		}
		
		void searchBuildHeap(node *temp){
			if(temp->left != NULL){
				searchBuildHeap(temp->left);	
			}
			if(temp->index == checkIndex){
				ptr = temp;
			}
			if(temp->right != NULL){
				searchBuildHeap(temp->right);	
			}
		}
		void deletionCompleteBinaryTree(node* temp){
			deletionSearch(temp);
			if(root->left == NULL){
				delete root;
				root = NULL;
				return;
			}
			while(temp->left != NULL){
				temp = temp->left;
			}
			hCheck = temp;
			if(ptr->right != NULL){
				temp = ptr->right;
				cout << temp->info << " is deleted" << endl;
				ptr->right = NULL;
				delete temp;
				temp = NULL;
				return;
			}
			temp = ptr->left;
			cout << temp->info << " is deleted" << endl;
			if(hCheck == temp){
				Height--;
			}
			ptr->left = NULL;
			delete temp;
			temp = NULL;
			return;
		}
		
		void deletionSearch(node* temp){
			if(temp->left!=NULL && h < Height){
   				h++;
   				deletionSearch(temp->left);
				h--; 
			}
			if(h == Height-1 && temp->left != NULL){
				ptr = temp;
			}
			if(temp->right!=NULL && h < Height){
   				h++;
   				deletionSearch(temp->right);
				h--;
			}
		}
		
		
		void printCompleteBinaryTree(node *temp){
   			if(temp == NULL){    		
			   cout<<" Tree is empty.\n";       
			   return;    
			}
			
   			if(temp->left != NULL){
   				printCompleteBinaryTree(temp->left);	
			}
   			cout <<"[" << temp->index << "]: " << temp->info << " ";
   			if( temp->right != NULL ){
   				printCompleteBinaryTree(temp->right);	
		}
	}		
};

int main(){
	completeBinaryTree CBT;
	CBT.printCompleteBinaryTree(CBT.root);
	int array[15] = {65,31,32,26,21,19,68,13,24,15,14,16,5,70,12};
	for(int i = 0; i < 15; i++){
		CBT.value = array[i];
		CBT.insertCompleteBinaryTree(CBT.root);
		cout << endl;
	}
	CBT.printCompleteBinaryTree(CBT.root);
	cout << endl;
	CBT.buildMinHeap();
	CBT.printCompleteBinaryTree(CBT.root);
	cout << endl;
	
}








