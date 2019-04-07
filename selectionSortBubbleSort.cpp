#include <iostream>
using namespace std;

class selectionSortAndBubbleSort{
	private:
		int *temp, *array, *ptr;
		int size, swap;
	public:
		selectionSortAndBubbleSort(){
			temp = array = ptr = NULL;
			size = 0;
			array = new int[size];
		}
		~selectionSortAndBubbleSort(){
			delete temp, ptr;
			
		}
		void inputArray(){
			cout << "Enter the size: ";
			cin >> size;
			cout << "Enter the value: " << endl;
			temp = array;
			for(int i = 1; i <= size; i++){
				cin >> *temp;
				temp++;
			}
		}
		void selectionSortSet(){
			
			ptr = array;
			for(int i = 1; i < size; i++){
				temp = ptr;
				for(int j = i; j < size; j++){
					temp++;
					if(*ptr > *temp){
						swap = *ptr;
						*ptr = *temp;
						*temp = swap;	
					}	
				}
				ptr++;
			}
		}
		
		void BubbleSortSet(){
			int length;
			length = size;
			for(int i = 1; i <= size; i++){
				temp = array;
				ptr = array+1;
				for(int j = 1; j <= length; j++){
					if(*ptr < *temp){
						swap = *ptr;
						*ptr = *temp;
						*temp = swap;	
					}	
					ptr++;
					temp++;
				}
				length--;
			}
		}
		
		void outPutArray(){
			temp = array;
			for(int i = 1; i <= size; i++){
				cout <<  *temp << " ";
				temp++;
			}
		}
};


int main(){
	selectionSortAndBubbleSort ss;
	ss.inputArray();
	ss.outPutArray();
	cout << endl;
	ss.selectionSortSet();
	ss.outPutArray();
	cout << endl;
	
}



