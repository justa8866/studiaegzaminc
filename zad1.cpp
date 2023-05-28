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

  league1.push_back({1, 100, "John"});
  league1.push_back({2, 60, "David"});
  league1.push_back({3, 70, "Paul"});
  league1.push_back({4, 80, "Daniel"});
  league1.push_back({5, 30, "Damian"});

  for(const auto& player : league1){
    cout << "Nazwa: " << player.name << " ID: " << player.id << " skills: " << player.skills << endl;
  }

  return 0;
}