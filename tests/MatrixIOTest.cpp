#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

#include <Eigen/Dense>
//#include <fstream>
#include <iostream>
#include <vector>

//using namespace std;
using namespace Eigen;

struct MatrixIOFixture 
{
    MatrixIOFixture()
    {
        expected = MatrixXd(3,3);
        expected << 0.680375, 0.59688, -0.329554,
                    -0.211234, 0.823295, 0.536459,
                    0.566198, -0.604897, -0.444451;
    }

    MatrixXd expected; 
}


BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-8))

BOOST_AUTO_TEST_CASE(openDataM3)
{
    // read in data
    MatrixXd M; 
    M = matrixIO::openData("../data/m3.csv", 3);

    // compare to expected
    for (int i=0; i < 3; i++)
    {
        for (int j=0; j < 3; j++)
        {
            BOOST_TEST(M(i,j) == expected(i,j));
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
