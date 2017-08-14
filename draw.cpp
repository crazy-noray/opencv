#include"people.h"
#include<fstream>

void draw(Mat frame ,Mat back,int &people)
{

    Mat show = frame.clone();

    //contours角点的容器，hierarchy 层容器
    vector<vector<Point> > contours;
    vector<Vec4i>hierarchy;

    findContours(back,contours,hierarchy,
                 RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

    //轮廓面积，外部轮廓，外接矩形
    int area[10000];
    vector< vector<Point> >contours_poly(contours.size());
    vector<Rect>boundRect(contours.size());

    for(unsigned int i = 0;i<contours.size();i++)
    {
        int hei = 0;//高度权重
        int wid = 0;//宽度权重
        int count =0;//框内估计人数

        area[i] = contourArea(contours[i]);//求轮廓面积

        if(area[i]>1200)
        {
            approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
            boundRect[i] = boundingRect(Mat(contours_poly[i]));

            count = addWeight(boundRect[i],hei,wid);

            peopleDeal(boundRect[i],count);
/*
            cout<<"------------------------------------------"<<endl;
            cout<<"3.draw.."<<endl;
            cout<<"The height is "<<boundRect[i].height<<endl;
            cout<<"The width is "<<boundRect[i].width<<endl;
            cout<<"the count is"<<count<<endl;
            cout<<"------------------------------------------"<<endl;
*/
            drawRect(show,boundRect[i],count);

            if(boundRect[i].height>128&&boundRect[i].width>64)
            {
                Mat mask = show(Range(boundRect[i].y,boundRect[i].y+boundRect[i].height),
                                 Range(boundRect[i].x,boundRect[i].x+boundRect[i].width));
                people += dete(mask);
            }
            else
            {
                 people+=count;//获得当前视频 范围内人数
            }




        }//面积判断结束
    }//区域循环结束

    text(show,"People:",10,20,3);
    text(show,people,130,20,3);

    imshow("draw",show);


}
void drawRect(Mat show,Rect boundRect,int count)
{
    if(count != 0 )
    {
        boundRect.y -= 5;
        boundRect.height -= 10;

        Scalar green= Scalar(0,255,0);
        rectangle(show,boundRect.tl(),boundRect.br(),green,2,8,0);

        text(show,count,boundRect.x+5,boundRect.y+3,1);//显示到屏幕上

    }
}
