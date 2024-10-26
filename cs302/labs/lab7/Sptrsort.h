#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <class T>
class sptr {
	public:
		sptr(T *_ptr=NULL){ptr=_ptr;}
		bool operator< (const sptr &rhs) const {
			return *ptr<*rhs.ptr;
		}
		operator T*()const{return ptr;}
	private:
		T*ptr;
 // COPY FROM CLASS HANDOUT
};
//set smart pointer to the each index of list
template <typename T>
void sptrsort(std::vector<T *> &A) {
  int i=A.size();
  vector<sptr<T> >sp;
  sp.resize(i);
  for(int a=0;a<i;a++){
	sp[a]=A[a];		
  }	
  sort(sp.begin(),sp.end());
  for(int a=0;a<i;a++){
	A[a]=sp[a];
  }
  //USE std::sort on SPTR VERSION OF A
  //NOTE: A is vector of pointers (T *)
}

