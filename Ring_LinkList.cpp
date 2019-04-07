#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
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
			}
			else if(start->next == start){
				ptr = new node;
				cin >> ptr->info;
				ptr->next = start;
				start->next = ptr;
			}
			else{
				temp = ptr;
				ptr = new node;
				cin >> ptr->info;
				ptr->next = temp;
				start->next = ptr;
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
						delete temp;
						temp = NULL;
					}
					else if(ptr->next->info == key){
						temp = ptr->next;
						ptr->next = temp->next;
						delete temp;
						temp = NULL;
					}
					ptr = ptr->next;
				}while(ptr != start);
				
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
				cout << ptr->info << " --> ";
				}
				ptr = ptr->next;
			}
			cout << ptr->info << endl;	
		}
	
};


int main(){
	Link_List LL;
	LL.Insert_start();
	LL.Print();
	LL.Insert_start();
	LL.Insert_start();
	LL.Print();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Insert_start();
	LL.Print();
	LL.Deletion_one();
	LL.Print();
}
