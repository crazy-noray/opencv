#ifndef PEOPLE_H

#define PEOPLE_H





#endif // PEOPLE_H
#include<opencv.hpp>
#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;


void before(Mat &back);
void shadow(Mat &back);
void draw(Mat back,Mat frame,int &people);
int addWeight(Rect boundRect,int &hei,int &wid);
void Count(int &,int, int);
void text(Mat &win,int number,int x,int y,int color);
void text(Mat &win,string word, int x, int y,int color );
Scalar switchColor(int colorNumber);
void frameNumbers(int &frameNum);
void frameDiff(int frameNum,Mat &backFrame,Mat gray,Mat &frame_0);
void textShow(Mat frame,double fps,int frameNum,int people);
double FPSTime(double time);
void videoCheck(VideoCapture capture);
Mat dealFrameDiff(Mat gray,Mat backFrame);
Mat deal(Mat frame,Mat foreground,Mat foreFrame,int &people);
void colorSpaceTrans(Mat frame,Mat &gray);
void StopDeal(Mat frame,bool &key);
void startDeal(Mat frame,bool &key);
void peopleDeal(Rect &,int count);
void drawRect(Mat show,Rect boundRect,int count);
int dete(Mat &dst)
