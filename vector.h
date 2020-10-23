#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
template
	<typename T> // Assume Vector only takes in int or double for T
class Vector {
private:
	int sz; 	// the number of elements in this Vector
	T* buf; 	// the base of the array of Ts, you must allocate it

public:
	Vector(int n) : sz (n) , buf(new T[sz])
	// Vector v1(10); -- create a 10 element Vector
	{
		/*	for (int i = 0; i < sz; ++i)
				buf[i] = 0;	*/
	}
	//@Overload Constructor   any vector of type
	Vector(initializer_list<T> L) : sz(L.size()), buf(new T[sz]) 
	{
		 // Vector v1{T1, T2, T3};
		
    
		int count = 0;
        for(auto& i : L)
        {
            buf[count++] = i;
        }

	}
	~Vector() /* destructor called automatically when a Vector dies 
Destructor should free memory used. your program should have no leak/lost/still-reachable/errors(suppressed or not), besides 72704 bytes in one still-reachable block (a g++/valgrind bug on some versions). */
	{
		delete[] buf;
	}
	//Copy constructor 
	Vector(const Vector & v) // Vector v2(v1); deep-copy
	{
	 sz = v.sz;
        buf = new T[sz];
        for(int index = 0; index < sz; index++ )
        {
            buf[index] = v.buf[index];
        }
	}
	int size() const // v1.sz returns 10 for v1 example above
	{
		return sz;
	}
	//Bracket Operator
	T & operator [] (const int i)
	  //T x = V[i]; 
	{
		if(i < 0 || i > sz )
		{
			 throw std::out_of_range("index out of bound!");
		}
		return buf[i];
	}
//Access out-of-bound index should throw an error to be caught in outside scope 
	T operator * (const Vector & v) const
	{
		int vSize= v.size() < sz ? v.size() : sz;
		int total = 0;

		for (int i = 0; i < vSize; ++i)
		{
			total += buf[i] * v.buf[i]; 
		}
		return total;
	}
// T x = V1 * V2; dot product
// e.g. [1, 2] * [3, 4, 5] = 1 * 3 + 2 * 4 + 0 = 11
// Assume an empty Vector will cause the product to be 0.
	Vector operator + (const Vector & v) const 
// V3 = V1 + V2; [1, 2, 3] + [4, 5, 6, 7] = [5, 7, 9, 7]
	{
		int vSize= v.size() > sz ? v.size() : sz;
		int total = 0;

		for (int i = 0; i < vSize; ++i)
		{
			int leftSide = (i < sz) ? buf[i] : 0; 
			int rightSize = (i < v.size()) ? buf[i] : 0; 

			total += buf[i] + v.buf[i]; 
		}
		return total;
	}
	const Vector & operator = (const Vector & v) // V1 = V2;
	{
		// buf = V.buf;
		// if the addresses are not the same
	
        if (this != &v) { // protect against invalid self-assignment
            // 1: allocate new memory and copy the elements
            T* new_array = new T[v.sz];
            std::copy(v.buf, v.buf + v.size(), new_array);

            // 2: deallocate old memory
            delete[] buf;

            // 3: assign the new memory to the object
            buf = new_array;
            sz = v.size();
        }
        // by convention, always return *this
        return *this;
	}
	bool operator == (const Vector & v) const // if (V1 == V2)...
	{
		// identity
		//return (this == &v) ? true : false;
		// equivalence
		if (sz !=  v.sz)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < sz; ++i)
			{
				if(buf[i] != v.buf[i])	return false;
			}
		}
		return true;
	}
	bool operator != (const Vector & v) const // if (V1 != V2)...
	{
		
		if (sz != v.sz)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < sz; ++i)
			{
				if(buf[i] != v.buf[i])	return true;
			}
		}
		return false;
	}
	friend Vector operator * (const int n, const Vector & v)
	// V1 = 20 * V2; -- each element of V1 is element of V2 * 20
	{
	//v1 =  20  * v2;
		Vector<T> tmpV(v);
	for (int i = 0; i < tmpV.sz; ++i)
		tmpV.buf[i] *= n; 
	return tmpV;
	}


	friend Vector operator + (const int n, const Vector & v)
	// V1 = 20 + V2; -- each element of V1 is element of V2 + 20
	{
	
			Vector<T> tmpV(v);
	for (int i = 0; i < tmpV.sz; ++i)
		tmpV.buf[i] += n; 
	return tmpV;

	}


	friend ostream& operator << (ostream & o, const Vector & v)
	// cout << V2; -- prints the vector in this format 
// (v0, v1, v2, ... vn-1);
	{
		o << "(";
		int i = 0;
		for ( ;i < v.sz -1; ++i)
		{
			 o << v.buf[i] << ", ";
		}
		    o <<  v.buf[i] << ")";
	return o;
	}
};
#endif

/* OR #include "vector.h" in diffrent file
class Box {
   double width;
   
   public:
      friend void printWidth( Box box );
      void setWidth( double wid );
};

// Member function definition
void Box::setWidth( double wid ) {
   width = wid;
}

int main()
box b = box; 
	Vector<int> intVec{1,3,5,7,9};
	Vector<double> doubleVec{1.5,2.5,3.5,4.5};
	Vector<int> iv(intVec);
	Vector<double> dv(doubleVec);
*/ 