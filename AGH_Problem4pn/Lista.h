#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node{
	T *item;
	Node<T>* next;
};

template <class T>
class Lista
{
public:
	Lista();
	~Lista();
	void push_back(T* push);
	Node<T>& last();
	class Iterator;
	friend class Iterator;
	//ITERATOR
	class Iterator{
	private:
		Node<T> *position;
	public:
		bool operator!=(Iterator b) const{ return position != b.position; }
		T& operator*(){ return *position->item; }
		void operator++(int){ position = position->next; }
		friend class Lista;
	};
	Iterator begin()
	{
		Iterator iter;
		iter.position = head;
		return iter;
	}

	Iterator end()
	{
		Iterator iter;
		iter.position = NULL;
		return iter;
	}

private:
	Node<T> *head;
	int number;
};

template <class T>
Lista<T>::Lista()
{
	head = NULL;
	number = 0;
}
template <class T>
Lista<T>::~Lista()
{
	//Nie chce mi sie
}

template <class T>
void Lista<T>::push_back(T* push)
{
	Node<T> *tmp;
	Node<T> *tmp2;
	if (head == NULL){
		head = new Node<T>;
		head->item = push;
		head->next = NULL;
		return;
	}
	else{
		tmp = head;
		tmp2 = tmp->next;
		while (tmp2 != NULL){
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		tmp2 = new Node<T>();
		tmp->next = tmp2;
		tmp2->next = NULL;
		tmp2->item = push;
	}
	number++;
}

template<class T>
Node<T>& Lista<T>::last(){
	Node<T>* tmp = head;
	for (int i = 0; i < number; i++)
	{
		tmp = tmp->next;
	}
	return *tmp->item;
}


#endif