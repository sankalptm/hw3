#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void trickleUp (int loc);
  void heapify (int idx);
  std::vector<T> inputs;
private:
  /// Add whatever helper functions and data members you need below

  //std::vector<T> inputs;
  int num_children; 
  PComparator heap_type;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  num_children=m;
  heap_type=c;
}
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  
}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty Vector");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else {
    return inputs[0];
  }


}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return inputs.size();
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  // trickle down 
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Vector is empty");

  }
  else{
    //remove the proper vector position
    std::swap(inputs[0], inputs[inputs.size()-1]);
    inputs.pop_back();
    heapify(0);

  }



}
template <typename T, typename PComparator>
bool Heap<T,PComparator>:: empty() const{
  if (inputs.empty()){
    return true;
  }
  else {
    return false;
  }
}
template <typename T, typename PComparator>
void Heap<T, PComparator>::push (const T& item){
  //push into the correct index
  // m = 3
  //parent: (i-1)/m
  //children: 
  //1st child = m*i +1
  // 2nd child = m*i + 2
  // 3rd child = m*i + 3
  //4th child =

  inputs.push_back(item);
  //check with parent not very first element
  trickleUp(inputs.size()-1);
  // if (heap_type(item, inputs[0])){
  //   std::swap(inputs[0], inputs[inputs.size()-1]);
  //   trickleUp(inputs.size()-1);
  // }
  
  
}
template <typename T, typename PComparator>
void Heap<T, PComparator>:: trickleUp(int loc){
  int parent=(loc-1)/num_children;
  while (parent >=0 && heap_type(inputs[loc],inputs[parent])){
    std::swap(inputs[parent], inputs[loc]);
    loc=parent;
    parent=(loc-1)/num_children;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>:: heapify(int idx){
  //size_t 
  if (idx>=static_cast<int>(inputs.size())){
    return;
  }
  int smallerChild= idx * num_children + 1;
  if(smallerChild >= static_cast<int>(inputs.size()))
    return;
  // childIdx = num_children * parent + 1
  for (int j=idx * num_children + 1; j <= idx * num_children + num_children;j++){
    if (j>=static_cast<int>(inputs.size())){
      break;
    }
    if (heap_type(inputs[j], inputs[smallerChild])){
      smallerChild=j;
    }
   
  }
  if (heap_type(inputs[smallerChild],inputs[idx])){
    std::swap(inputs[smallerChild],inputs[idx]);
    heapify(smallerChild);
  }
  //int smallerChild= (num_children*idx) +1;
  /*for (int i=0; i <num_children; i++){
    if (smallerChild+1<static_cast<int>(inputs.size())){
      int rChild=smallerChild+i;
      if (inputs[rChild]<inputs[smallerChild]){
        smallerChild=rChild;
      }
    }
   
    
  }
  //std::cout<<idx<<std::endl;
  //std::cout<<smallerChild<<std::endl;
  if (inputs[idx]>inputs[smallerChild]){
      std::swap(inputs[idx],inputs[smallerChild]);
      heapify (smallerChild);
    }*/
}



#endif

