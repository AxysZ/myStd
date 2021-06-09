#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include "../include/DataStructures.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

template<typename DataType>
void generateDataForTests(DataType*& pointer);

bool stringTest()
{
	using namespace stLib;
	
	String s1;
	String s2("String");
	String s3(s2);
	String s4(String("something"));
	String s5;

	s1 = s2;
	s5 = s3 + s4;
	s3 += s4;
	//etc...

	return false;
}

bool vectorTest()
{


	return false;
}


int main()
{
	stringTest();
	vectorTest();

	_CrtDumpMemoryLeaks();
	return 0;
}