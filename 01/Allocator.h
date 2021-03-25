#include <stdio.h>
#include <stdlib.h>

class Allocator
{
private:
  size_t m_maxSize;
  size_t m_filled;
  char* m_mas;
public:
  Allocator();
  void makeAllocator(size_t a_maxSize);
  char* alloc(size_t a_size);
  void reset();
  ~Allocator();
};
