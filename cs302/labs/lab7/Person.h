#ifndef __PERSON_H__ 
#define __PERSON_H__


#include<iostream>
using namespace std;

enum person_enum  { UNKNOWN, FACULTY, STUDENT };
enum faculty_enum { ASST_PROF, ASSOC_PROF, FULL_PROF };
enum student_enum { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };

class person{
	friend ostream &operator<<(ostream& out, person& p);
	public:
	bool operator<(const person& p2)const;
	string get_Name();
	void set_person_type(person_enum p){
		person_type = p;
	}
	void set_Name(string N);
	protected:
	person_enum person_type;
	string Name;
	virtual void print_details()=0;
	virtual void print_courses()=0;
};  //DEFINITION -- base class
class faculty:public person{	
	public:
		bool operator<(const faculty &f2)const;
		void add_course(vector<string>&V);
		void set_faculty_type(faculty_enum f){
			faculty_type=f;
		}
	protected:
		faculty_enum faculty_type;
		vector<string>fcourse;
		void print_details();
		void print_courses();
};//DEFINITION -- derived class

class student:public person{
	public:
		bool operator<(const student& s2)const;
		void add_course(vector<string>&V);
		void add_gpa(vector<float>&V);
		void set_student_type(student_enum s){
			student_type=s;
		}	
	protected:
		student_enum student_type;
		vector<string>course;
		vector<float>gpa;
		vector< pair<string,float> >courselist;
		void print_details();
		void print_courses();
};//DEFINITION -- derived class


#endif
