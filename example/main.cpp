/*
 * main.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: arnebef
 */
#include <iostream>
#include <sdi/Register.h>


class Definition
{
public:
	virtual int a() = 0;
};

class RealImpl : public Definition
{
public:
	RealImpl() {

	}
	virtual int a() { return 1;}
};


class TestImpl : public Definition
{
	int _a;
public:
	TestImpl() {
		static int c = 0;
		c++;
		_a = c;
	}

	virtual int a() { return _a;}
};

class RealClass
{
public:
	sdi::Inject<Definition> di;
};

int main()
{
	sdi::Register::instance<Definition, TestImpl>();

	RealClass rc;
	RealClass rc2;

	std::cout << rc.di->a() << std::endl;
	std::cout << rc2.di->a() << std::endl;

	return 0;
}




