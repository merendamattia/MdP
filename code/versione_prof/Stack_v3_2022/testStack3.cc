#include "Stack.hh"
#include "T.hh"

#include <iostream>
#include <string>

int T::num_current_objects = 0;

void
prova() {
  Stack<T> s1;
  assert(s1.size() == 0);
  assert(s1.is_empty());

  std::cerr << "\n\n ### fine fase 1 ## \n\n";

  Stack<T> s2(s1);
  assert(s1.size() == 0 && s2.size() == 0);

  std::cerr << "\n\n ### fine fase 2 ## \n\n";

  s2.push("aaa");
  assert(s1.size() == 0 && s2.size() == 1);

  std::cerr << "\n\n ### fine fase 3 ## \n\n";

  T& t = s2.top();
  assert(t == "aaa");
  t = "bbb";
  assert(s2.top() == "bbb");

  std::cerr << "\n\n ### fine fase 4 ## \n\n";

  Stack<T> s3 = s2;
  assert(s2.size() == 1 && s3.size() == 1 && s3.top() == s2.top());

  Stack<T> s4(std::move(s3));

  std::cerr << "\n\n ### fine fase 5 ## \n\n";

  s3 = s2 = s1;
  assert(s1.is_empty() && s2.is_empty() && s3.is_empty());

  std::cerr << "\n\n ### fine fase 6 ## \n\n";

  s1.push("abra");
  s1.push("cadabra");
  s1.pop();
  assert(s1.size() == 1 && s1.top() == "abra");

  std::cerr << "\n\n ### fine fase 7 ## \n\n";

  {
    Stack<T> s4;
    s4.swap(s1);
  }

  std::cerr << "\n\n ### fine fase 8 ## \n\n";

  assert(s1.is_empty());
  const size_t big_size = 4000;
  T t1("t1");
  for (size_t i = 0; i < big_size; ++i)
    s1.push(t1);
  assert(s1.size() == big_size);
}

int main() {
  try {
    prova();
  } catch (...) {
    std::cerr << "Exception caught" << std::endl;
  }
}
