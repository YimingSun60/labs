#ifndef __SUPPORT_H__
#define __SUPPORT_H__
#include <vector>
typedef enum {white, black} color;
using namespace std;
class maze{
	public:
		void create_maze(int Nrows, int Ncols);
		void write_maze();
		void read_maze();
		bool solve_maze();	
		bool solve_maze(int, int);
		bool deadend(vector<color>& ,int);
		void write_path();
	private:
		int Nrow,Ncol;
		bool wall;
		vector< vector<int> >cel;
		vector<color> vcolor;
		vector<int>path;
};

#endif
