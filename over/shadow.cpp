#include"ABS.h"
//阴影处理函数
//将背景图的颜色空间转化成BGR
//然后取一定的阈值 因为阴影的颜色会稍微的浅一点，但是由于系统会吧颜色接近背景颜色的人误检为阴影所以会产生一些问题
//然后转换回来 以便于下一步的处理
void shadow(Mat &back)
{
    Mat back2 = back.clone();
    Mat deledst;
    cvtColor(back,back,COLOR_GRAY2BGR);
    threshold(back,back,127,255,CV_THRESH_BINARY);
    cvtColor(back,back,COLOR_BGR2GRAY);
    absdiff(back,back2,deledst);
    absdiff(back2,deledst,deledst);
    // imshow("abs There",deledst);
}



