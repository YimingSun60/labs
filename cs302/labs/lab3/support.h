#ifndef __SUPPORT_H__
#define __SUPPORT_H__
#include <fstream>
#include <ostream>
#include <iostream>
#include <istream>
#include <cstdlib>
using namespace std;
typedef unsigned char uchar;
extern const char ETX;

template <typename T>
class matrix {
	public:
		matrix(){
			buf=NULL;			
		}
		~matrix() {
			delete[] buf;
		}

		int get_Nrows() const {return Nrows;}
		int get_Ncols() const {return Ncols;}
		void assign(int n_Nrows, int n_Ncols){
			Nrows = n_Nrows;
			Ncols = n_Ncols;
			buf=new T [Nrows*Ncols];
		}
		T *data(){
			return buf;
		}
		T * operator[] (int i) {return &buf[i*Ncols];}
		//overload operator() {}
	private:
		int Nrows, Ncols;
		T *buf;
		//DATA storage
};

struct pixel {  
	int row, col;
	pixel(){
		row = 0;
		col = 0;
	}
	pixel(int nrow, int ncol){
		row=nrow;
		col=ncol;
	}
};

struct RGB {
	uchar R, G, B;
	RGB(){
		R=0;
		G=0;
		B=0;
	}
};

class ppm { 
	public:
		ppm(){
			Nrows = 0;
			Ncols = 0;
			Val_color = 255;
			Ntype="P6";
		}
		~ppm(){};
		void read(string fname);
		void write(string newfname);
		RGB *operator[](int i){return M[i];}
		int get_Ncols(){
			return Ncols;
		}
		int get_Nrows(){
			return Nrows;
		}
	private:
		int Nrows;
		int Ncols;
		int Val_color;
		string Ntype;
		matrix<RGB>M;
};
class rnumgen{
	public:
		rnumgen(int seed=0){
			srand(seed);
		}
		void pdf(const vector<int>& );
		int rand()const;
	private:
		vector<float>F;
};

#endif
