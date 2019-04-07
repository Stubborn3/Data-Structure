#include <iostream>
using namespace std;

struct node{
	int info;
	node *left, *right;
};

class completeBinaryTree{
	private:
		node *ptr, *hCheck, *heapdlt;
		int count, Height, totalNode, h, swap;
		bool flag;
	public:
		node *root;
		int value;
		completeBinaryTree(){
			root = ptr = hCheck = heapdlt = NULL;
			count = Height = totalNode = h = swap =  0;
		}
		
		~completeBinaryTree(){
			delete root, ptr, hCheck,heapdlt ;
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
				while(temp->left != NULL){
					temp = temp->left;
				}
				ptr = new node;
				ptr->info = value;
				ptr->left = NULL;
				ptr->right = NULL;
				temp->left = ptr;
				minHeap(root);
				count++;
				return;
			}
			
			if(count != totalNode){
				insertionSearch(temp);
				if(ptr->left != NULL && ptr->right == NULL){
					temp = new node;
					temp->info = value;
					ptr->right = temp;
					temp->left = NULL;
					temp->right = NULL;
					minHeap(root);
					count++;
					return;
				}
				if(ptr->left == NULL && ptr->right == NULL ){  
					temp = new node;
					temp->info = value;
					ptr->left = temp;
					temp->left = NULL;
					temp->right = NULL;
					minHeap(root);
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
				swap = temp->info;
				temp->info = heapdlt->info;
				heapdlt->info = swap;
				cout << temp->info << " is deleted" << endl;
				ptr->right = NULL;
				minHeap(root);
				delete temp;
				temp = NULL;
				return;
			}
			temp = ptr->left;
			if(hCheck == temp){
				Height--;
			}
			swap = temp->info;
			temp->info = heapdlt->info;
			heapdlt->info = swap;
			cout << temp->info << " is deleted" << endl;
			ptr->left = NULL;
			minHeap(root);
			delete temp;
			temp = NULL;
			return;
		}
		
		void minHeapLeft(node* temp){
				if(temp->left == NULL){
					return;
				}
				if(temp->info > temp->left->info ){
					swap = temp->info;
					temp->info = temp->left->info;
					temp->left->info = swap;
			 		return;
				}
				else{
					return;
				}	
		}
		void minHeapRight(node* temp){
				if(temp->right == NULL){
					
					return;
				}
				if(temp->info > temp->right->info ){
					swap = temp->info;
					temp->info = temp->right->info;
					temp->right->info = swap;
					return;
				}
				else{
					return;
				}	
		}
		void minHeap(node* temp){
			if(temp->left != NULL ){
				minHeapLeft(temp);
				minHeapRight(temp);
				minHeap(temp->left);
				minHeapLeft(temp);
				minHeapRight(temp);
			}
			if(temp->right != NULL ){
				minHeapLeft(temp);
				minHeapRight(temp);
				minHeap(temp->right);
				minHeapLeft(temp);
				minHeapRight(temp);
			}
			
		}
		
		void minHeapDeletion(node *temp){
			
			while(temp->left != NULL){
				if(temp->right == NULL){
					swap = temp->info;
					temp->info = temp->left->info;
					temp->left->info = swap;
					temp = temp->left;
				}
				else if(temp->left->info < temp->right->info){
					swap = temp->info;
					temp->info = temp->left->info;
					temp->left->info = swap;
					temp = temp->left;
				}
				else if(temp->left->info > temp->right->info){
					swap = temp->info;
					temp->info = temp->right->info;
					temp->right->info = swap;
					temp = temp->right;
				}
				else{
					break;
				}
			}
			heapdlt = temp;
			deletionCompleteBinaryTree(root);
			
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
   			cout << temp->info << " ";
   			if( temp->right != NULL ){
   				printCompleteBinaryTree(temp->right);	
		}
	}		
};

int main(){
	completeBinaryTree CBT;
	for(int i = 0; i <  1; i++){
		cout << "enter the value: " << endl;
		cin >> CBT.value;
		CBT.insertCompleteBinaryTree(CBT.root);
		cout << "root: " << CBT.root->info  << endl;
		CBT.printCompleteBinaryTree(CBT.root);
		cout << endl;
	}
	for(int i = 0; i < 1; i++){
		CBT.minHeapDeletion(CBT.root);
		CBT.printCompleteBinaryTree(CBT.root);
		cout << endl;
	}
		
	
		
}








