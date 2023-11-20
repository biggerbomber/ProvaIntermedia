#include "../include/MyVector.h"

MyVector::MyVector(){
	m_capacity=100;
	m_data= new double [m_capacity];
	m_size=0;
}

MyVector::MyVector(int dim){
	m_capacity=dim;
	m_data= new double [m_capacity];
	m_size=0;
}

MyVector::MyVector(const MyVector& v): m_size{v.m_size} , m_capacity{v.m_capacity}, m_data{new double[v.m_capacity]}{
	std::copy(v.m_data,v.m_data+v.m_size,m_data);
}

MyVector::MyVector(std::initializer_list<double> i){
	const double* p=i.begin();
	m_size=i.size();
	m_capacity=i.size();
	m_data = new double [m_capacity];

	std::copy(p,p+i.size(),m_data);
}

double MyVector::operator[](int a) const{
	return m_data[a];
}

double& MyVector::operator[](int a){
	return m_data[a];
}

MyVector::~MyVector(){
	delete[] m_data;
	m_size=0;
	m_data=nullptr;
}

double MyVector::at(int i) const{
	if(i>=0 && i<m_size){
		return m_data[i];
	}
	
	throw std::out_of_range("");
}

double& MyVector::at(int i){
	if(i>=0 && i<m_size){
		return m_data[i];
	}
	
	throw std::out_of_range("");
}

void MyVector::reserve(int new_capacity){
	if(new_capacity>m_capacity){
		double* d=new double[new_capacity];
		std::copy(m_data,m_data+m_size,d);
		delete [] m_data;
		m_data=d;
		m_capacity=new_capacity;
	}
}

void MyVector::push_back(double d){
	if(m_size==m_capacity){
		reserve(m_capacity*2);
	}
	m_data[m_size]=d;
	m_size++;
}

double MyVector::pop_back(){
	if(m_size<=0){
		std::cout<<"Vettore vuoto\n";
		throw std::out_of_range("");
	}
	m_size=m_size-1;
	return m_data[m_size];
}
std::ostream& operator<<(std::ostream& os, MyVector& v){
    for(int i=0;i<v.size();i++){
            os<<v[i]<<'\n';
    }
    return os;
}
