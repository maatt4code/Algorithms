#pragma once

#include <array>

/*
 * Given a square metric, this function rotates it anto-clockwise by 90 degrees
 */
template<int N>
inline void rotateSquareMatrix(std::array< array<int, N>, N>& mtrx)
{
    // We rotate the matrix layer by layer, from outside towards the center,
    // So you actually only have to do n/2 layers. Layers eg:
    // 0 0 0 0 0 0 * 0
    // * 1 1 1 1 1 1 0
    // 0 1 2 2 2 2 1 0
    // 0 1 2 3 3 2 1 0
    // 0 1 2 3 3 2 1 0
    // 0 1 2 2 2 2 1 0
    // 0 1 1 1 1 1 1 *
    // 0 * 0 0 0 0 0 0
    int n = mtrx.size();
    for( int layer = 0; layer < n/2 ; ++layer )
    {
        // calculate the first and last indices to work on
        // eg
        // - Layer 0: 0 ... (n-1)
        // - Layer 1: 1 ... (n-1)-1
        int first = layer;  // 0, 1, ..., n/2
        int last = n - 1 - layer; // (n-1), (n-2), ... , n/2
        for( int i = first; i<last ; ++i )
        {
            // for each idx, rotate the following 4 elements
            // ie (layer, idx), (idx, last), (last, last - idx + first),  (last - idx + first, first)
            // * see astrix above
            int tmp = mtrx[layer][i];
            mtrx[layer][i] = mtrx[i][last];
            mtrx[i][last] = mtrx[last][last-i+first];
            mtrx[last][last-i+first] = mtrx[last-i+first][first];
            mtrx[last-i+first][first] = tmp;
            //std::cout << "--- Layer " << layer << ", --- First " << first << ", Last " << last << "-------------------------------" << std::endl;
            //for( const auto& r : mtrx) {
            //    for( const auto& c : r ) {
            //        std::cout << c << ",";
            //    }
            //    std::cout << endl;
            //}
        }
    }
};
