#pragma once
template<class T>   //  typename T
class smartPtr
{
private:
	T* privatePtr;
public:
	smartPtr(T* inputPtr) : privatePtr(inputPtr){}
	~smartPtr() { delete  privatePtr; }
	//  *
	T& operator * () const { 
		return *(privatePtr); 
	}
	// ->
	T*  operator ->  ()const {
		return privatePtr;
	}
};