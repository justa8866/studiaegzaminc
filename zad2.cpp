#include <iostream>
#include <map>
#include <time.h>
#include <random>

using namespace std;

template<typename M>
void print(const M &zawodnicy){
  for (auto it:zawodnicy){
    cout << it.first << " " << it.second << endl;
  }
}

int main(){
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist1_5(1,5);
  uniform_int_distribution<int> dist6_12(6,12);

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
    {10, "Irek"},
    {11, "Filip"},
    {12, "Irek"}
  };

  print(zawodnicy);
  cout << endl;

  int zmianaZespolPodstawowy = dist1_5(gen);
  int zmianaZespolRezerwowy = dist6_12(gen);
  cout << zmianaZespolPodstawowy << "<->" << zmianaZespolRezerwowy << endl;

  auto zawRez = zawodnicy.extract(zmianaZespolRezerwowy);
  auto zawPod = zawodnicy.extract(zmianaZespolPodstawowy);
  
  zawRez.key() = zmianaZespolPodstawowy;
  zawodnicy.insert(move(zawRez));

  zawPod.key() = zmianaZespolRezerwowy;
  zawodnicy.insert(move(zawPod));

  print(zawodnicy);
  cout << endl;

  zmianaZespolPodstawowy = dist1_5(gen);
  zmianaZespolRezerwowy = dist6_12(gen);
  cout << zmianaZespolPodstawowy << "<->" << zmianaZespolRezerwowy << endl;

  zawRez = zawodnicy.extract(zmianaZespolRezerwowy);
  zawPod = zawodnicy.extract(zmianaZespolPodstawowy);
  
  zawRez.key() = zmianaZespolPodstawowy;
  zawodnicy.insert(move(zawRez));

  zawPod.key() = zmianaZespolRezerwowy;
  zawodnicy.insert(move(zawPod));

  print(zawodnicy);
}
