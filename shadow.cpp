#include"people.h"
void shadow(Mat &back)
{
    cvtColor(back,back,COLOR_GRAY2BGR);
    threshold(back,back,130,255,THRESH_BINARY);
    cvtColor(back,back,COLOR_BGR2GRAY);
    medianBlur(back,back,5);

}
