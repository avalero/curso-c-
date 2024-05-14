#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

  vector<string> names{"Alice", "Bob", "Charlie", "David"};

  ofstream file;
  // open file for writing (replaces existing file with the same name)
  file.open("file.txt", ios::out);

  if (file.is_open())
  {
    for (auto name : names)
    {
      file << name << " ";
    }
    file.close();
  }
  else
  {
    cout << "Error opening file" << endl;
  }

  ifstream inputFile;
  inputFile.open("file.txt", ios::in);
  if (inputFile.is_open())
  {
    while (!inputFile.eof())
    {
      string value;
      inputFile >> value;
      cout << value << " - ";
    }
  }
  else
  {
    cout << "Error opening file for reading\n";
  }
  cout << endl;
}