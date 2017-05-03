#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Adapted from http://info.prelert.com/blog/stdgetline-is-the-poor-relation

void populateVec_getline(std::vector<std::string> &vec)
{
    vec.clear();
    std::ifstream dataStrm("farequote.csv");
    std::string line;
    while (std::getline(dataStrm, line))
    {
        vec.push_back(std::move(line));
    }
}

void splitUp(const char *begin,
             const char *end,
             std::vector<std::string> &vec,
             bool &continueLast)
{
    while (begin != end)
    {
        const char *eol = std::find(begin, end, '\n');
        std::size_t len = eol - begin;
        if (continueLast)
        {
            vec.back().append(begin, len);
        }
        else
        {
            vec.push_back(std::string(begin, len));
        }
        if (eol == end)
        {
            continueLast = true;
            break;
        }
        continueLast = false;
        begin = eol + 1;
    }
}

void populateVec_split(std::vector<std::string> &vec)
{
    vec.clear();
    std::ifstream dataStrm("farequote.csv");
    static const std::streamsize bufSize(256);
    std::vector<char> workBuf(bufSize);
    bool continueLast(false);
    while (dataStrm.read(&workBuf[0], bufSize))
    {
        splitUp(&workBuf[0], &workBuf[dataStrm.gcount()], vec, continueLast);
    }
    if (!dataStrm.bad()) // gcount() can't be relied on if stream is bad
    {
        splitUp(&workBuf[0], &workBuf[dataStrm.gcount()], vec, continueLast);
    }
}

int main(int, char **)
{
  {
    std::vector<std::string> fileContent;
    for (std::size_t count = 0; count < 1000; ++count)
    {
      populateVec_getline(fileContent);
    }
    std::cout << fileContent.size() << std::endl;
  }
  {
    std::vector<std::string> fileContent;
    for (std::size_t count = 0; count < 1000; ++count)
    {
      populateVec_split(fileContent);
    }
    std::cout << fileContent.size() << std::endl;
  }
  return 0;
}
