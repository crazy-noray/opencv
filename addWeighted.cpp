#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
#include<fstream>
using namespace cv;
using namespace std;

int addWeight(Rect boundRect,int &hei,int &wid)
{


  if(boundRect.width<70||boundRect.height<90)
    {
        if(boundRect.width>=40)
        {
            wid = 1;
        }
        else
        {
            wid = 0;
        }
        if(boundRect.height>=60)
        {
            hei = 1;
        }
        else
        {
            hei = 0;
        }
        return hei*wid;
    }


    switch(boundRect.y/100)
    {
    case 0:
        wid = (boundRect.width-70)/30+1;
        hei = (boundRect.height-90)/38+1;
        break;
    case 1:
        wid = (boundRect.width-80)/30+1;
        hei = (boundRect.height-105)/38+1;
        break;
    case 2:
        wid = (boundRect.width-80)/30+1;
        hei = (boundRect.height-115)/38+1;
        break;

    default:
        wid = (boundRect.width-85)/30+1;
        hei = (boundRect.height-95)/38+1;
        break;


    }

 /*   cout<<"----------------------------------------"<<endl;
    cout<<"1.This is addWeight"<<endl;
    cout<<"The boundRect locate is ("<<boundRect.x<<"."<<boundRect.y<<")"<<endl;
    cout<<"The height is "<<boundRect.height<<endl;
    cout<<"The width is "<<boundRect.width<<endl;
    cout<<"The wid is "<<wid<<endl;
    cout<<"The hei is "<<hei<<endl;
    cout<<"----------------------------------------"<<endl;
*/
    return hei+wid;
}
