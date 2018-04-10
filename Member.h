#pragma once
#include <map>
#include <iostream>
using namespace std;

class Member{

private:

  map <int,Member*> followingMap;
  map <int,Member*> followersMap;
  size_t id;
  static size_t activeMembers;


public:
  //Constructor and distructor
  Member();
  ~Member();
  //setters
  void setFollowers(int x);
  void setFollowing(int x);
  //functions
  void follow(Member& m);
  void unfollow(Member& m);
  int numFollowers();
  int numFollowing();
  static int count();
  //print
  void print();
};
