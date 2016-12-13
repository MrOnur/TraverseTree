// TraverseTree.cpp : Defines the entry point for the console application.
//

// Traverse Homework

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

//#ifdef _DEBUG
//	#define new DEBUG_NEW
//#endif

using namespace std;


class Node
{
public:
	char data[100];
	Node* pLeft;
	Node* pRight;
    
	Node()
	{
		pLeft = NULL;
		pRight = NULL;
	}
};

void ReadDataFile(char* filename);
void SetNodeData(char* dest, char* source);
void TraverseTree(Node* pTail, Node* pHead);
void TraversePrintNode(Node* p);
void DeleteTraverse(Node* ptr);

int _tmain(int argc, _TCHAR* argv[])
{
	ReadDataFile("data.txt");
	getchar();
	
	return 0;
}

void ReadDataFile(char* filename)
{
	Node *pNew = NULL;
	Node *ptrHead = NULL;
	Node *ptrCatch = NULL;

	ifstream is(filename);

	if (is.is_open())
	{
		char line[100];
		char newline[100];
		char sub1[100];
		char sub2[100];

		is.getline(newline,sizeof(is));

		istringstream iss(newline);
		iss >> sub1;
		iss >> sub1;

		ptrCatch = new Node();
		ptrCatch->pLeft = NULL;
		ptrCatch->pRight = NULL;

		SetNodeData(ptrCatch->data,sub1);

		while (!is.eof())
		{
			pNew = new Node();

			is.getline(line, sizeof(is));

			istringstream iss(line);
			iss >> sub2;
			iss >> sub2;	
			
		    ptrHead = pNew;

			SetNodeData(ptrHead->data, sub2);
		
			TraverseTree( ptrCatch, ptrHead);
		}

	TraversePrintNode(ptrCatch);
	DeleteTraverse(ptrCatch);

	}
	getchar();
}

void SetNodeData(char* dest, char* source)
{
	int i = 0;
	memset(dest, 0, 100);

	do
	{		
		*(dest + i) = *(source + i);		
		i++;
		
		if (*(source + i) == '\0')
			break;

		if ( i == 1500 )
			break;
	} while (1);
}

void TraverseTree(Node* pTail, Node* pHead)
{

	if (strcmp(pTail->data,pHead->data) == 1)
	{
		if (pTail->pLeft == NULL)
		{
			pTail->pLeft = pHead;
			pHead->pLeft = NULL;
			pHead->pRight = NULL;
		}
		else
		{
			TraverseTree(pTail->pLeft, pHead);
		}
	}
	else
	{
		if (pTail->pRight != NULL)
		{
			TraverseTree(pTail->pRight, pHead);
		}
		else
		{
			pTail->pRight = pHead;
			pHead->pLeft = NULL;
			pHead->pRight = NULL;
		}
	}
}

void TraversePrintNode(Node* p)
{
	if (p != NULL)
	{
		TraversePrintNode(p->pLeft);
		cout << p->data << endl;
		TraversePrintNode(p->pRight);
	}
}

void DeleteTraverse(Node* ptr)
{
	if (ptr != NULL)
	{
		DeleteTraverse(ptr->pLeft);
		DeleteTraverse(ptr->pRight);
		delete ptr;
	}
}