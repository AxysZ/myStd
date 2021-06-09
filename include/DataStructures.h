/*Here will be some basic data sructures, like string, vector, hash tables, graphs, etc...*/

#pragma once
#include <iostream>
#include "Utilities.h"

namespace stLib
{
	template<typename Type>
	class templatedString
	{
	public:

		//-+-+-+-+-+-+-+-+__consturctors__-+-+-+-+-+-+-+-+//
		
		templatedString();
		templatedString(const Type* str);
		templatedString(Type* str);
		templatedString(const templatedString& obj);
		templatedString(templatedString&& obj);
		
		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//
		


		//-+-+-+-+-+-+-+-+___destructor___-+-+-+-+-+-+-+-+//
		
		~templatedString();
		
		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//



		//-+-+-+-+-+-+__overloaded_operators__-+-+-+-+-+-+//

		templatedString& operator=(const templatedString& obj);
		templatedString& operator=(templatedString&& obj);
		templatedString& operator=(const Type* cStr);
		templatedString& operator=(Type* cStr);
		templatedString& operator+=(const templatedString& obj);
		Type operator[](size_t index);
		
		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//



		//-+-+-+-+-+-+-+__member_functions__-+-+-+-+-+-+-+//
		
		const Type* getData();
		size_t getlength();
		size_t getMaxLength();
		Type* begin();
		Type* end();

		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//



	private:
		const size_t _maxLength = 500000000;
		size_t _length;
		Type* _Data;
	};

	/*string thigs:*/

	//-+-+-+-+-+-+-+-+__consturctors__-+-+-+-+-+-+-+-+//
	
	template<typename Type>
	templatedString<Type>::templatedString()
		:Data(nullptr),_length(0)
	{

	}

	template<typename Type>
	templatedString<Type>::templatedString(const Type* str)
		:Data(nullptr),_length(0)
	{
		length = c_Str_Len(str);
		if(length > this->_maxLenght) this->_data = nullptr //Add here some exeption's logic in future
		else copy_C_Str(this->_data, str);
		
	}

	template<typename Type>
	templatedString<Type>::templatedString(Type* str)
		:Data(nullptr),_length(0)
	{
		length = c_Str_Len(str);
		if (length > this->_maxLenght) this->_data = nullptr //Add here some exeption's logic in future
		else this->_data = str;
	}

	template<typename Type>
	templatedString<Type>::templatedString(const templatedString<Type>& obj)
		:Data(nullptr),_length(0)
	{
		length = obj.length;
		copy_C_Str(this->_data, obj.Data);
	}

	template<typename Type>
	templatedString<Type>::templatedString(templatedString<Type>&& obj)
		:Data(nullptr),_length(0)
	{
		length = obj.length;
		copy_C_Str(this->_data, obj.Data);
		obj.Data = nullptr;
		obj.length = 0;
	}

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//





	//-+-+-+-+-+-+-+-+___destructor___-+-+-+-+-+-+-+-+//

	template<typename Type>
	templatedString<Type>::~templatedString()
	{
		length = 0;
		delete[]this->_data;
	}

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//





	//-+-+-+-+-+-+__overloaded_operators__-+-+-+-+-+-+//

	template<typename Type>
	templatedString<Type>& templatedString<Type>::operator=(const Type* str)
	{
		this->length = c_Str_Len(cStr);
		if (length > this->_maxLenght) this->_data = nullptr; //Exeptions... I'll add
		else copy_C_Str(this->_data, cStr);
		return *this;
	}
	
	template<typename Type>
	templatedString<Type>& templatedString<Type>::operator=(Type* str)
	{
		this->length = c_Str_Len(cStr);
		if (length > this->_maxLenght) this->_data = nullptr; //Exeptions... I'll add
		else this->_data = cStr;
		return *this;
	}

	template<typename Type>
	templatedString<Type>& templatedString<Type>::operator=(const templatedString<Type>& obj)
	{
		this->length = obj.length;
		copy_C_Str(this->_data, obj.Data);
		return *this;
	}

