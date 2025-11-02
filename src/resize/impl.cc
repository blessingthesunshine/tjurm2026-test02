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
            float orig_r = r / scale;
            float orig_c = c / scale;
            int r1 = orig_r;
            int c1 = orig_c;
            int r2 = r1 + 1;
            int c2 = c1 + 1;
            // 边界检查
            if (r2 >= input.rows) r2 = input.rows - 1;
            if (c2 >= input.cols) c2 = input.cols - 1;

            float dr = orig_r - r1;
            float dc = orig_c - c1;

            float w1 = (1 - dr) * (1 - dc);
            float w2 = (1 - dr) * dc;
            float w3 = dr * (1 - dc);
            float w4 = dr * dc;

            Vec3b resize;
            for (int channel = 0; channel < 3; channel++) {
                float value = w1 * input.at<Vec3b>(r1, c1)[channel] + w2 * input.at<Vec3b>(r1, c2)[channel] + w3 * input.at<Vec3b>(r2, c1)[channel] + w4 * input.at<Vec3b>(r2, c2)[channel];
                resize[channel] = static_cast<uchar>(value);
            }
            output.at<Vec3b>(r, c) = resize;
        }
    }
    return output;
}