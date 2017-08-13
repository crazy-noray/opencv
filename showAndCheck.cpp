
#include"people.h"
void textShow(Mat frame,double fps,int frameNum,int people)
{
    text(frame,"fps:",60,20,3);
    text(frame,fps,110,20,3);
    text(frame,frameNum,frame.cols-70,20,3);
    text(frame,"People:",10,frame.rows-10,3);
    text(frame,people,100,frame.rows-10,3);

}
double FPSTime(double time)
{
    time = ((double)getTickCount()-time)/getTickFrequency();
    double fps = 1.0/time;
    return fps;
}

void frameNumbers(int &frameNum)
{
    frameNum++;
}
void videoCheck(VideoCapture capture)
{
    if(!capture.isOpened())
    {
        cerr<<"No camera or video input!\n"<<endl;

    }

}
