//
// test_kdt.cpp
// CSE 100 Project 1
//
// A KDT tester using Catch unit testing framework.
//
// ATTENTION: This is not an exchaustive test suite and
// passing all tests does not guarantee full score on the
// project. You may want to add your own test cases by
// following the examples given.
//
// Last modified by Heitor Schueroff on 01/10/2019
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <algorithm>
#include <vector>
#include <string>

#include "../src/KDT.hpp"

using namespace std;

/**
 * Tests building KDT from given points.
 *
 * Parameters:
 *     t - the KDT to build and test
 *     points - points to use to build t
 *     expected_height - the expected height of the KDT after inserting points
 */
void test_kdt(KDT &t, vector<Point> &points, unsigned int expected_height) {
    REQUIRE(t.build(points) == points.size());

    CHECK(t.size() == points.size());
    CHECK(t.height() == expected_height);

    INFO("Searching for points actually in the tree");

    for (Point p : points) {
        REQUIRE(*(t.findNearestNeighbor(p)) == p);
    }
}

TEST_CASE("Testing Point::squareDistance implementation") {
    CHECK(Point::squareDistance(Point(1.0, 2.0), Point(1.0, 3.0)) == 1.0);
    CHECK(Point::squareDistance(Point(-1.0, 4.0), Point(1.0, 4.0)) == 4.0);
}

TEST_CASE("Testing KDT implementation") {
    KDT tree;

    SECTION("adding one point") {
        vector<Point> points = {{0, 0}};
        test_kdt(tree, points, 1);
        REQUIRE(*(tree.findNearestNeighbor(Point(1, 1))) == Point(0, 0));
    }

    SECTION("adding many points") {
        vector<Point> points = {{1.0, 3.2}, {3.2, 1.0}, {5.7, 3.2}, 
                                {1.8, 1.9}, {4.4, 2.2}};
        vector<Point> neighbors = {{1.2, 3.0}, {3.4, 1.2}, {5.9, 3.4},
                                   {2.0, 1.8}, {4.6, 2.0}};
        test_kdt(tree, points, 3);
        INFO("Searching for nearest neighbors");
        for (size_t i = 0; i < points.size(); ++i) {
            REQUIRE(*(tree.findNearestNeighbor(neighbors[i])) == points[i]);
        }
    }
}

