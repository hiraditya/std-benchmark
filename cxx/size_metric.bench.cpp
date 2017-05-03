#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>

#define GETNAME(T) #T

template<typename T>
void print_sizeof(const T& t, const char* N) {
  std::cout << "\nSizeof, " << N << ", " << sizeof(t);
}

int main() {
  print_sizeof(std::deque<int>(), GETNAME(std::deque<int>()));
  print_sizeof(std::list<int>(), GETNAME(std::list<int>()));
  print_sizeof(std::vector<int>(), GETNAME(std::vector<int>()));
  print_sizeof(std::set<int>(), GETNAME(std::set<int>()));
  print_sizeof(std::unordered_set<int>(), GETNAME(std::unordered_set<int>()));
  print_sizeof(std::map<int, int>(), GETNAME((std::map<int, int>())));
  print_sizeof(std::unordered_map<int, int>(), GETNAME((std::unordered_map<int, int>())));
  return 0;
}
