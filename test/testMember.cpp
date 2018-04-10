#include "Member.h"
#include "doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

TEST_CASE("create ,delete, and count() test") {
	 Member avi;
   CHECK(Member::count() == 1);
   Member beni;
   CHECK(Member::count() == 2);
   {
       Member chana;
       CHECK(Member::count() == 3);
   }
   CHECK(Member::count() == 2);
}
TEST_CASE("Test follow() and unfollow()"){
   Member avi;
   Member beni;
   CHECK(avi.numFollowing() == 0);
   CHECK(avi.numFollowers() == 0);
   avi.follow(beni);
   CHECK(avi.numFollowing() == 1);
   CHECK(beni.numFollowers() == 1);
   {
       Member chana;
       avi.follow(chana);
       CHECK(avi.numFollowing() == 2);
       CHECK(chana.numFollowers() == 1);
   }
   CHECK(avi.numFollowing() == 1);

   avi.unfollow(beni);
   CHECK(avi.numFollowing() == 0);
   CHECK(beni.numFollowers() == 0);
}
