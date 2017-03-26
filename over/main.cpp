/*问题：
 * 1.摄像头视角问题 由于我之前采集的视频丢失，所以采用了这个视频 这个视频是从网上下载的 专门用于行人检测的视频
 *   但是我之前开发调试使用的都是之前采集的视频。但是具体细节会有不同。等过段时间我会再去采集一些视频用于测试和完善
 * 2.人数计数问题，这个因为我一直处理的人数都相对较少，所以对这个多人数的统计没有想到，现在我正在想这个问题应该怎么去处理
 *
 */



#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include"ABS.h"
#include"draw.cpp"
#include"people.cpp"
#include"before.cpp"
#include"shadow.cpp"
using namespace cv;
using namespace std;



//这个主要是使用了高斯函数混合建模的方法提取前景图，但是因为阴影处理的关系我又使用了帧差法并且将两者的图片进行混合
//用以解决因为阴影处理带来的部分行人漏检的问题

int main ()
{

    Mat gray; // 原始图 灰度图
    Mat frame_0;  //第一帧 用于abs
    Mat foreground;  //mog 前景图
    Mat background;   //mog 背景图
    Mat dst;    //abs 和mog
     int frameNum = 0;
    VideoCapture capture("j://4.mp4");
     BackgroundSubtractorMOG2 mog;
    if (!capture.isOpened())
    {
        cout<<"No camera or video input!\n"<<endl;
        return -1;
    }
   while(1)
    {
        frameNum++;
        cout<<frameNum<<endl;
        if(frameNum/20<20&&frameNum%20==0)
        {
            cout<<"loading......."<<endl;
           // system("cls");
        }


        capture>>frame;
       // frame  = frame(Range(400,1050),Range(700,1400));
       resize(frame,frame,Size(640,360),0,0,2);

        mog(frame, foreground, 0.0005);
        mog.getBackgroundImage(background);
//
     //  before(foreground);
   //    imshow("d",foreground);
        cvtColor( frame,gray, CV_RGB2GRAY );
        if(frameNum==1)
        {
            backFrame=gray.clone();
            frame_0=backFrame;
        }
        else
        {
            backFrame=frame_0;
        }
        Canny(gray,gray,240,255,3);
        absdiff(backFrame,gray,foreFrame);//用帧差法求前景
        threshold(backFrame,backFrame_Th,220,255,THRESH_BINARY);
        normalize(backFrame_Th,backFrame_Th,120, 255, NORM_MINMAX, CV_8UC1);
       // imshow("th",backFrame_Th);

        if(frameNum>=500)
        {
          shadow(foreground);
          addWeighted(foreground,0.5,backFrame_Th,0.5,0.0,dst);
           imshow("qdst",dst);
           before(dst);
           imshow("dst",dst);
           draw(dst,frame);
           imshow("frame1",frame);
        }
        frame_0 = gray.clone();
       //waitKey(0);
       if(waitKey(10)=='q')
          break;
    }
}
