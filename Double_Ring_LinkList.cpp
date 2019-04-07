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
				start->next = start;
				start->prev = start;	
			}
			else if(start->next == start){
				ptr = new node;
				cin >> ptr->info;
				ptr->next = start;
				start->next = ptr;
				start->prev = ptr;
				ptr->prev = start;	
			}
			else{
				temp = ptr;
				ptr = new node;
				cin >> ptr->info;
				ptr->next = temp;
				start->next = ptr;
				temp->prev = ptr;
				ptr->prev = start;
			}
		}
		
		void Insert_mid_end(){
			ptr = start;
			cout << "After the num " << endl;
			int key;
			cin >> key;
			do{
				if(ptr->info == key){
					temp = ptr;
					ptr = new node;
					cin >> ptr->info;
					ptr->next = temp->next;
					ptr->prev = temp;
					ptr->next->prev = ptr;
					temp->next = ptr;
					
				}
				ptr = ptr->next;
			}while(ptr != start);
		}
		
		void Deletion_one(){
			cout << "Enter the Delete Number " << endl;
			int key;
			cin >> key;
			ptr = start;
			if(start == NULL){
				cout << "No value in Link list" << endl;
			}
			else{
				do{
					if(key == ptr->next->info && ptr->next->info == start->info){
						temp = start;
						start = temp->next;
						ptr->next = start;
						start->prev = ptr;
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
				}while(ptr != start);
				
				
			}
		}
		
		
		
		
		
		void searchF_R(){
			ptr = start;
			temp = start;
			int n, c_f, c_r;
			c_f = 0;
			c_r = 0;
			cout << "head" << start->info << endl;
			cout << "enter: ";
			cin >> n;
			if(start->info == n){
				cout << "Position " << c_f << " It is search for head " << endl;
				return; 
			}
			do{
				if(ptr->info == n){
					cout << "Position "  << c_f << " It is search for forward " << endl; 
					return;
				}
				
				if(temp->info == n){
					cout << "Position "  << c_r << " It is search for back " << endl; 
					return;
				}
				c_r++;
				
				ptr = ptr->next;
				temp = temp->prev;
				
			}while(ptr != start || temp != start);
		}
		void search1(){
			ptr = start;
			int k;
			cin >> k;
			if(recSearch(ptr, k) == k){
				cout << "the key is found" << endl;
			}
			else{
				cout << "it is not" << endl;
			}
			
		}
		
		int recSearch(node *ptr,int key){
			if(ptr->next == start){
				return ptr->info;
			}
			
			if(ptr->info == key){
				return ptr->info;
			}
			else{
				recSearch(ptr->next,key);
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		void Search(){
			cout << "Enter the search Number" << endl;
			int key;
			cin >> key;
			ptr = start;
			do{
				if(ptr->info == key){
					cout << "It is search value" << endl;
					return;
				}
				ptr = ptr->next;
			}while(ptr != start);
			cout << "It is not search value" << endl;
		}
		
		void Print(){
			ptr = start->next;
			while(ptr != start){
				{
				cout << ptr->info << " <---> ";
				}
				ptr = ptr->next;
			}
			cout << ptr->info << endl;	
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
	LL.search1();
	LL.Print();
}
