#include"ABS.h"
/*-------------------------------------------------*/
//使用归一化函数 进行线性归一化
//然后进行矩形膨胀算子，膨胀内核为17
//进行矩形腐蚀算子，腐蚀内核为9
//最后进行中值滤波，内核为11
/*------------------------------------------------------*/
void before(Mat ROI1)//预处理函数
{
    //  imshow(" 1",ROI1);
    normalize(ROI1,ROI1,120, 255, NORM_MINMAX, CV_8UC1);

    int dilateType = MORPH_RECT;
    int dilateSize =2;
    Mat elementDilate = getStructuringElement(dilateType,
        Size(2*dilateSize + 1, 2*dilateSize+1),
        Point(dilateSize, dilateSize));
    //腐蚀算子
    int erosionType = MORPH_RECT;
    int erosionSize =1 ;
    Mat erosionElement = getStructuringElement(erosionType,
        Size(2*erosionSize+1, 2*erosionSize+1),
        Point(erosionSize, erosionSize));
    medianBlur(ROI1,ROI1,9);
    threshold(ROI1,ROI1,120,255,THRESH_BINARY);
    imshow("1",ROI1);
for(int i = 0;i<2;i++)
{
    erode(ROI1,ROI1,erosionElement);
  //  medianBlur(ROI1,ROI1,3);
    dilate(ROI1,ROI1, elementDilate);
    erode(ROI1,ROI1, erosionElement);
}
   // medianBlur(ROI1,ROI1,3);
  ROI1 = ROI1>130;
    //imshow("dddddddddddddddddst",ROI1);
}

