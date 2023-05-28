#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Player
{
	int id, skills;
  string name;
};

void showPlayerVectorContent(vector<Player> wektor) {
  for(const auto& player : wektor){
    cout << "Nazwa: " << player.name << " ID: " << player.id << " skills: " << player.skills << endl;
  }
}

int main(){
  vector<Player> league1;
  vector<Player> league2;

  league1.push_back({1, 100, "John"});
  league1.push_back({2, 60, "David"});
  league1.push_back({3, 70, "Paul"});
  league1.push_back({4, 80, "Daniel"});
  league1.push_back({5, 30, "Damian"});

  // showPlayerVectorContent(league1);

  if(league1.size() >= 2) {
    league1.erase(league1.begin() + 1);
  }

  league1.push_back({6, 60, "Daniel"});
  league1.push_back({7, 40, "Damian"});

  if(league1.size() >= 2) {
    league2.insert(league2.begin(), league1.end() - 2, league1.end());
  }

  showPlayerVectorContent(league2);

  return 0;
}