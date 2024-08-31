#include <iostream> // @nouhad2007
using namespace std;
#include <fstream>

int main(int argc, char* argv[]) {
  cout << "Hello world." << endl;
  cout << argc << endl; // argunment counter
  cout << "The first element of the vector array is " << argv[0] << endl;
  for (int i = 0; i < argc; i++){
    cout << argv[i] << endl;
  }
  return 0;
}