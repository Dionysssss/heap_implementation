#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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

private:
  /// Add whatever helper functions and data members you need below
	
	/**
   * @brief Returns the index of the parent node
   * 
   */
	size_t parent(size_t i) const;

	/**
   * @brief Returns index of the left_child node
   * 
   */
	size_t left_child(size_t p) const;

	/**
   * @brief Returns if the node is the leaf node
   * 
   */
	bool IfLeafNode(size_t idx) const;

	/**
   * @brief Place an item down to the right place
   * 
   */
	void TrickleDown(size_t idx);

	/**
   * @brief Place an item up to the right place
   * 
   */
	void TrickleUp(size_t idx);

private:
	std::vector<T> data;
	PComparator c_;
	int m_;
	

};

// Add implementation of member functions here

/**
	* construction
	*/
template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
	m_(m),  c_(c),  data()
{

}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

/**
	* helper functions
	*/

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::parent(size_t i) const{
	return (i-1) / m_;
}


template<typename T, typename PComparator>
size_t Heap<T, PComparator>::left_child(size_t p) const{
	return p*m_+1;
}


template<typename T, typename PComparator>
bool Heap<T, PComparator>::IfLeafNode(size_t idx) const{
	return left_child(idx)>data.size();
}


template<typename T, typename PComparator>
void Heap<T, PComparator>::TrickleDown(size_t idx){
	if( IfLeafNode(idx) ) return;
	size_t GreatChildIdx = left_child(idx);
	size_t Left_child = left_child(idx);

	int i=1;
	while( Left_child+i < data.size() && 
					i < m_ )
					// find the greatest child
				{
					if( c_( data[Left_child+i], data[GreatChildIdx] ) )
					GreatChildIdx = Left_child+i;

					i++;
				}
	if(! c_(data[idx], data[GreatChildIdx]) )
	{
		std::swap( data[idx], data[GreatChildIdx] );
		TrickleDown(GreatChildIdx);
	}

}


template<typename T, typename PComparator>
void Heap<T, PComparator>::TrickleUp(size_t idx){

	while(idx != 0 &&
				c_( data[idx], data[parent(idx)] )  )
		{
			std::swap(data[idx], data[parent(idx)]);
			idx = parent(idx);
			
		}
}


/**
	* public functions
	*/
template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
	return data.size();
}


template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	return data.empty();
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
    throw std::underflow_error("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");

  }

	data[0] = data[data.size()-1];
	data.pop_back();
	TrickleDown(0);


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	data.push_back(item);
	TrickleUp(data.size()-1);
}



#endif

