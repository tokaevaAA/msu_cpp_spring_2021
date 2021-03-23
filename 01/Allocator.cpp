#include<stdio.h>

#include<stdlib.h>

#include"Allocator.h"


Allocator::Allocator(): m_maxSize(0), m_filled(0), m_mas(nullptr) {}
void Allocator::makeAllocator(size_t a_maxSize) {
  if (m_maxSize == 0 && a_maxSize > 0) {
    m_maxSize = a_maxSize;
    m_mas = static_cast < char * > (malloc(m_maxSize * sizeof(char)));
    return;
  } else if (m_maxSize > 0 && a_maxSize == 0) {
    if (m_mas != nullptr) {
      free(m_mas);
    }
    m_maxSize = 0;
    m_mas = nullptr;
    return;
  } else if (a_maxSize > m_maxSize) {
    m_maxSize = a_maxSize;
    char * new_mas = static_cast < char * > (malloc(m_maxSize * sizeof(char)));
    for (size_t i = 0; i < m_filled; i = i + 1) {
      new_mas[i] = m_mas[i];
    }
    free(m_mas);
    m_mas = new_mas;
  } else if (a_maxSize <= m_maxSize) {
    return;
  }
}
char * Allocator::alloc(size_t a_size) {
  if (m_filled + a_size > m_maxSize) {
    printf("From alloc: Wanted alloc %lu, but No free place! Allocator does not change mas;\n", a_size);
    return nullptr;
  }
  m_filled += a_size;
  return m_mas + m_filled;
}
void Allocator::reset() {
  m_filled = 0;
}
Allocator::~Allocator() {
  if (m_mas != nullptr) {
    free(m_mas);
  }
}