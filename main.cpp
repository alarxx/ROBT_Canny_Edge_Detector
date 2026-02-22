#include <iostream>
#include <stdio.h>

#include <opencv2/opencv.hpp>

#include "TensorX/Tensor.hpp"
#include "utils.hpp"
#include "convolution.hpp"
#include "ops.hpp"
#include "opencv_utils.hpp"
#include "image_processing.hpp"


using tensor::Tensor;
using tensor::mat2tensor, tensor::tensor2mat;


void test(){
    tensor::test_conv();
    tensor::test_mul();
    tensor::test_mul_scalars();
    tensor::test_scalar_mul();
}


int main(){
    Tensor<float> t = tensor::imread_gray("./lenna.png");
    std::cout << "t: rank(" << t.getRank() << "), size(" << t.getLength() << ")" << std::endl;
    std::cout << "t: dims(" << array2string(t.getRank(), t.getDims()) << ")" << std::endl;
    std::cout << "t: type(" << typeid(typename decltype(t)::type).name() << ")" << std::endl;

    // Convolution

    // Canny

    // 1. Gaussian Filter
    Tensor blurred = tensor::gaussian_blur(t, 2);

    // 2. Image Derivarive
    Tensor sobel = tensor::sobel_operator(blurred);

    // 3. Non-Maximum Suppression
    // 4. Double Thresholding
    // 5. Hysterisis

    tensor::imshow(t);
    tensor::imshow(blurred);
    tensor::imshow(sobel);

    return 0;
}


