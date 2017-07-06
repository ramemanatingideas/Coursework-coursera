#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdexcept>
using namespace std;

template <class Item>
class Deque
{
private:
	std::vector<Item> queue_vector;

	public:
		Deque();
		bool isEmpty();
		int queue_size();
		void addFirst(Item elem);
		void addLast(Item elem);
		Item removeFirst();
		Item removeLast();
		
		void Iterable();

};

template <class Item>
Deque<Item>::Deque()
{
	std::vector<Item> queue_vector;

}

template <class Item>
int Deque<Item>::queue_size()
{
	unsigned int queue_length = queue_vector.size(); 

	return queue_length;
}

template <class Item>
bool Deque<Item>::isEmpty()
{
	int queue_length;
	queue_length =queue_size();

//throw out_of_range("Stack<>::pop(): empty stack"); 


   	if(queue_length==0)
   		return true;
   	else 
   		return false;

}

template <class Item>
void Deque<Item>::addLast(Item item)
{
	
	//int pos = queue_vector.front();
	queue_vector.push_back(item);


}

template <class Item>
void Deque<Item>::addFirst(Item item)
{
//int pos = queue_vector.front();

queue_vector.insert(queue_vector.begin(),item);

}

template <class Item>
Item Deque<Item>::removeLast()
{
	int element;


	if(!isEmpty())
	{		
		element = queue_vector.back();
		queue_vector.pop_back();
	}
	else
		throw out_of_range("Stack<>::pop(): empty stack"); 

return element;
}

template <class Item>
Item Deque<Item>::removeFirst()
{
	int element;

	if(!isEmpty())
	{
		element = queue_vector.front();
		queue_vector.erase(queue_vector.begin());
	}
	else
	throw out_of_range("Stack<>::pop(): empty stack"); 

	return element;
}

template<class Item>
void Deque<Item>::Iterable()
{

	for(vector<int>::iterator it = queue_vector.begin() ; it!=queue_vector.end(); it++)
		cout << *it << " ";
}



int main(int argc, char const *argv[])
{

	try{
		Deque<int>     Intobj;
		Deque<char>    charobj;

	int choice,enter,value;
	
    	

   do
    {
    	cin>>choice;
    	cin>>enter;

    	if(enter==1)
    	{	
    		cin>>value;
    		Intobj.addFirst(value);
    	}

    	else if(enter==2)
    	{	
    		cin>>value;
    		Intobj.addLast(value);
    	}

    	else if(enter==3)
    	{	
    		//cin>>value;
    		Intobj.removeFirst();
    	}
    	else if(enter==4)
    	{	
    		//cin>>value;
    		Intobj.removeLast();
    	}

	}while(choice!=0);



		Intobj.Iterable();

	}catch(exception const& ex) { 
      cerr << "Exception: " << ex.what() <<endl;
  }
	return 0;
}
