#include"people.h"

Mat deal(Mat frame,Mat foreground,Mat foreFrame,int &people)
{


    Mat dst;
    shadow(foreground);
    addWeighted(foreground,0.5,foreFrame,0.5,0.0,dst);
    normalize(dst,dst,0,130,NORM_MINMAX,CV_8UC1);
    medianBlur(dst,dst,1);
    before(dst);
    normalize(dst,dst,0,255,NORM_MINMAX,CV_8UC1);
    imshow("dst",dst);
    draw(frame,dst,people);
    return dst;
}


void StopDeal(Mat frame,bool &key)
{
    text(frame,"On",5,20,3);
    if(waitKey(10) == 27)
    {
        exit(0);
    }
    if(waitKey(10) == 'q')
    {
        key = false;
    }
}
void startDeal(Mat frame,bool &key)
{
    text(frame,"Off",5,20,3);
    if(waitKey(10) == 27)
        exit(0);
    if(waitKey(10) == 'q')
        key = true;

}
