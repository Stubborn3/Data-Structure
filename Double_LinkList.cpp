#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *prev;
};

class Link_List{
	private:
		node *start, *ptr, *temp;
	public:
		Link_List(){
			start = NULL;
			ptr = NULL;
			temp = NULL;
		}
		~Link_List(){
			delete start, ptr, temp;
		}
		
		void Insert_start(){
			if(start == NULL){
				start = new node;
				cin >> start->info;
				start->next = NULL;
				start->prev = NULL;
			}
			else{
				ptr = new node;
				cin >> ptr->info;
				ptr->next = start;
				start->prev = ptr;
				ptr->prev = NULL;
				start = ptr;
				
			}
		}
		
		void Insert_mid_end(){
			ptr = start;
			cout << "After the num " << endl;
			int key;
			cin >> key;
			while(ptr != NULL){
				if(ptr->info == key){
					temp = ptr;
					ptr = new node;
					cin >> ptr->info;
					ptr->next = temp->next;
					temp->next->prev = ptr;
					temp->next = ptr;
					ptr->prev = temp;
				}
				ptr = ptr->next;
			}
		}
		
		void Deletion(){
			cout << "Enter the Delete Number " << endl;
			int key;
			cin >> key;
			ptr = start;
			if(start == NULL){
				cout << "No value in Link list" << endl;
			}
			else if(key == ptr->info){
				temp = start;
				start = ptr->next;
				delete temp;
				temp = NULL;
				start->prev = NULL;
				}
			else{
				while(ptr->next != NULL){
					if(ptr->next->next == NULL && ptr->next->info == key){
						temp = ptr->next;
						ptr->next =  temp->next;
						delete temp;
						temp = NULL;
						return;
					}
					else if(ptr->next->info == key){
						temp = ptr->next;
						ptr->next = temp->next;
						temp->next->prev = ptr;
						delete temp;
						temp = NULL;
						return;
					}
					ptr = ptr->next;
				}
			}
		}
		
		void Search(){
			cout << "Enter the search Number" << endl;
			int key;
			cin >> key;
			ptr = start;
			while(ptr != NULL){
				if(ptr->info == key){
					cout << "It is search value" << endl;
					return;
				}
				ptr = ptr->next;
			}
			if(ptr == NULL){
				cout << "It is not search value" << endl;
			}
		}
		void Print(){
			ptr = start;
			cout << ptr->info << endl;
			while(ptr != NULL){
				if(ptr->next == NULL){
					cout << ptr->info << endl;
				}
				else{
					cout << ptr->info << " , ";
				}
				ptr = ptr->next;
			}	
		}
		
		
		void check(){
			
			ptr = start->next->next;
			cout << " ptr " << ptr->info << endl;
			temp = ptr;
			while(ptr != NULL){
				if(ptr == start && temp->next == NULL){
					cout << " same " << endl;
					return;
				}
				if(ptr == start){
					cout << " head " << endl;
					return; 
				}
				if(temp->next == NULL){
					cout << " end " << endl;
					return;
				}
				
				ptr = ptr->prev;
				temp = temp->next;
			}
		}
	
};


int main(){
	Link_List LL;
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Print();
	LL.Deletion();
	LL.Print();
}
