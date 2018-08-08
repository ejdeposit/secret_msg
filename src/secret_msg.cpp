using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
void init_array(char array1[], char array2[], int size1, int size2);
bool read_msg(char filePath[], char msg[]);
bool read_txt(char filePath[], char txt[]);
void remove_upper(char text[]);
void remove_spaces(char msg[]); 
void encode(char msg[], char text[]);

int main(){
	//variables
	int msgSize= 99;
	int textSize= 999;
	char msg[msgSize];
	char text[textSize];
	char cMsgFilePath[20]= "secret_message";   
	char cTxtFilePath[20]= "paragraph";

	//initialize array
	init_array(msg, text, msgSize, textSize);

	// sementation fault here
	//cout << "test output of Initialized arrays"  << msg << endl << text << endl << "***" << endl;
	
	//read in secrete message into array
	 read_msg(cMsgFilePath, msg);

	//read in paragraph into array
	 read_txt(cTxtFilePath, text);
	
	//TEST  
	cout << endl << "message: " << msg  << endl;
	cout << endl << "Paragraph: " << endl << text << endl;
	
	//remove uppercase letters from paragraph array
	remove_upper(text);	
	
	//TEST 
	//cout << endl<< "paragraph with out upper case letters" << endl  << text << endl;

	//remove spaces from secret msg
	remove_spaces(msg);
	
	//TEST 
	//cout << endl << "***" << msg << "***"  << endl;
	
	//place secrete message letters in paragraph encode message into parapgraph array
	encode(msg, text);
	
	//TEST
	cout << endl << text << endl;
	
	//write encoded message to file and read and print to screen

	return 0;
}

void init_array(char array1[], char array2[], int size1, int size2){
for(int i= 0; i < size1; i++){
	array1[i]=0;
}	
for(int i= 0; i < size2; i++){
	array2[i]=0;
}	
return;
}

bool read_msg(char filePath[], char msg[]){

	ifstream inMsg;
	int i=0;	

	inMsg.open(filePath);	
	
	if(inMsg.is_open()){
		
		while(!inMsg.eof()){		
		inMsg.get(msg[i]);
		i++;
		}
		
		inMsg.close();
		return 1;	
	}
	cout << endl << "Error: cannot open file. " << endl;
	return 0;
}

bool read_txt(char filePath[], char txt[]){	

	ifstream inMsg;
	int i=0;	

	inMsg.open(filePath);	
	//inMsg.open("secret_msg");
	
	if(inMsg.is_open()){
		
		while(!inMsg.eof()){		
		inMsg.get(txt[i]);
		i++;
		}
		
		inMsg.close();
		return 1;	
	}
	cout << endl << "Error: cannot open file. " << endl;
	return 0;
}

void remove_upper(char text[]){
	int i=0;
	while(text[i] != 0){	
		text[i] = tolower(text[i]);
		i++;
	}	
	return;
}

void remove_spaces(char msg[]){
	int noSpaceCount= 0;
	//int withSpaceCount= 0;
	int length= strlen(msg);
	//	cout << endl << "string length"  << strlen(msg) << endl; 
	
	for(int i=0; i< length; i++){
		//insert upper case letter where space follows
		if ((msg[i] != 32) && ( msg[i+1] == 32))		
		msg[i]=	toupper(msg[i]);
		//remove spaces if 
		if(msg[i] != 32){
			msg[noSpaceCount] = msg[i];
			noSpaceCount++;
		}	
	}	
	//place null character after last letter and make last letter capital
	msg[noSpaceCount-1]=0;
	msg[noSpaceCount-2]= toupper(msg[noSpaceCount-2]);	
	return;
}
 
void encode(char msg[], char text[]){
	int msgIndex= 0;
	int textIndex= 0;	
	int stringLength= strlen(msg);	
	
	//cout << endl << "string Length= " <<  strlen(msg) << endl;
	
	//replace fist letter of paragraph with first letter of message
	text[textIndex]= msg[msgIndex];
	msgIndex++;
	textIndex++;

	
	while(msg[msgIndex] != 0){
		//if ((text[textIndex] == 32 || text[textIndex] == '\n') && text[textIndex+1] != 32 && text[textIndex+1] != '\n'){
		if (text[textIndex] == 32 && text[textIndex+1] != 32){
		//	cout << text[textIndex]  <<  '*';
			text[textIndex+1] = msg[msgIndex];	
			msgIndex++;
			textIndex++;
		}
		else{
		//cout << text[textIndex] << '#';
		textIndex++;
		}
	}
return;
}
