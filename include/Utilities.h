#pragma once

namespace stLib
{
	template<typename Type>
	void swap(Type& first, Type& second)
	{
		Type tmp = first;
		first = second;
		second = tmp;
	}

	template<typename Type = char>
	size_t c_Str_Len(const Type* str)
	{
		size_t counter = 0;
		for (Type* tmp = (Type*)str; *tmp != '\0'; tmp++) counter++;

		return counter;
	}

	template<typename Type = char>
	int copy_C_Str(Type*& left, const Type* right)
	{
		if (right == nullptr) return -1;

		if (left != nullptr) delete[]left;
		size_t length = c_Str_Len(right);
		left = new Type[length+1];

		for (size_t i = 0; i < length; i++)
		{
			left[i] = right[i];
		}
		left[length] = '\0';
		return 0;
	}

	template<typename Type = char>
	const Type* concatenate_C_Strs(Type* left, const Type* right)
	{
		size_t leftLenght = c_Str_Len(left);
		size_t rightLenght = c_Str_Len(right);
		Type* newStr = new Type[leftLenght + rightLenght + 1];
		
		size_t i;
		for (i = 0; i < leftLenght; i++)
		{
			newStr[i] = left[i];
		}
		for (size_t j = 0; j < rightLenght; j++)
		{
			newStr[i + j] = right[j];
		}
		newStr[rightLenght + leftLenght] = '\0';

		return newStr;
	}
}
