#include"people.h"
#include<fstream>

void draw(Mat frame ,Mat back,int &people)
{


    Mat show = frame.clone();

    vector<vector<Point> > contours;
    vector<Vec4i>hierarchy;

    findContours(back,contours,hierarchy,
                 RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
    int area[100000];
    vector< vector<Point> >contours_poly(contours.size());
    vector<Rect>boundRect(contours.size());

    for(unsigned int i = 0;i<contours.size();i++)
    {
        int hei = 0;
        int wid = 0;
        int sum = 0;
        int count =0;
        area[i] = contourArea(contours[i]);

        if(area[i]>1200)
        {
            approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
            boundRect[i] = boundingRect(Mat(contours_poly[i]));

            sum = addWeight(boundRect[i],hei,wid);

            if(sum == 0)
            {
               continue;
            }
            else
            {
              Count(count,sum,wid);
            }

          /*  cout<<"------------------------------------------"<<endl;
            cout<<"3.draw.."<<endl;
            cout<<"The height is "<<boundRect[i].height<<endl;
            cout<<"The width is "<<boundRect[i].width<<endl;
            cout<<"sum is "<<sum<<endl;
            cout<<"the count is"<<count<<endl;
            cout<<"------------------------------------------"<<endl;
*/
            Scalar green= Scalar(0,255,0);
            rectangle(show,boundRect[i].tl(),boundRect[i].br(),green,2,8,0);

            people+=count;

            text(show,count,boundRect[i].x+5,boundRect[i].y+3,1);

        }//面积判断结束
    }//区域循环结束

    text(show,"People:",10,20,3);
    text(show,people,130,20,3);

    imshow("draw",show);

}
