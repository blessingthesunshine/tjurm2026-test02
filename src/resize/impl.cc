#include "impls.h"
using namespace cv;

cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    Mat output = Mat::zeros(new_rows, new_cols, input.type());
    for (int r = 0; r < new_rows; r++) {
        for (int c = 0; c < new_cols; c++) {
            int orig_r = static_cast<int>(r / scale);
            int orig_c = static_cast<int>(c / scale);
            output.at<Vec3b>(r, c) = input.at<Vec3b>(orig_r, orig_c);
        }
    }
    return output;
    return cv::Mat::zeros(new_rows, new_cols, input.type());
}
