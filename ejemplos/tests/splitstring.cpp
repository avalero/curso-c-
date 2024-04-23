#include "splitstring.h"

vector<string> splitString(string const &s, char const &delimiter)
{
  vector<string> tokens;
  string token;
  for (char c : s)
  {
    if (c == delimiter)
    {
      tokens.push_back(token);
      token.clear();
    }
    else
    {
      token += c;
    }
  }
  tokens.push_back(token);
  return tokens;
}