#include<iostream>
#include<string>

class String {
public:
	String();
	String(const String& s);
	virtual ~String();
	const char* CStr();
protected:
	char* sVal;
	int length;
};

String::String() {
	sVal = NULL;
	length = 0;
}



String::~String() {
	delete[]sVal;
 }

const char* String::CStr() {
	return (const char*)sVal;
}