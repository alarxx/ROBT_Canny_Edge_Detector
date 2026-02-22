#pragma once
#ifndef _TENSORIMAGEPROCESSING_
#define _TENSORIMAGEPROCESSING_

#include <cmath>
#include <climits>

#include "TensorX/Tensor.hpp"


namespace tensor {

    template<Arithmetic T>
    Tensor<T> gaussian_blur(Tensor<T>& image, int times = 1){
        Tensor<float> _blur5x5 = {
            {2,  4,  5,  4, 2},
            {4,  9, 12,  9, 4},
            {5, 12, 15, 12, 5},
            {4,  9, 12,  9, 4},
            {2,  4,  5,  4, 2}
        };
        Tensor blur5x5 = div(159.0f, _blur5x5);

        Tensor<T> result = image;

        for (int i = 0; i < times; ++i){
            std::cout << "gaussian_blur" << std::endl;
            result = conv(result, blur5x5);
        }

        return result;
    }

    template<Arithmetic T>
    T max(int length, T * values){
        T maxv = (T) INT_MIN;
        for(int i = 0; i < length; ++i){
            if(maxv < values[i]){
                maxv = values[i];
            }
        }
        return maxv;
    }

    template<Arithmetic T>
    Tensor<T> sobel_operator(Tensor<T>& image){
        Tensor<float> sobel_x = {
            {-1,  0,  1},
            {-2,  0,  2},
            {-1,  0,  1}
        };
        Tensor gx = conv(image, sobel_x);

        Tensor<float> sobel_y = {
            {-1, -2, -1},
            { 0,  0,  0},
            { 1,  2,  1}
        };
        Tensor gy = conv(image, sobel_y);

        // magnitude
        int H = gx.getDims()[0];
        int W = gx.getDims()[1];

        Tensor<float> mag(H, W);

        for (int r = 0; r < H; ++r){
            for (int c = 0; c < W; ++c){
                float gxv = gx.get(r, c); // [-4*255; 4*255]
                float gyv = gy.get(r, c);
                // float magv = std::abs(gxv) + std::abs(gyv); // L1. [0; 8*255]
                float magv = std::sqrt(gxv * gxv + gyv * gyv); // L2. [0; 4*255]]
                mag.get(r, c) = magv;
            }
        }

        // normalization
        float maxv = max(mag.getLength(), mag.getCoeffs());
        Tensor out = mul(255/maxv, mag);

        return out;
    }

};

#endif
