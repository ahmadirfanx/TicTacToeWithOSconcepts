#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;
void printBoard();
void initializeArray();
char array[9];


int main(){
cout << "Ola!" << endl;
initializeArray();
printBoard();

return 0;
}

void initializeArray(){
for (int i=0; i<9; i++)
array[i]=' ';
}
void printBoard(){
cout << "\t *************************" << endl;
for (int j=0; j<3; j++){
	for (int k=0; k<3;k++){
	if (k==1){
	cout << "\t |";
		for (int p=0; p<3;p++){
			cout <<"   " << array[p] << "   |";
		}
cout << endl;
	}
else {
		for (int i=0; i<4; i++){
		cout << "\t |";
		}
		cout << endl;
	}
}
	cout<< "\t *************************" << endl;
	}
}
