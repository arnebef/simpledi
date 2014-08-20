/*
 * SimpleDI.h
 *
 *  Created on: Aug 19, 2014
 *      Author: arnebef
 */

#ifndef SIMPLEDI_H_
#define SIMPLEDI_H_

#include <typeindex>
#include <functional>
#include <memory>
#include <unordered_map>
namespace sdi {

class Register
{
public:
	static void* get(const std::type_info &type);
	static void set(const std::type_info &type, std::function<void*()> func);

	template<class Interface, class Implementation>
	static void singleton()
	{
		set(typeid(Interface), []() {static Implementation impl; return (void*)&impl;});
	}

	template<class Interface, class Implementation>
	static void instance()
	{
		set(typeid(Interface), [](){return (void*)new Implementation;});
	}
};


template<class T>
class Inject
{
private:
	T* _m;

public:
	Inject() : _m((T*)Register::get(typeid(T)))	{}
	T& operator *() const {
		return *_m;
	}

	T* operator ->() const {
		return _m;
	}

};
}

#endif /* SIMPLEDI_H_ */
