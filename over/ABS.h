#ifndef ABS_H
#define ABS_H
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int flag = 0;
int g_ThValue;
const int g_ThValueMax = 255;
int g_weight = 0.5;
const int g_weightMax = 10;
 char C[100];     //储存显示框内人数的字符数组
Mat foreFrame; //abs 前景
Mat backFrame_Th; //abs 背景 二值化
Mat frame,gray; // 原始图 灰度图
Mat backFrame;  // abs 背景
Mat frame_0;  //第一帧 用于abs
Mat foreground;  //mog 前景图
Mat background;   //mog 背景图
Mat dst;    //abs 和mog
void draw(Mat back,Mat frame);
bool intersection(const vector<Point> & line1, const vector<Point> &line2);
bool rectText(const vector<Point> & line,const Rect & targetRect);
void before(Mat ROI1);
void shadow(Mat &ROI1);
#endif // ABS_H
