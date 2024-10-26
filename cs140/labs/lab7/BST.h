#ifndef BST_H
#define BST_H

#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <class TKey>
class bst {
	struct node {
		node(int id=0 );
		void print();
		TKey key;
		int ID;
		//ID parameter
		node *parent;
		//parent info
		node *link[2];
	};

	public:
	class iterator {
		public:
			iterator();
			bool operator==(iterator )const;
			bool operator != (iterator )const;
			TKey & operator *();
			iterator operator++();
			//default constructor (no argument)
			//overloaded operators (++, *, ==, !=)
		private:
			friend class bst<TKey>;
			iterator(node *pp);
			//constructor (with argument)

			node *p;
	};

	iterator begin();
	iterator end();

	public:
	bst() { 
		Troot=NULL;
		ID=1;

	}
	~bst() { clear(Troot); }

	bool empty() { return Troot==NULL; }

	void insert(TKey &);

	iterator lower_bound(const TKey &);
	iterator upper_bound(const TKey &);

	void print_bylevel();
	private:
	void clear(node *);
	node *insert(node *, TKey &);
	int ID;
	//ID parameter
	node *Troot;
};



template <class TKey>
TKey &bst<TKey>::iterator::operator *(){
	return p->key;

}
template <class TKey>
bool bst<TKey>::iterator::operator==(bst<TKey>::iterator pp)const {
	return pp.p==p;
}
template <class TKey>
bool bst<TKey>::iterator::operator!=(bst<TKey>::iterator pp)const{
	return pp.p!=p;
}
template <class TKey>
class bst<TKey>::iterator bst<TKey>::iterator::operator++(){

	if(p->link[1]!=NULL){
		p=p->link[1];
		while(p->link[0]!=NULL){
			p=p->link[0];
		}
		return *this;
	}
	if(p->link[1]==NULL){
		while(p->parent!=NULL){
			if(p==p->parent->link[0]){
				p=p->parent;
				return *this;
			}
			else{ 
				p=p->parent;	

			}
		}
	}
	p=NULL;
	return *this;
}
//move down, if have right child, to the right, move down left
//if there have no right child, move up
//move down, if no left child, move down right
template <class TKey>
bst<TKey>::node::node(int id){
	ID=id;
	parent=NULL;
	link[0]=NULL;
	link[1]=NULL;
}
//bst<TKey>::node constructor goes here
	template <class TKey>
void bst<TKey>::node::print()
{
	if(parent==NULL){
		cout <<setw(3)<<key << setw(3) << ID << " :"<<" "<<"ROOT";
	}
	else
		cout << setw(3)<<key<< setw(3) << ID << " :"<<" "<<"P= "<<parent->ID;
	//output node and parent ID information
	//change below to output subtree ID information

	if (link[0]) cout << " L=" << setw(3) << link[0]->ID;
	else         cout << "      ";
	if (link[1]) cout << " R=" << setw(3) << link[1]->ID;
	else         cout << "      ";

	cout << "\n";
}

template <class TKey>
class bst<TKey>::iterator bst<TKey>::begin(){
	node *T=Troot;  
	while(T->link[0]!=NULL){
		T=T->link[0];
	}
	return iterator(T);
}
//define the begin of tree
template <class TKey>
class bst<TKey>::iterator bst<TKey>::end(){
	node *T=Troot;
	while(T->link[1]!=NULL){
		T=T->link[1];
	}
	return iterator();
}
//define end of tree
template <class TKey>
bst<TKey>::iterator::iterator(){
	p=NULL;
}
template <class TKey>
bst<TKey>::iterator::iterator(node *pp){
	p=pp;
}
//bst<TKey>::iterator functions not defined above go here

	template <class TKey>
void bst<TKey>::clear(node *T)
{
	if (T) {
		clear(T->link[0]);
		clear(T->link[1]);
		delete T;
		T = NULL;
	}
}

	template <class TKey>
void bst<TKey>::insert(TKey &key)
{ 
	Troot = insert(Troot, key);
}

	template <class TKey>
class bst<TKey>::node *bst<TKey>::insert(node *T, TKey &key)
{
	if (T == NULL) {

		//update and set node ID 
		T = new node(ID++);
		T->key = key;
	} else if (T->key == key) {
		;
	} 
	else {
		//set parent link 
		int dir = T->key < key;
		T->link[dir] = insert(T->link[dir], key);
		T->link[dir]->parent=T;						
	}

	return T;
}
template <class TKey>
class bst<TKey>::iterator  bst<TKey>::lower_bound(const TKey & kkey){
	node *T=NULL;
	node *TT=Troot;
	while(TT!=NULL){
		if(kkey<TT->key){
			T=TT;
			TT=TT->link[0];
		}
		else if(kkey>TT->key){
			TT=TT->link[1];
		}
		else if(kkey==TT->key){
			return iterator(TT);
		}
	}

	return iterator(T);
}
//lower bound>=than key
//use two pointer, one is point to curent node
//another will move when first pointer move to left
//while current pointer move to NULL, return second pointer.

//bst<TKey>::lower_bound function goes here
template <class TKey>
class bst<TKey>::iterator  bst<TKey>::upper_bound(const TKey & kkey){
	node *T=NULL;
	node *TT=Troot;
	while(TT !=NULL){
		if(kkey<TT->key){
			T=TT;
			TT=TT->link[0];
		}
		else
			TT=TT->link[1];
		
	}
	return iterator(T);
}
//upper bound>key
//also use two pointers, as same as lower bound

//bst<TKey>::upper_bound function goes here

	template <class TKey>
void bst<TKey>::print_bylevel()
{
	if (Troot == NULL)
		return;

	queue<node *> Q;
	node *T;

	Q.push(Troot);
	while (!Q.empty()) {
		T = Q.front();
		Q.pop();

		T->print();
		if (T->link[0]) Q.push(T->link[0]);
		if (T->link[1]) Q.push(T->link[1]);
	}
}
#endif

