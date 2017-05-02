#include<string>
void foo();

// Test to find if the destructor of std::string is optimized away or not.
// Currently g++ does not optimize the first one and clang++ does not optimize
// the second one.
// You have to compile with -O3  str.cpp -S -o - -fno-exceptions
// Enable -stdlib=libc++ for clang++
// g++ version:
// commit 7f22a985951e8c33ee6ecb98219fec1f048f5ef1
// Author: gccadmin <gccadmin@138bc75d-0d04-0410-961f-82ee72b054a4>
// Date:   Fri Apr 21 00:16:27 2017 +0000
//
//     Daily bump.
//
// clang++ version (llvm-project) SHA:
// commit fdda8da9f92db73bf1058ee2bead192fb9f1321b
// Author: Eric Fiselier <eric@efcs.ca>
// Date:   Fri Apr 21 01:48:02 2017 +0000
//
// XFAIL Windows test failures under test/libcxx
//
// This patch XFAIL's a number of tests under test/libcxx when on Windows.
// These failures need more investigation or patches to either Clang or libc++
// but for now we don't want them to prevent the bot from going green.

int t1() {
  std::string s("a");
  foo();
  return 0;
}

int t2() {
  std::string s("a");
  s+='a';
  return 0;
}

// g++ -O3 -S -o a.s ../a.cpp -fdump-tree-all-all
// g++ does not inline the string::find function
int foo1(const std::string &s1, const std::string &s2, int i) {
  bool ret = false;
  for (int k = 0; k < i; ++k)
     ret |= s1.find(s2) == k;
  return ret;
}
