//---------------------------------------------------------------------------
#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_
#include <iostream>
#include <fstream>
#include "creep.h"

template <class T>
class Node
{

private:
         Node<T>*  previous;
         T*        data;
         Node<T>*  next;

public:
         Node();
         ~Node();
         bool SetData(T& Element);
         bool SetData(T* Element);
         void SetPrevious(Node<T>* previousElement);
         void SetNext(Node<T>* nextElement);
         Node<T>* GetNext();
         Node<T>* GetPrevious();
         T* GetData();
         bool GetData(T& Item);
		 bool GetData(T* Item);
         //friend ofstream& operator <<(ofstream& out_data, Node<T>& Node);
};
enum Position{FORWARD, BACKWARD, BEGINNING, END};
enum Status{CONTINUE, STOP, SUCCESS, FAILURE };

template <class T>
class List{

private:
         Node<T>*   first;
         Node<T>*   cursor;
         Node<T>*   last;
         int        size;

         bool RemoveFirst();
         bool RemoveLast();
         bool RemoveCurrent();
public:
         List();
         ~List();
		 
		 bool Insert(T &item);
         bool Remove(T &item);
         bool SetCursor(Position pos = BEGINNING,int counter = 0);
         T* GetCursorData(Status& status);
		 //Status GetCursorData(T& item);
         Status Search(T& item);
         int GetSize();
         bool SaveList(char* filename);
         bool ReadList(char* arquivo);
};

#endif
