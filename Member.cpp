#include "Member.h"
#include <map>

size_t Member::activeMembers=0;

//Constructor
Member::Member(){
  activeMembers+=1;
  id=activeMembers;
}

Member::~Member(){
  activeMembers-=1;
  std::cout << "Destructing" << '\n';

}

int Member::numFollowers(){
  return followersMap.size();
}
int Member::numFollowing(){
  return followingMap.size();
}

//functions
void Member::follow(Member& m){
  if(&m!=this){
    followingMap.insert(make_pair(m.id, &m));
    m.followersMap.insert(make_pair(id,this));
  }
}

void Member::unfollow(Member& m){
  if(&m!=this){
    followingMap.erase(m.id);
    m.followersMap.erase(id);
  }
}

int Member::count(){
  return activeMembers;
}
void Member::print(){
  cout << "my ID: " << id << endl;
  for(auto elem : followingMap)
  {
    std::cout <<"following map: " <<elem.first << " " << elem.second << endl;
  }
  for(auto elem : followersMap)
  {
    std::cout <<"followers map: " <<elem.first << " " << elem.second << endl;
  }
}
