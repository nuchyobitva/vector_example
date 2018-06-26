#include <iostream>
template <typename type>
class vector_t
{
private:
    type * elements_;
    std::size_t size_;
    std::size_t capacity_;
    void at(std::size_t index) const;
public:
    
    vector_t();
    vector_t(vector_t const & other);
    vector_t & operator =(vector_t const & other);
    ~vector_t();
    
    std::size_t size() const;
    std::size_t capacity() const;
    
    void push_back(type value);
    void pop_back();
    
    type & operator [](std::size_t index);
    type operator [](std::size_t index) const;
    
    bool operator ==(vector_t const & other) const;
};
template<typename type>
bool operator !=(vector_t<type> const & lhs, vector_t<type> const & rhs);
#include <algorithm>
#include <cassert>
template <typename type>
void vector_t<type>::at(std::size_t index) const
{
    if(index>=capacity_){
        throw "index out of range";
    }
}
template <typename type>
vector_t<type>::vector_t()
{
    elements_=nullptr;
    size_=0;
    capacity_=0;
}
template <typename type>
vector_t<type>::vector_t(vector_t const & other)
{
    elements_=new type[other.capacity()];
    for(int i=0;i<other.size();i++){
        elements_[i]=other.elements_[i];
    }
    size_=other.size();
    capacity_=other.capacity();
}
template <typename type>
vector_t<type> & vector_t<type>::operator =(vector_t const & other)
{   if(this!=&other){
    if(elements_!=nullptr){
        delete[] elements_;
    }
    elements_=new type[other.capacity()];
    for(int i=0;i<other.size();i++){
        elements_[i]=other.elements_[i];
    }
    size_=other.size();
    capacity_=other.capacity();
}
    return *this;
}
template <typename type>
bool vector_t<type>::operator ==(vector_t const & other) const
{
    bool result=true;
    if(size_!=other.size()){
        return false;
    }
    for(int i=0;i<other.size();i++){
        if(elements_[i]!=other.elements_[i]){
            result=false;
            return result;
        }
    }
    return result;
}
template <typename type>
vector_t<type>::~vector_t()
{
    if(elements_!=nullptr){
        delete[] elements_;
    }
}
template <typename type>
std::size_t vector_t<type>::size() const
{
    return size_;
}
template <typename type>
std::size_t vector_t<type>::capacity() const
{
    return capacity_;
}
template <typename type>
void vector_t<type>::push_back(type value)
{
    size_+=1;
    if(size_>capacity_){
        if(capacity_==0){
            capacity_=1;
        }else{
            capacity_=2*capacity_;
        }
        type *elements=new type[capacity_];
        for(int i=0;i<size_-1;i++){
            elements[i]=elements_[i];
        }
        elements[size_-1]=value;
        if(elements_!=nullptr){
            delete[] elements_;
        }
        elements_=elements;
    }
    else{
        elements_[size_-1]=value;
    }
}
template <typename type>
void vector_t<type>::pop_back()
{
    if (size_==0){
        return;
    }
    size_-=1;
    if(size_<=(capacity_/4)){
        capacity_=capacity_/2;
        type *elements=new type[capacity_];
        for(int i=0;i<size_;i++){
            elements[i]=elements_[i];
        }
        
        if(elements_!=nullptr){
            delete[] elements_;
        }
        elements_=elements;
    }
}
template <typename type>
type & vector_t<type>::operator [](std::size_t index)
{
	return elements_[index];
}

template <typename type>
type vector_t<type>::operator [](std::size_t index) const
{
	return elements_[index];
}
template <typename type>
bool operator !=(vector_t<type> const & lhs, vector_t<type> const & rhs)
{
    bool result=false;
    if(rhs.size()!=lhs.size()){
        return true;
    }
    if(!(lhs==rhs)){
        result=true;
        return result;
    }
    return result;
}
