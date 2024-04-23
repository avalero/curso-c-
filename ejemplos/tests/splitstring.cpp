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

vector<string> splitStringInParenthesis(string const &s)
{
  vector<string> tokens;
  string token;
  int level = 0;
  for (char c : s)
  {
    if (c == '(')
    {
      if (level > 0)
        token += c;
      level++;
    }
    else if (c == ')')
    {
      level--;
      if (level > 0)
        token += c;
      else if (level == 0)
      {
        tokens.push_back(token);
        token.clear();
      }
    }
    else if (level > 0)
    {
      token += c;
    }
  }
  return tokens;
}