	template<typename Type>
	templatedString<Type>& templatedString<Type>::operator=(templatedString<Type>&& obj)
	{
		this->length = obj.length;
		copy_C_Str(this->_data, obj.Data);
		obj.Data = nullptr;
		obj.length = 0;
		return *this;
	}

	template<typename Type>
	templatedString<Type>& templatedString<Type>::operator+=(const templatedString<Type>& obj)
	{
		*this = concatenate_C_Strs(this->_data, obj.Data);
		length = c_Str_Len(this->_data);
		return *this;
	}

	template<typename Type>
	Type templatedString<Type>::operator[](size_t index)
	{
		if (index >= 0 && index <_length) return _data[i];
		else return '\0'; //This place needs in exeption throwing. I'll add in future, I promice
	}
	
	template<typename Type>
	templatedString<Type> operator+(templatedString<Type>& left, templatedString<Type>& right)
	{
		return templatedString<Type>(concatenate_C_Strs<Type>(left.getC_str(), right.getC_str()));
	}

	template<typename Type>
	std::ostream& operator<<(std::ostream& os, const templatedString<Type>& str)
	{
		return os << str.getData();
	}

	template<typename Type>
	std::istream& operator>>(std::istream& is, templatedString<Type>& str)
	{
		Type tmpStr[str.maxlength()];
		is >> tmpStr;
		copy_C_Str(str, tmpStr);
		return is;
	}

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//




	//-+-+-+-+-+-+-+__member_functions__-+-+-+-+-+-+-+//

	template<typename Type>
	const Type* templatedString<Type>::getData() { return static_cast<const Type*> this->_data; }

	template<typename Type>
	size_t templatedString<Type>::getlength() { return this->length; }

	template<typename Type>
	size_t templatedString<Type>::getMaxLength() { return this->_maxLenght; }

	template<typename Type>
	Type* templatedString<Type>::begin() {return this->_data }

	template<typename Type>
	Type* templatedString<Type>::end() {return this->_data + this->length}

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//

	typedef templatedString<char> String;
	typedef templatedString<wchar_t> wString;
	typedef templatedString<char16_t> uStrgin;
	typedef templatedString<char32_t> UString;


	template<typename Type>
	class Vector
	{
	public:
		//-+-+-+-+-+-+-+-+__consturctors__-+-+-+-+-+-+-+-+//

		Vector();
		Vector(const Type* arr);
		Vector(Type* arr);
		Vector(const Vector& obj);
		Vector(Vector&& obj);

		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//




		////////////////////////////////////////////
		class Iterator;
		////////////////////////////////////////////




		//-+-+-+-+-+-+-+-+___destructor___-+-+-+-+-+-+-+-+//

		~Vector();

		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//



		//-+-+-+-+-+-+__overloaded_operators__-+-+-+-+-+-+//

		Vector& operator=(const Vector& obj);
		Vector& operator=(Vector&& obj);
		Vector& operator=(const Type* arr);
		Vector& operator=(Type* arr);
		Vector& operator+=(const Vector& obj);
		Type operator[](size_t index);

		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//




		//-+-+-+-+-+-+-+__member_functions__-+-+-+-+-+-+-+//

		const Type* getData();
		size_t getlength();
		size_t getCapacity();
		size_t resize();
		size_t getMaxLength();
		Iterator begin();
		Iterator end();

		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+//


	private:
		size_t _size;
		size_t _maxCapacity;
		Type* _data;
	};

	template<typename Type>
	class Vector<Type>::Iterator
	{
		Iterator()
			:pointer(nullptr)
		{

		}

		Iterator(const Type* pointer)
			:pointer(pointer)
		{

		}


		~Iterator()
			:pointer(nullptr)
		{

		}


		Iterator& operator++()
		{
			this->pointer++;
			return *this;
		}

		Iterator& operator--()
		{
			this->pointer--;
			return *this;
		}

		bool operator==(const Iterator& obj)
		{
			return this->pointer == obj.pointer;
		}

		bool operator!=(const Iterator& obj)
		{
			return this->pointer != obj.pointer;
		}

		Type& operator*()
		{
			return *this->pointer;
		}

	private:
		Type* pointer;
	};
}
