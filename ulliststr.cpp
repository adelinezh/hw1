#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{ 
  if (tail_ == nullptr) //if empty
  {
    head_ = new Item();
    tail_ = head_;
    tail_ -> first = 0;
    tail_ -> last = 1;
    tail_ -> val[0] = val;
    
  }
  else if(tail_ -> last == ARRSIZE) //if full
  {
    Item* tempItem = new Item();
    tail_ -> next = tempItem;
    tempItem -> prev = tail_;
    tail_ = tempItem;
    tail_ -> first = 0;
    tail_ -> last = 1;
    tail_ -> val[0] = val;

  } 
  else
  {
    tail_ -> val[tail_ -> last] = val;
    tail_ -> last ++;
  }
  
  size_ ++;
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back()
  {
    if (empty() == true)
    {
      throw std::runtime_error("Empty List"); //head_ == tail_ && tail_ -> last - tail_ -> first == 1
    } 
    tail_ -> last--;
    
    if(tail_ -> first == tail_ -> last)
    {
      Item* tempItem = tail_;
      tail_ = tail_ -> prev;
      
      if (tail_ == nullptr)
      {
        head_ = nullptr;
      }
      else
      {
        tail_ -> next = nullptr; 
        
      }
      delete tempItem;
    }
    size_ --;
  }

  void ULListStr::push_front(const std::string& val)
  {
    if (head_ == nullptr) //if empty
    {
      head_ = new Item();
      tail_ = head_;
      head_ -> first = ARRSIZE - 1;
      head_ -> last = ARRSIZE;
      head_ -> val[head_ -> first] = val;
    }
    else if (head_ -> first == 0) //if full
    {
      Item* tempItem = new Item();
      tempItem -> next = head_;
      head_ -> prev = tempItem;
      head_ = tempItem;
      head_ -> first = ARRSIZE - 1;
      head_ -> last = ARRSIZE;
      head_ -> val[head_ -> first] = val;
      
    } 
    else
    {
      head_ -> first --;
      head_ -> val[head_ -> first] = val;
    }
    size_ ++; 
  }


  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front()
  {
    if (empty() == true)
    {
      throw std::runtime_error("Empty List"); //head_ == tail_ && tail_ -> last - tail_ -> first == 1 
    } 
    head_ -> first++;

    if(head_ -> first == head_ -> last)
    {
      Item* tempItem = head_;
      head_ = head_ -> next;
      
      if (head_ == nullptr)
      {
        tail_ = nullptr; 
      }
      else
      {
        head_ -> prev = nullptr;
      }
      delete tempItem;
    }
    
    size_--;
  }

  std::string const & ULListStr::back() const
  {
    if (empty())
    {
      throw std::runtime_error("Empty List");
    }
    return tail_ -> val[tail_ -> last - 1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const
  {
    if (empty())
    {
      throw std::runtime_error("Empty List");
    }
    return head_ -> val[head_ -> first];

  }
  
  std::string* ULListStr::getValAtLoc(size_t loc) const
  {
    if (loc >= size_)
    {
      return nullptr;
    }
    Item* temp = head_;
    size_t index = 0;

    while (temp != nullptr) //check within each item
    {
      size_t numElements =  (temp -> last) - (temp -> first);
      if (loc < index + numElements)
      {
        return &(temp -> val[temp -> first + (loc - index)]);
      }
        index += numElements;
        temp = temp -> next;  
    }
    return nullptr;
  }

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
