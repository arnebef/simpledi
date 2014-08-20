/*
 * Register.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: arnebef
 */

#include <sdi/Register.h>

namespace sdi
{


typedef std::unordered_map<std::type_index, std::function<void*()> > type_map;


class Singleton
{
public:
	static Singleton& s()
	{
		static Singleton s;
		return s;
	}

	type_map map;

};


class RegisterException
{

};

void* Register::get(const std::type_info &type)
{
	std::type_index i = type;
	type_map &map = Singleton::s().map;
	auto result = map.find(type);
	if(result == map.end())
	{
		throw new RegisterException;
	}
	return result->second();
}

void Register::set(const std::type_info &type, std::function<void*()> func)
{
	Singleton::s().map[std::type_index(type)] = func;
}

}




