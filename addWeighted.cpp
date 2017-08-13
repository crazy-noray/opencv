#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
#include<fstream>
using namespace cv;
using namespace std;

int addWeight(Rect boundRect,int &hei,int &wid)
{


    switch(boundRect.y/100)
    {
    case 0:
        wid = (boundRect.width)/36;
        hei = (boundRect.height)/60;
        break;
    case 1:
        wid = (boundRect.width)/42;
        hei = (boundRect.height)/70;
        break;
    case 2:
        wid = (boundRect.width)/48;
        hei = (boundRect.height)/80;
        break;
    case 3:
        wid = (boundRect.width)/54;
        hei = (boundRect.height)/90;
        break;
    default:
        wid = (boundRect.width)/60;
        hei = (boundRect.height)/100;
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
