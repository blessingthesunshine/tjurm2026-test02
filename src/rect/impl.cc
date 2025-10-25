#include "impls.h"
using namespace cv;
using namespace std;

std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    imshow("input", input);
    
    // IMPLEMENT YOUR CODE HERE
    Mat gray, binary;
    cvtColor(input, gray, COLOR_BGR2GRAY);
    threshold(gray, binary, 200, 255, THRESH_BINARY_INV);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(binary, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    std::pair<cv::Rect, cv::RotatedRect> res;

    double max_area = 0.0;
    int max_index = -1;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        if (area > max_area) {
            max_area = area;
            max_index = i;
        }
    }
    if (max_index != -1) {
        res.first = boundingRect(contours[max_index]);
        res.second = minAreaRect(contours[max_index]);
    }
    return res;
}