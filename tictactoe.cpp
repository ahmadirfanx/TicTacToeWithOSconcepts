#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;
void *printBoard(void *args);
void *initializeArray(void *args);

char array[9];


int main(){
pthread_t main_thread; //parent thread
cout << "Ola!" << endl;
pthread_create(&main_thread, NULL, initializeArray, NULL); 
pthread_join(main_thread, NULL);

pthread_t th2; //thread for print function
pthread_create(&th2, NULL, printBoard, NULL); 
pthread_join(th2, NULL);


return 0;
}

void *initializeArray(void *Args){
cout << "initializing Array" << endl;
for (int i=0; i<9; i++)
array[i]=' ';
}

void *printBoard(void *args){
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
