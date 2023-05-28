#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

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

  cout << endl;
}

bool compareById(const Player& playerA, const Player& playerB) {
  return playerA.id < playerB.id;
}

bool compareBySkills(const Player& playerA, const Player& playerB) {
  return playerA.skills > playerB.skills;
}

int main(){
  vector<Player> league1;
  vector<Player> league2;

  league1.push_back({1, 100, "John"});
  league1.push_back({2, 60, "David"});
  league1.push_back({4, 70, "Paul"});
  league1.push_back({3, 80, "Daniel"});
  league1.push_back({5, 30, "Damian"});

  showPlayerVectorContent(league1);

  if(league1.size() >= 2) {
    league1.erase(league1.begin() + 1);
  }

  league1.push_back({6, 40, "Daniel"});
  league1.push_back({7, 60, "Damian"});

  if(league1.size() >= 2) {
    league2.insert(league2.begin(), league1.end() - 2, league1.end());
  }

  sort(league1.begin(),league1.end(), compareById);
  showPlayerVectorContent(league1);

  sort(league2.begin(),league2.end(), compareBySkills);
  showPlayerVectorContent(league2);

  league1.clear();
  league2.clear();

  showPlayerVectorContent(league1);
  showPlayerVectorContent(league2);

  return 0;
}