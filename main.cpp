#include <iostream>
#include <chrono>

#include <opencv2/opencv.hpp>

#include "TensorX/Tensor.hpp"
#include "utils.hpp"
#include "convolution.hpp"
#include "ops.hpp"
#include "opencv_utils.hpp"
#include "image_processing.hpp"


using tensor::Tensor;
using tensor::mat2tensor, tensor::tensor2mat;


void custom_canny(){
    auto start = std::chrono::high_resolution_clock::now();

    // code block
    Tensor<float> t = tensor::imread_gray("./images/lenna.png");
    Tensor edges = tensor::canny(t, 30.0f, 80.0f);
    // tensor::imshow(edges);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "custom_canny: " << duration_ns.count() << "ns" << std::endl;
}

void opencv_canny(){
    auto start = std::chrono::high_resolution_clock::now();

    // OpenCV Canny
    cv::Mat img = cv::imread("./images/lenna.png", cv::IMREAD_GRAYSCALE);
    if (img.empty()) return;
    cv::Mat edges;
    cv::Canny(img, edges, 100, 200);
    // cv::imshow("Original", img);
    // cv::imshow("Canny OpenCV", edges);
    // cv::waitKey(0);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "opencv_canny: " << duration_ns.count() << "ns" << std::endl;
}


void test(){
    tensor::test_conv();
    tensor::test_mul();
    tensor::test_mul_scalars();
    tensor::test_scalar_mul();
    custom_canny();
    opencv_canny();
}


int main(){
    test();

    // Tensor<float> t = tensor::imread_gray("./images/lenna.png");
    Tensor<float> t = tensor::imread_gray("./images/karis.jpeg");

    std::cout << "t: rank(" << t.getRank() << "), size(" << t.getLength() << ")" << std::endl;
    std::cout << "t: dims(" << array2string(t.getRank(), t.getDims()) << ")" << std::endl;
    std::cout << "t: type(" << typeid(typename decltype(t)::type).name() << ")" << std::endl;

    // Convolution

    // Canny

    // 1. Gaussian Filter
    Tensor blurred = tensor::gaussian_blur(t, 2);

    // 2. Image Derivarive
    Tensor sobel = tensor::sobel_operator(blurred);

    // 3. Non-Maximum Suppression (NMS)
    Tensor nms = tensor::non_max_suppression(sobel);

    // 4. Double Thresholding
    Tensor strongweak = tensor::double_threshold(nms, 20.0f, 80.0f);

    // 5. Hysterisis
    Tensor chained = tensor::hysterisis(nms, 20.0f, 80.0f);

    // Auto Threshold Values
    float median = find_median(sobel);
    float mean = find_mean(sobel);
    std::cout << "median: " << median << std::endl;
    std::cout << "mean: " << mean << std::endl;
    // float low = std::max(0.0f, mean);
    // float high = std::min(255.0f, std::min(80.0f, 2*mean));
    // Tensor strongweak = tensor::double_threshold(nms, low, high);
    // Tensor chained = tensor::hysterisis(nms, low, high);

    tensor::imshow(t);
    tensor::imshow(blurred, "Gaussian Blur 5x5");
    tensor::imshow(sobel, "Sobel Operator");
    tensor::imshow(nms, "Non-Maximum Suppression");
    tensor::imshow(strongweak, "Double Threshold");
    tensor::imshow(chained, "Hysterisis");
    // tensor::imshow(tensor::canny(t, 20.0f, 80.0f));

    return 0;
}


