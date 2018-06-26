#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() : elements_(nullptr), size_(0), capacity_(0)
{
}

vector_t::vector_t(vector_t const & other)
{
    	elements_ = new int[other.capacity_];
    	for (std::size_t i = 0; i < other.size_; i++)
    	{
        	elements_[i] = other.elements_[i];
    	}
    	capacity_ = other.capacity_;
	size_ = other.size_;
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this != &other)
	{
		if(elements_ != nullptr)
			delete[]elements_;
		elements_ = new int [other.capacity_];

		for (size_t i = 0; i < other.capacity_; i++)
		{
			elements_[i] = other.elements_[i];
		}
		capacity_ = other.capacity_;
		size_ = other.size_;
	}
		return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (size_ == other.size_)
	{
		for (size_t i = 0; i < other.size_; i++)
		{
			if (elements_[i] != other.elements_[i])
			{
				return false;
				break;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

vector_t::~vector_t()
{
	if(elements_ != nullptr)
	{
		delete[]elements_;
	}
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if (capacity_)
	{
		if ( size_ == capacity_)
		{	
			capacity_ *= 2;
			int *temp_elements = new int [capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				temp_elements[i] = elements_[i];
			}

			delete[]elements_;
			
			elements_ = temp_elements;
		}
	}
	else
	{
		capacity_ = 1;
		elements_ = new int [capacity_];
	}
	
	elements_[size_++] = value;
}

void vector_t::pop_back()
{
	if (size_)
	{
		size_--;
		if (size_ <= ( capacity_ / 4 ))
		{
			capacity_ = capacity_ / 2;
			int * temp_elements = new int [capacity_];
			for (size_t i = 0; i < size_; i++)
			{
				temp_elements[i] = elements_[i];
			}
			
			delete[]elements_;

			elements_ = temp_elements;
		}
	}else
	{
		std::cout << "Error!\n Vector is empty\n";
	}
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	return !(lhs == rhs);
}
