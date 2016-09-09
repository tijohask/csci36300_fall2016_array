// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

/**
 * Returns the current size of the array.
 * In this case the current size is the size of the array 
 * from the beginning to the last assigned character
 */
inline
size_t Array::size (void) const
{
  return cur_size_;
}

/**
 * Returns the maximum size of the array.
 * In this case the maximum size is the actual size of the 
 * array, from the beginning to the last available character slot
 */
inline
size_t Array::max_size (void) const
{
  return max_size_;
}
