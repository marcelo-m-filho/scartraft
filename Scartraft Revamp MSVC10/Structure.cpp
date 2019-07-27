#pragma hdrstop
#include "Structure.h"
//#pragma package(smart_init)

template <class T> Node<T>::Node()     //default constructor
{
   data = NULL;
   previous = NULL;
   next = NULL;
}

template <class T> Node<T>::~Node()    //default destructor
{
   if (data != NULL)
   {
      delete data;
   }
}


template <class T> bool Node<T>::SetData(T& element)     //Gets a node and creates a pointer pointing to it
{  
	if(&element == NULL)
	{
		return false;
	}
	data = &element;
	return true;     
}

template <class T> bool Node<T>::SetData(T* element)      //Gets an element  and creates a pointer pointing to it
{
   data = new T;
   if (data == NULL)        //if "new" can't allocate the function returns "false"
   {
     return false
   }
   *data = *element;
   return true;        //successful allocation
}

template <class T> Node<T>* Node<T>::GetNext()     //returns the next element
{
   return next;
}

template <class T> Node<T>* Node<T>::GetPrevious()       //returns the previous element
{
   return previous;
}

template <class T> T* Node<T>::GetData()        //returns the current element's data
{
   return data;
}

template <class T> void Node<T>::SetPrevious(Node<T>* previousElement)       //sets the previous element's data
{
   previous = previousElement;
}

template <class T> void Node<T>::SetNext(Node<T>* nextElement)        //sets the next element's data
{
   next = nextElement;
}

template <class T> bool Node<T>::GetData(T& item)         //gets the current element's data
{
   if (data ==NULL)          //if there's no data the funcion returns "false"
   {
      return false;
   }
   item = *data;  //Stores the data of the element in the Item's address
   return true;
}

/*
template <class T> ofstream& operator <<(ofstream& out_data, Node<T>& Node)
{
   T DadoGrava = Node.GetDado();
   out_data << DadoGrava;
   return out_data;
}   */



template <class T> List<T>::List()     //default constructor
{
   first = NULL;
   cursor = NULL;
   last = NULL;
   size = 0;
}

template <class T> List<T>::~List()       //default destructor
{
   SetCursor();    //Puts the cursor at the list's beginning
   while (cursor != NULL)  //"Walks" through the list deleting nodes
   {
      Node<T>* nodeTemp;
      nodeTemp = cursor->GetNext();
      if (cursor != NULL)
      {
         delete cursor;
      }
      cursor = nodeTemp;
   }
}

template <class T> bool List<T>::SetCursor(Position pos,int counter)
{
   if (counter < 0)
   {
      return false;
   }
   switch (pos)
   {
      case  FORWARD: //Moves forward through the list's elements
         while (cursor != last) //While Cursor is not pointing to the last list's element
         {
            if (counter == 0)   //"Moves" the cursor through the list
            {
               break;
            }
            cursor = cursor->GetNext(); 
            counter = counter - 1;
         }
         break;


      case  BACKWARD: //Moves backward through the list's elements
         while (cursor != first) //While Cursor is not pointing to the first list's element
         {
            if (counter == 0)  //"Moves" the cursor through the list
               break;
            cursor = cursor->GetPrevious();
            counter = counter - 1;
         }
         break;


      case  BEGINNING:  //Starting at the beginning moves the cursor through the list's elements
         cursor = first;   //Cursor goes to the list's beginning
         if (counter != 0)
         {
            return SetCursor(FORWARD,counter);   //calls function SetCursor to move the cursor forward
         }
         break;


      case  END:  //Starting in the end moves the cursor through the list's elements
         cursor = last;    //Cursor goes to the list's end
         if (counter != 0)
         {
            return SetCursor(BACKWARD,counter);   //calls function SetCursor to move the cursor backward
         }
         break;
   };
   return true;
}

template <class T> Status List<T>::Search(T &Item)
{
   setCursor();   //Puts the cursor at the list's beginning
   Status state;
   T itemTemp;
   do
   {
      state = GetCursorData(itemTemp);     //returns STOP, CONTINUE or FAILURE
      if (itemTemp == item)       //if the item found is the same as the wanted
      {
         item = itemTemp;
         return SUCCESS;
      }
      SetCursor(FORWARD,1);      //moves the cursor one position ahead              //WARNING
   }
   while(state == CONTINUE);
   return FAILURE;

}

template <class T> bool List<T>::Insert(T &item)
{
   Node<T>* newNode = new Node<T> ;
   if (newNode == NULL)       //if "new" wasn't able to create the Node
   {
      return false;
   }
   if (!newNode->SetData(item))  //if can't allocate
   {
      delete newNode;
      return false;
   }
   if (first == NULL) //if the list is empty
   {
      first = newNode; // The NewNode receives both status of First and Last element
	  last = newNode;
      newNode->SetPrevious(NULL);
      newNode->SetNext(NULL);
	}
   else  //if the list is not empty
   {
      last -> SetNext(newNode); //insert the "NewNode" after the Last node
	  newNode -> SetPrevious(last); //NewNode point to the element before the last
	  last = newNode; //NewNode receive "Last" status
   }
   size = size + 1; //increases list's size
   return true;
}

template <class T> int List<T>::GetSize()
{
   return size;
}

