#include <boost/scope_exit.hpp>
#include <iostream>

void foo(int i) {
  BOOST_SCOPE_EXIT(&i) {
    std::cout << "[BOOST_SCOPE_EXIT] foo: scope_exit: i = " << i << '\n'
              << std::endl;
  }
  BOOST_SCOPE_EXIT_END

  std::cout << "foo: initially i = " << i << std::endl;
}

int main() {
  for (int i = 0; i < 5; ++i) {
    BOOST_SCOPE_EXIT(&i) {
      std::cout << "[BOOST_SCOPE_EXIT] main: finished for iteration with i = "
                << i << '\n'
                << std::endl;
    }
    BOOST_SCOPE_EXIT_END

    std::cout << "main: begin for iteration with i = " << i << '\n'
              << std::endl;
    if (i == 1) {
      std::cout << "main: i = " << i << ", so continue" << '\n' << std::endl;
      continue;
    }
    if (i < 3) {
      foo(i);
    } else {
      foo(i);
      break;
    }
  }

  return 0;
}
