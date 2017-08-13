#include"people.h"
void text(Mat &win,string word, int x, int y,int color)
{
    putText(win,word,Point(x,y)
            ,CV_FONT_HERSHEY_COMPLEX,0.7,switchColor(color));
}

void text(Mat &win,int number,int x,int y,int color)
{

    char word[100];
    sprintf(word,"%d",number);
    putText(win,word,Point(x,y)
            ,CV_FONT_HERSHEY_COMPLEX,0.7,switchColor(color));
}
void text(Mat &win,double number,int x,int y,int color)
{

    char word[100];
    sprintf(word,"%.2f",number);
    putText(win,word,Point(x,y)
            ,CV_FONT_HERSHEY_COMPLEX,0.7,switchColor(color));
}
Scalar switchColor(int colorNumber)
{
    switch (colorNumber) {
    case 1:
        return Scalar(255,0,0);
        break;
    case 2:
        return Scalar(0,255,0);
        break;
    case 3:
        return Scalar(0,0,255);
        break;
    default:
        return Scalar(255,255,255);
        break;
    }

}

