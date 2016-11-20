// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class Publication
{
protected:
	char title[50];
	char author[50];
	char ISBN[50];
	double price;
public:
	Publication()
	{
		price = 0;
	}
	virtual void display() = 0;
	virtual void get_info() = 0;
};

class Book : public Publication
{
	int numPages;
public:
	void display()
	{
		printf("title: %s\n author: %s\n ISBN: %s\n Price: %3.2f\n pages: %d\n",
			title, author, ISBN, price, numPages);
	}
	void get_info()
	{
		cout << "enter title: ";
		gets_s(title);
		cout << "enter author: ";
		gets_s(author);
		cout << "enter ISBN: ";
		gets_s(ISBN);
		cout << "enter Price: ";
		cin >> price;
		cout << "enter pages: ";
		cin >> numPages;
		cin.clear();
		cin.ignore();
	}
};

class Audio : public Publication
{
	int minutes;
public:
	void display()
	{
		printf("title: %s\n author: %s\n ISBN: %s\n Price: %3.2f\n minutes: %d\n",
			title, author, ISBN, price, minutes);
	}
	void get_info()
	{
		cout << "enter title: ";
		gets_s(title);
		cout << "enter author: ";
		gets_s(author);
		cout << "enter ISBN: ";
		gets_s(ISBN);
		cout << "enter Price: ";
		cin >> price;
		cout << "enter minutes: ";
		cin >> minutes;
		cin.clear();
		cin.ignore();
	}
};

int main()
{
	Publication **bptr;
	int numberPubs = 0;
	char answer[2];

	cout << "How many publications? ";
	cin >> numberPubs;
	cin.clear();
	cin.ignore();

	bptr = new Publication *[numberPubs];
	for (int i = 0; i < numberPubs; i++)
	{
		cout << "Book ? or Audio?  enter B for book A for Audio:  ";
		gets_s(answer);
		if (strcmp(answer, "B") == 0)
		{
			bptr[i] = new Book();
			bptr[i]->get_info();
		}
		else if (strcmp(answer, "A") == 0)
		{
			bptr[i] = new Audio();
			bptr[i]->get_info();
		}
		else
		{
			cout << "try again" << endl;
			--i;
		}
	}

	for (int i = 0; i < numberPubs; i++)
	{
		bptr[i]->display();
	}

	return 0;
}

