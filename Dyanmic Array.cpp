#include <iostream>
using namespace std;




class List{
	private:
		int *ptr1; *start; *end; *temp;
		int length;
	public:
		List(){
			ptr1 = NULL;
			start = NULL;
			end = NULL;
			temp = NULL;
			length = 0;
		}
		
		~List(){
			delete ptr1, start, end, temp;
			delete [] ptr1;
		}
		
		void Input(){
			
			cout << " Enter the length of array: ";
			cin >> length;
			ptr1 = new int[length];
			start = ptr1;
			for(int i = 1; i <= length; i++){
				cin >> *ptr1;
				if(i == length){
					end = ptr1;
				}
				ptr1 += 1;
			}
			ptr1 = start;
			
		}
		
		int Get(){
			return *ptr1;
		}
		
		void Remove(){
			cout << " Enter the delete num: ";
			int x;
			cin >> x;
			ptr1 = start;
			temp = ptr1 + 1;
			for(int i = 1; i <= length; i++){
				if(*ptr1 == x){
					*ptr1 = NULL;
					ptr1 -= 1;
					temp -= 1;
					i -= 1;
				}
				else if(*ptr1 == NULL){
					*ptr1 = *temp;
					*temp = NULL;
				}	
				ptr1 += 1;
				temp += 1;
			}
			if(*end == NULL){
					end -= 1;
					length -= 1;
				}
			ptr1 = start;
			
		}
		
		void Add(){
			cout << " Enter the add num: ";
			int a, b;
			cin >> a;
			cout << " Enter the add after num: " << endl;
			cin >> b;
			ptr1 = end;
			temp = ptr1 + 1;
			for(int i = length; i >= 1 ; i--){
				if(*ptr1 == b){
					*temp = a;
					length += 1;
					return;
				}
				else{
					int h = 0;
					h = *ptr1;
					*ptr1 = *temp;
					*temp = h;
				}
				
				if(i == length){
					end += 1;
				}
				temp -= 1;
				ptr1 -= 1;
				
			}
			ptr1 = start;
		}
		
		void Find(){
			ptr1 = start;
			int x;
			cout << " Enter the found num: ";
			cin >> x;
			for(int i = 1; i <= length; i++){
				if(*ptr1 == x){
					cout << " Found Successfully " << endl;
				}
				else if(*ptr1 == *end){
					cout << " Not Found " << endl;
				}
				ptr1 += 1;
			}
			ptr1 = start;	
		}
		
		void Update(){
			ptr1 = start;
			int x,y;
			cout << " Enter the Update num: ";
			cin >> x;
			cout << " Enter the position: ";
			cin >> y;
			for(int i = 1; i <= length; i++){
				if(i == y){
					*ptr1 = x;
				}
				ptr1 += 1;
			}
			ptr1 = start;	
		}
		
		void Length(){
			int s;
			s = length;
			cout << "Size: " << s << endl;
		}
		
		void Back(){
			cout << " Before Current Pointer in Back: " << *ptr1 << endl;
			if(ptr1 != start){
				ptr1 -= 1;
			}
			else{
				ptr1 = start;
			}
			cout << " After Current Pointer in Back: " << *ptr1 << endl;
			
		}
		
		void Next(){
			cout << " Before Current Pointer in Next: " << *ptr1 << endl;
			if(ptr1 != end){
				ptr1 += 1;
			}
			else{
				ptr1 = end;
			}
			cout << " After Current Pointer in Next: " << *ptr1 << endl;
		}
		
		void Start(){
			ptr1 = start;
			cout << " Current Pointer in Start: " << *ptr1 << endl;
		}
		
		void End(){
			ptr1 = end;
			cout << " Current Pointer in End: " << *ptr1 << endl;
		}
		void Show(){
			ptr1 = start;
			for(int i = 1; i <= length; i++){
				if(i == length){
					cout << *end;
				}
				else{
					cout << *ptr1 << " , ";
				}
				
				ptr1 += 1;
			}
			cout << endl; 
			ptr1 = start;
		}
		
		
		
};


int main(){
	List l1;
	l1.Input();
	cout << "Get Current Pointer " <<l1.Get() << endl;
	l1.Show();
	l1.Add();
	l1.Show();
	
}
