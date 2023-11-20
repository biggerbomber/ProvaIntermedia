#ifndef _MYVECTOR_H
#define _MYVECTOR_H

#include <iostream>

class MyVector{
public:
	MyVector();
	explicit MyVector(int);
	MyVector(const MyVector&);
	MyVector(std::initializer_list<double>);
	~MyVector();

	
	double operator[](int) const;
	double& operator[](int);
	
	double at(int) const;
	double& at(int);
	
	void reserve(int);

	void push_back(double);
	double pop_back();
	
	int size() {return m_size;}//inline
	double* get_pointer(){return m_data;}
  
	
private:
	double* m_data {nullptr};
	int m_size {0};
	int m_capacity {0};
	
};

std::ostream& operator<<(std::ostream&, MyVector&);

#endif
