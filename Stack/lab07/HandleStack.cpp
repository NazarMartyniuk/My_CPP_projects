#include "HandleStack.h"

HandleStack::HandleStack()
{}
HandleStack::HandleStack(int size)
{
	this->size = size;
	this->mass = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		mass[i] = 0;
	}
}
HandleStack::HandleStack(const HandleStack& ref_Point) //Конструктор копіювання
{
	for (size_t i = 0; i < size; i++)
	{
		mass[i] = ref_Point.mass[i];
	}
}
HandleStack::~HandleStack()
{
	if (size > 0)
	{
		delete []mass;
	}
}
