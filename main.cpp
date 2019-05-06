#include "RotateSquareMatriix.hpp"
#include "FindPivotElement.hpp"

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // rotate square matrix
    {
        constexpr int ksize = 5;
        array< array<int, ksize> , ksize > a{{
            {{1,  2,  3,  4,  5}},
            {{6,  7,  8,  9,  10}},
            {{11, 12, 13, 14, 15}},
            {{16, 17, 18, 19, 20}},
            {{21, 22, 23, 24, 25}}
        }};
        cout << "#### Original matrix ##################################################################" << endl;
        for( const auto& r : a) {
            for( const auto& c : r ) {
                cout << c << ",";
            }
            cout << endl;
        }

        rotateSquareMatrix<ksize>(a);

        cout << "#### Rotated matrix ##################################################################" << endl;
        for( const auto& r : a) {
            for( const auto& c : r ) {
                cout << c << ",";
            }
            cout << endl;
        }
    }
    
    // rotated sequence
    {
        vector<int> arr{3,4,5,6,1,2};
        cout << findPivotSequentialSearch(arr) << endl;
        cout << findPivotBinarySearch(arr) << endl;
    }
    // non-rotated sequence
    {
        vector<int> arr{1,2,3,4,5,6};
        cout << findPivotSequentialSearch(arr) << endl;
        cout << findPivotBinarySearch(arr) << endl;
    }
    
    return 0;
}
