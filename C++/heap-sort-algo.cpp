#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
template<typename RandomAccessIterator>
void heap_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  make_heap(begin, end);
  sort_heap(begin, end);
}
 
int main() {
  int a[] = {25, 0, 95, 13, -26, -51, 24, 144, 255};
  cout << "Original nos:\n";
  copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
  cout << "\n";

  heap_sort(begin(a), end(a));
  cout << "Sorted numbers:\n";
  copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
  cout << "\n";
}
