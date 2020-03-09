#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "DLlist.h"

TEST_CASE( "DLlist", "[DLlist]" ) {
    DLlist L;
    REQUIRE(L.getSize() == 0);

    L.append(6);
    L.append(9);
    // The list is supposed to contain (6,9)
    REQUIRE(L.getSize() == 2);
    REQUIRE(L.at(0) == 6);
    REQUIRE(L.at(1) == 9);

    DNode *t = L.search(9);
    L.insertAfter(t , 42);
    // The list is supposed to contain (6,9,42)
    REQUIRE(L.getSize() == 3);
    REQUIRE(L.at(0) == 6);
    REQUIRE(L.at(2) == 42);

    L.insertAfter(NULL, 88);
    // The list is supposed to contain (88,6,9,42)
    REQUIRE(L.getSize() == 4);
    REQUIRE(L.at(0) == 88);
    REQUIRE(L.at(2) == 9);

    L.prepend(90);
    // The list is supposed to contain (90,88,6,9,42)
    REQUIRE(L.getSize() == 5);
    REQUIRE(L.at(0) == 90);
    REQUIRE(L.at(1) == 88);
    REQUIRE(L.at(1) == 88);

    /**
    // List R is going to have (1,2,3,4,5)
    DLlist R;
    for (int i = 1; i <= 5; i++) R.append(i);

    R.reverse();
    for (int i = 0; i <= 4; i++)  {
        REQUIRE(R.at(i) == 5 - i);
    }
    **/

}