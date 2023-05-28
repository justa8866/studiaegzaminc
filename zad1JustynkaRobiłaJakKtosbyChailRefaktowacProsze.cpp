#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Player
{
	int id;
  int skills; 
  string name;
};

void showPlayerVectorContent(vector<Player> wektor) {
  for(const auto& player : wektor){
    cout << "Nazwa: " << player.name;
    cout << " ID: " << player.id;
    cout << " skills: " << player.skills << endl;
  }
}

bool compareId(const Player& playerA, const Player& playerB) {
  return playerA.id < playerB.id;
}

bool compareSkills(const Player& playerA, const Player& playerB) {
  return playerA.skills > playerB.skills;
}

int main(){
  vector<Player> league1;
  vector<Player> league2;

  league1.push_back({1, 90, "Tom"});
  league1.push_back({2, 20, "David"});
  league1.push_back({4, 40, "Eugeniusz"});
  league1.push_back({3, 50, "Rafał"});
  league1.push_back({5, 70, "Adrian"});

  showPlayerVectorContent(league1);

  if(league1.size() >= 2) {
    league1.erase(league1.begin() + 1);
  }

  league1.push_back({6, 40, "Antonio"});
  league1.push_back({7, 60, "Marcin"});

  if(league1.size() >= 2) {
    league2.insert(league2.begin(), league1.end() - 2, league1.end());
  }

  sort(league1.begin(),league1.end(), compareId);
  showPlayerVectorContent(league1);

  sort(league2.begin(),league2.end(), compareSkills);
  showPlayerVectorContent(league2);

  league1.clear();
  league2.clear();

  showPlayerVectorContent(league1);

  return 0;
}