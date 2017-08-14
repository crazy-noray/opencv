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
    if(waitKey(10) == ' ' )
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
        key= true;
    if(waitKey(10) == ' ')
    {
        exit(0);
    }


}
void peopleDeal(Rect &boundRect,int count)
{

    if(count>=3)
    {
          if(boundRect.height<128)
              boundRect.height = 128;
          if(boundRect.width<64)
              boundRect.width = 64;
    }


}

void videoDeal(Mat &frame)
{
    int col = frame.cols;
    int row = frame.rows;
    while(frame.cols>800)
    {
        col /=2;
        row /=2;
        resize(frame,frame,Size(col,row),0,0,2);
    }
   

}
