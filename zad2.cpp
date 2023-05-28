#include<iostream>
#include<map>

using namespace std;

template<typename M>
void print(const M &zawodnicy){
  for (auto it:zawodnicy){
    cout << it.first << " " << it.second << endl;
  }
}

int main(){
  map<int, string> zawodnicy {
    {1, "Marek"},
    {2, "Tom"},
    {3, "Marcin"},
    {4, "Tadeusz"},
    {5, "Krzysiek"},
    {6, "Wojtek"},
    {7, "Roman"},
    {8, "Sławek"},
    {9, "Filip"},
    {10, "Irek"}
  };

  print(zawodnicy);

  cout << endl;

  auto zaw = zawodnicy.extract(2);
  
  zaw.key() = 20;
  zawodnicy.insert(move(zaw));

  print(zawodnicy);
}