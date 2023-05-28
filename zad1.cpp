#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Player
{
	int id, skills;
  string name;
};

int main(){
  vector<Player> league1;

  league1.push_back({1, 100})
  league1.push_back({2, 60})
  league1.push_back({3, 70})
  league1.push_back({4, 80})
  league1.push_back({5, 30})

  return 0;
}