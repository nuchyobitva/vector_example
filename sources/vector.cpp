#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
  elements_=nullptr;
  size_=0;
  capacity_=0;
}

vector_t::vector_t(vector_t const & other)
{
  elements_=new int[other.capacity()];
  for(int i=0;i<other.size();i++){
    elements_[i]=other.elements_[i];
  }
  size_=other.size();
  capacity_=other.capacity();
}

vector_t & vector_t::operator =(vector_t const & other)
{   if(this!=&other){
           if(elements_!=nullptr){
                  delete[] elements_; 
           }
           elements_=new int[other.capacity()];
           for(int i=0;i<other.size();i++){
               elements_[i]=other.elements_[i];
           } 
           size_=other.size();
           capacity_=other.capacity();
    }

   return *this;

}

bool vector_t::operator ==(vector_t const & other) const
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

vector_t::~vector_t()
{
  if(elements_!=nullptr){
        delete[] elements_; 
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
     size_+=1;
     if(size_>capacity_){
      if(capacity_==0){
        capacity_=1;
      }else{
          capacity_=2*capacity_;
      }
      
      int *elements=new int[capacity_];
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

void vector_t::pop_back()
{   
  if (size_==0){
    return;
  }
  size_-=1;
  
  if(size_<=(capacity_/4)){
      capacity_=capacity_/2;
      int *elements=new int[capacity_];
      for(int i=0;i<size_;i++){
        elements[i]=elements_[i];
      }
      
      if(elements_!=nullptr){
            delete[] elements_; 
        }
      elements_=elements;

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
  bool result=false;
  if(rhs.size()!=lhs.size()){
    return true;
  }
  for(int i=0;i<rhs.size();i++){
    if(lhs.elements_[i]!=rhs.elements_[i]){
      result=true;
      return result;
    }
  }

  return result;
  
}
