#include <iostream>
using namespace std;



class redixSort{
	private:
		int *array, *temp, *ptr;
		int size, length, L, cLength, swap, t, p;
	public:
		redixSort(){
			temp = ptr = NULL;
			size = length = L = 0;
			array = new int[size];
		}
		
		~redixSort(){
			delete array, temp, ptr;
		}
		
		void checkLength(){
			cLength = *temp;
			while(2){
				if(cLength == 0){
					break;
				}
				cLength = cLength/10;
				L++;
			}
			if(length <= L){
				length = L;
				L = 0;
			}
		}
		
		void inputArray(){
			cout << "Enter the size: ";
			cin >> size;
			temp = array;
			for(int i = 1; i <= size; i++){
				cout << "Enter the value: ";
				cin >> *temp;
				checkLength();
				temp++;
			}
		}
		
		void checkRedixSortArray(){
			int temp1, ptr1;
			int i = 0;
			temp1 = *temp;
			ptr1 = *ptr;
			while(i < L){
				t = temp1 % 10;
				temp1 /= 10;
				p = ptr1 % 10;
				ptr1 /= 10;
				i++;
			}
		}
		
		void redixSortArray(){
			L = 1;
			while(L<= length){
				temp = array;
				for(int i = 1; i <= size; i++){
					ptr = temp+1;
					for(int j = i; j < size; j++){
						checkRedixSortArray();
						if(t > p){
							swap = *temp;
							*temp = *ptr;
							*ptr = swap;
						}
						ptr++;
					}
					temp++;
				}
				L++;
			}
		}
		
		void outputArray(){
			temp = array;
			cout << "print the value " << endl;
			for(int i = 0; i < size; i++){
				cout << *temp << " ";
				temp++;
			}
			
		}
		
};




int main(){
	redixSort r;
	r.inputArray();
	r.outputArray();
	cout << endl;
	r.redixSortArray();
	r.outputArray();
}
