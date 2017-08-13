#include <iostream>
#include<opencv2/opencv.hpp>
#include"people.h"
using namespace std;
using namespace cv;



int main()
{
    Mat gray;           //灰度图
    Mat frame_0;        //第一帧 用于absdiff
    Mat foreground;     //MOG 前景图
    Mat background;
    Mat dst;            //abs和MOG混合之后的效果图
    Mat foreFrame;
    Mat backFrame;
    Mat frame;

    int people = 0;
    int frameNum = 0;   //帧数

    bool key = true;    //是否停止处理标志

    VideoCapture capture("E://1.mp4");

    BackgroundSubtractorMOG2 Mog;

    videoCheck(capture);

    while(1)
    {
        people = 0;

        frameNumbers(frameNum);

        double time = (double)getTickCount();

        capture>>frame;
        resize(frame,frame,Size(640,360),0,0,2);

        Mog(frame,foreground,0.001);
        Mog.getBackgroundImage(background);

        colorSpaceTrans(frame,gray);

        //帧差法
        frameDiff(frameNum,backFrame,gray,frame_0);

        //帧差法的结果处理 
        foreFrame = dealFrameDiff(gray,backFrame);

        if(key)
        {
            dst = deal(frame,foreground,foreFrame,people);
            StopDeal(frame,key);
        }else
        {
            startDeal(frame,key);
        }

        frame_0 = gray.clone();

        double fps = FPSTime(time);
        textShow(frame,fps,frameNum,people);
        imshow("frame",frame);

    }

    return 0;
}
