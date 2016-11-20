// info450music.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
using namespace std;

// Node class
stringstream ss;
string s;
int songNum = 1;
class Node {
	string   data;
	Node* next;

public:
	Node() {};
	void SetData(string aData) { data = aData; };
	void SetNext(Node* aNext) { next = aNext; };
	string  Data() { return data; };
	Node* Next() { return next; };
};

// List class
class List {
	Node *head;
public:
	List() { head = NULL; };
	void Print();
	void Play();
	void Insert(string data);
	void Delete(string data);
	void DeleteTheSong(int delNum);
	void Skip(int num);
};

/**
* Print the contents of the list
*/

void List::Print() {

	// Temp pointer
	Node *tmp = head;
	int i = 1;
	// No nodes
	if (tmp == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	// One node in the list
	if (tmp->Next() == NULL) {

	}
	else {
		// Parse and print the list
		do {
			cout << i;
			cout << ": \t";
			cout << tmp->Data() << endl;
			//  cout << " --> ";
			tmp = tmp->Next();
			i++;
		} while (tmp != NULL);

	}
}


/*
Play the song..

*/


void List::Play() {

	// Temp pointer
	Node *tmp = head;
	int i = 1;
	// No nodes
	if (tmp == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	// One node in the list
	if (tmp->Next() == NULL) {

	}
	else {
		// Parse and print the list
		do {
			if (songNum == i) {


				cout << " ****Song Play**** " << endl;



				//cout<<"............................"<<endl;
				cout << i;
				cout << ":";
				cout << tmp->Data() << endl;

				//cout<<"----------------------------";
				cout << endl << endl;

				//songNum++;
			}

			tmp = tmp->Next();
			i++;
		} while (tmp != NULL);

	}
}




/***

Skip the music
*/

void List::Skip(int num) {

	// Temp pointer
	cout << endl;
	cout << endl;
	Node *tmp = head;
	int i = 1;
	// No nodes
	if (tmp == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	// One node in the list
	if (tmp->Next() == NULL) {
		cout << "noting in list" << endl;
	}
	else {
		// Parse and print the list
		do {
			if (i == num) {
				cout << "currently Song play : \t";
				cout << tmp->Data() << endl;
			}
			//  cout << " --> ";
			tmp = tmp->Next();

			i++;
		} while (tmp != NULL);

	}
}
/**
* Append a node to the linked list
*/
void List::Insert(string data) {

	// Create a new node
	Node* newNode = new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);

	// Create a temp pointer
	Node *tmp = head;

	if (tmp != NULL) {
		// Nodes already present in the list
		// Parse to end of list
		while (tmp->Next() != NULL) {
			tmp = tmp->Next();
		}

		// Point the last node to the new node
		tmp->SetNext(newNode);
	}
	else {
		// First node in the list
		head = newNode;
	}
}

/**
* Delete a node from the list
*/
void List::Delete(string data) {

	// Create a temp pointer
	Node *tmp = head;

	// No nodes
	if (tmp == NULL)
		return;

	// Last node of the list
	if (tmp->Next() == NULL) {
		delete tmp;
		head = NULL;
	}
	else {
		// Parse thru the nodes
		Node *prev;
		do {
			if (tmp->Data() == data) break;
			prev = tmp;
			tmp = tmp->Next();
		} while (tmp != NULL);

		// Adjust the pointers
		prev->SetNext(tmp->Next());

		// Delete the current node
		delete tmp;
	}
}
void List::DeleteTheSong(int delNum) {

	// Create a temp pointer
	Node *tmp = head;
	int i = 1;
	// No nodes
	if (tmp == NULL)
		return;

	// Last node of the list
	if (tmp->Next() == NULL) {
		delete tmp;
		head = NULL;
	}
	else {
		// Parse thru the nodes
		Node *prev;
		do {
			//if ( tmp->Data() == data ) break;
			if (i == delNum) {

				cout << "Currently running song deleted..";
				break;
			}
			prev = tmp;
			tmp = tmp->Next();
			i++;
		} while (tmp != NULL);

		// Adjust the pointers
		prev->SetNext(tmp->Next());
		delete tmp;
	}
}



int main()
{
	// New list
	List list;
	int length = 0;

	ifstream myReadFile;
	myReadFile.open("text.txt");
	string temp;
	while (getline(myReadFile, temp)) {
		length++;
		list.Insert(temp);
	}

	list.Print();
	cout << endl << endl;
	char ans;
	int skipnum = 0;

	//cout<<"P : Play \t  S: Skip \t   D: Delete  \t   N: Next  \t E: Exit "<<endl<<endl;
	do {

		cout << "P : Play \t  S: Skip \t   D: Delete  \t   N: Next  \t E: Exit " << endl;
		cin >> ans;

		if (ans == 'P' || ans == 'p') {
			if (songNum>length)
				songNum = 1;
			list.Play();
		}


		if (ans == 'N' || ans == 'n') {
			songNum++;
			if (songNum>length) {
				songNum = 1;
			}
			list.Play();

		}

		if (ans == 'S' || ans == 's') {
			cout << "Enter the  Number :";
			cin >> skipnum;

			if (skipnum <= length) {

				list.Skip(skipnum);
				songNum = skipnum;
			}
			else {
				cout << "Number is not list.";
			}

		}
		if (ans == 'D' || ans == 'd') {
			list.DeleteTheSong(songNum);
		}

		if (ans == 'a' || ans == 'a') {

			list.Print();
		}






	} while ((ans != 'E') && (ans != 'e'));



}