template <class T> bool List<T>::Remove(T &item)
{
   if (size == 0) //if the list is empty
   {
      return false;
   }
   T fst,lst;     //"first" and "last"
   if ( !First->GetData(fst) || !Last->GetData(lst) )  //if the list don't have first or last element
   {
      return false;
   }
   if (*fst == item) //If the item to be deleted is the first
   {
      return RemoveFirst();
   }
   else if (*lst == item) //If the item to be deleted is the last
   {
     return RemoveLast();
   }
   else
   {
      int counter =1;
      SetCursor(); //Puts the cursor at the list's beginning
      while (counter<size)  //go through the list until it ends
      {
         SetCursor(FORWARD,1); //Makes the cursor advance one position on the list
         T temp;
         if ( !Cursor->GetData(temp) )  //If it is not possible to get the data that is pointed by the cursor
         {
            return false;
         }
         if(temp == item) //If the item to be deleted is the same that is pointed by the cursor
         {
            return RemoveCurrent();
         }
         counter = counter + 1; //Counter is increased
      }
   }

   return false;
}

template <class T> bool List<T>::RemoveFirst()                     
{
   if (first!=NULL) //If First is pointing somewhere
   {
      Node<T>* removeNode
      removeNode = first;   //The node to be removed is stored in "NoRemover"
      if (first != last)   //If the list has more than one element
      {
         first = first->GetNext();  //First becomes the list's current second element
         first->SetPrevious(NULL);
      }
      else  //If the list has only one element
      {
         first = NULL;
         last = NULL;
      }
      delete removeNode; //The node to be removed is removed
      removeNode = NULL; //NoRemover begins pointing nowhere
      size = size -1; //List size is decreased
      cursor = first;  //Cursor receives the new "First" element
      return true;
   }
   return false;
}

template <class T> bool List<T>::RemoveLast()
{
   if (last != NULL) //If Last is pointing somewhere
   {
      Node<T>* removeNode;
      removeNode = last;    //The node to be removed is stored in "NoRemover"
        if (first != last) //If the list has more than one element
        {
           last = last->GetPrevious(); //Last becomes the list's current element before the last
           last->SetNext(NULL);
        }
        else
         {
            first = NULL;
            last = NULL;
         }

        delete removeNode;  //The node to be removed is removed
        removeNode = NULL;  //NoRemover begins pointing nowhere
        size = size - 1;            //List size is decreased
        cursor = last;       //Cursor receives the new "First" element
        return true;
   }
   return false;
}

template <class T> bool List<T>::RemoveCurrent()
{
   if (cursor!=NULL) //If Cursor is pointing somewhere
   {
      Node<T>* tempNode;
      Node<T>* removeNode;
      removeNode = cursor;  //The node to be removed is the one pointed by Cursor
      cursor->GetPrevious()->SetNext(cursor->GetNext()); //Makes the element before the cursor point to the element after the cursor
      cursor->GetNext()->SetPrevious(cursor->GetPrevious()); //Makes the element after the cursor point to the element before the cursor
      cursor = cursor->GetPrevious(); //Makes the cursor point to one element before it was
      delete removeNode; //The node to be removed is removed
      removeNode = NULL; //The node removed begins pointing nowhere
      size = size -1; //The list size is decreased
      //Cursor=Cursor->GetPrevious(); WARNING
      return true;
   }
   return false;
}

template <class T> T* List<T>::GetCursorData(Status& status) 
{
   if (cursor == NULL)    //if the cursor points to nothing or the cursor's data is empty
   {
	  status = FAILURE;
      return NULL;
   }
   if (cursor == last)      //if the cursor ran through the whole list
   {
	  status = STOP;
	  return cursor->GetData();
   }

   status = CONTINUE;
   return  cursor->GetData();
}

//template <class T> Status List<T>::GetCursorData(T& item)
//{
//   if (cursor == NULL || !(cursor->GetData(item)))    //if the cursor points to nothing or the cursor's data is empty
//   {
//      return FAILURE;
//   }
//   if (cursor == last)      //if the cursor ran through the whole list
//   {
//      return STOP;
//   }
//   return  CONTINUE;
//
//}

template <class T> bool List<T>::SaveList(char* filename)
{
   ofstream output;  //Variable that sends data through the stream
   output.open(fileName); //Open stream to the filename
   SetCursor(); //Reset cursor to the beginning of list
   T record; //Variable that receives the list's element
   for (int aux=0; aux<Size; aux++) //do until there are elements in the list
   {
      if ( GetCursorData(record)!=FAILURE ) //Receives node data
      {
         output << record; //Send the data using the opened stream
      }
      SetCursor(FORWARD,1); //Cursor goes to the next list's element
   }
   output.close();  //Close stream
   return true;

}

template <class T> bool List<T>::ReadList(char* filename)
{
   ifstream input;   //Variable that gets data from the stream
   input.open(filename); //Open stream to the filename
   SetCursor();   //Reset cursor to the beginning of list
   T read;  //Variable that gets the file list's element
   while( !( input.eof() )  ) //do until there are elements in the file eof == "End Of File"
   {
      input >> read; //Get the data using the opened stream
      if ( input.eof() )  //Gets out of the loop if the file reaches the end eof == "End Of File"
      {
         break;
      }
      Insert(read);  //Insert the read elements in a list
   }
   return true;
}