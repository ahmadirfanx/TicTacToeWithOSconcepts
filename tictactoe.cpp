//developed by Ahmad Irfan and Amna Zahoor at FAST National University, Pakistan.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


using namespace std;
srand(time(0));
void *printBoard(void *args);
void *initializeArray(void *args);
bool PlaceMove();
bool ValidateMove();
void ChangeTurns();
bool CheckWinningCondition();
bool CheckIfFull();
void VsPlayer();
void VsComputer();
void menu();
void AttackMode();
void PlaceRandom();

pthread_mutex_t lock;  //mutex lock
char array[9];
char CurrentTurn='X';
char Winner=0;

int main(){
menu();
}

void VsPlayer(){ //--------------------------------------main
pthread_t main_thread; //parent thread
pthread_create(&main_thread, NULL, initializeArray, NULL); 
pthread_join(main_thread, NULL);
bool terminate=false;
cout << "Ola!" << endl;
while (terminate==false){
	terminate= PlaceMove();
	if (!terminate){
	terminate= CheckIfFull();
	}
	cout << "terminate: " << terminate << endl;

	pthread_t th2; //thread for print function
	pthread_create(&th2, NULL, printBoard, NULL); 
	pthread_join(th2, NULL);
	
	ChangeTurns();
	}
cout << "Player " << Winner << " wins the game!" << endl;
}

void VsComputer(){

}
void AttackMode(){
if ((array[0]==' ' && array[1]==array[2] && array[2]=='X')||(array[0]==' ' && array[3]==array[6] && array[6]=='X') || (array[0]==' ' && array[4]==array[8] && array[8]=='X')) {
array[0]='O';
}
else if ((array[2]==' ' && array[0]==array[1] && array[1]=='X')||(array[2]==' ' && array[4]==array[6] && array[6]=='X') || (array[2]==' ' && array[5]==array[8] && array[8]=='X')) {
array[2]='O';
}
else if ((array[6]==' ' && array[7]==array[8] && array[8]=='X')||(array[6]==' ' && array[7]==array[8] && array[8]=='X') || (array[6]==' ' && array[4]==array[2] && array[2]=='X')) {
array[6]='O';
}
else if ((array[8]==' ' && array[6]==array[7] && array[7]=='X')||(array[8]==' ' && array[0]==array[4] && array[4]=='X') || (array[8]==' ' && array[2]==array[5] && array[5]=='X')) {
array[8]='O';
}
else if ((array[1]==' ' && array[0]==array[2] && array[2]=='X')||(array[1]==' ' && array[4]==array[7] && array[7]=='X')) {
array[1]='O';
}
else if ((array[3]==' ' && array[4]==array[5] && array[5]=='X')||(array[3]==' ' && array[1]==array[7] && array[7]=='X')) {
array[3]='O';
}
else if ((array[5]==' ' && array[3]==array[4] && array[4]=='X')||(array[5]==' ' && array[2]==array[8] && array[8]=='X')) {
array[5]='O';
}
else if ((array[7]==' ' && array[6]==array[8] && array[8]=='X')||(array[7]==' ' && array[1]==array[4] && array[4]=='X')) {
array[7]='O';
}
else if ((array[4]==' ' && array[7]==array[1] && array[1]=='X')||(array[4]==' ' && array[3]==array[5] && array[5]=='X') ||(array[4]==' ' && array[0]==array[8] && array[8]=='X') ||(array[4]==' ' && array[2]==array[6] && array[6]=='X')) {
array[4]='O';
}
void PlaceRandom();
}

void PlaceRandom(){

}
void menu(){
cout << "\t for Player 1 vs. Player 2 press 1"<< endl << "\t for Player vs. Computer press 2" << endl; 
string choice;
cin >> choice;
if (choice=="1"){
VsPlayer();
}
else if (choice =="2"){
VsComputer();
}
else {
cout << "invalid input. please re-enter value..."<< endl;
	menu();
}
}
void *initializeArray(void *Args){
cout << "initializing Array" << endl;
for (int i=0; i<9; i++)
array[i]=' ';
}

void *printBoard(void *args){
int count =0;
cout << "\t *************************" << endl;
for (int j=0; j<3; j++){
	for (int k=0; k<3;k++){
		if (k==1){
		cout << "\t |";
			for (int p=0; p<3;p++){
				cout <<"   " << array[count] << "   |";
				count++;
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
bool ValidateMove(int x);

bool PlaceMove(){
cout << CurrentTurn << "'s Turn. Enter index: ";
int choice;
cin >> choice;
if (choice >=0 && choice<=9 && ValidateMove(choice)){
	array[choice]=CurrentTurn;
	cout << "Array updated, index: " << choice << " array: " <<array[choice] << endl;
	if (CheckWinningCondition()){
		return true;
	}
	else return false;
	}
else {
	cout << "invalid number entered. Enter a Valid number..." << endl;
	PlaceMove();
	}
}

bool ValidateMove(int x){	
if (array[x]==' '){
	return true;	
	}
else return false;
}

bool CheckWinningCondition(){
if (array[0]==array[1] && array[1]==array[2] && (array[2]=='X' || array[2]=='O')) Winner=array[2];
else if (array[0]==array[3] && array[3]==array[6] && (array[6]=='X' || array[2]=='O')){
 Winner=array[6];}
else if (array[2]==array[5] && array[5]==array[8] && (array[8]=='X' || array[2]=='O')){ 
Winner=array[8]; }
else if (array[6]==array[7] && array[7]==array[8] && (array[8]=='X' || array[2]=='O')){
 Winner=array[8];}
else if (array[1]==array[4] && array[4]==array[7] && (array[7]=='X' || array[2]=='O')){
 Winner=array[7];}
else if (array[1]==array[4] && array[4]==array[7] && (array[7]=='X' || array[2]=='O')){
 Winner=array[7];}
else if (array[3]==array[4] && array[4]==array[5] && (array[5]=='X' || array[2]=='O')){
 Winner=array[5];}
else if (array[1]==array[4] && array[4]==array[7] && (array[7]=='X' || array[2]=='O')){
 Winner=array[7];}
else if (array[0]==array[4] && array[4]==array[8] && (array[8]=='X' || array[2]=='O')){
 Winner=array[8];}
else if (array[1]==array[4] && array[4]==array[7] && (array[7]=='X' || array[2]=='O')){
 Winner=array[7];}
else if (array[2]==array[4] && array[4]==array[6] && (array[6]=='X' || array[2]=='O')){
 Winner=array[6];}


if (Winner=='X' || Winner=='O'){
cout << "Winner found: "<< Winner << endl;
return true;
}

else return false;
}

bool CheckIfFull(){
	int count=0;
	for (int i=0; i<9; i++){
	if (array[i]=='X' || array[i]=='O'){
		count++;
		}
	}
	if (count==9){
return true;
}
else return false; 
}

void ChangeTurns(){
if (CurrentTurn=='X')
CurrentTurn='O';
else if (CurrentTurn='O')
CurrentTurn='X';
}
