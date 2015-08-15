#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;

extern BOOST_MONAD_NOINLINE monad<int> test1(int n)
{
  return monad<int>(n).next([](monad<int> m) { return m.get()*3; });
}
extern BOOST_MONAD_NOINLINE void test2()
{
}

int main(void)
{
  monad<int> m(test1(5));
  test2();
  return m.get()!=15;
}