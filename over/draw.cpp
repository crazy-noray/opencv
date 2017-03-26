#include"ABS.h"
/*绘制与统计函数--------------------------------------------------*/
//首先定义点集合和轮廓集合
//使用寻找轮廓函数，寻找前景图的轮廓
//然后寻找轮廓的最小外包以及最小外包矩形
//在寻找的循环中我加入了人的前景最小外包矩形的高度和宽度的标志和结算时的人数标志变量
//之后初步筛选前景图像 先使用contourArea（）函数计算面积 并且选择轮廓面积大于1000的矩形
//在这里面我还加入了点到直线的距离计算公式，目的是计算过线人数
//之后的两个rectangle函数便是绘制函数
//后面的选择判断则是根据最小包围矩形的长度和宽度进行分类和长度宽度标志变量的赋值 并且计算出人数标志变量
//还有就是将宽度和长度固定，这个地方还有一点小问题 就是长度和宽度会近似不变 但是 还是会有一定的变化
//之后的switch是对人数标志变量进行分类并且在一定情况下将人数加入总人数
//最后是划线 绘制虚拟检测线并且调用过线检测的函数判断是否过线
     //储存显示框内人数的字符数组

void draw(Mat back,Mat frame)
{
     char People[100];//储存显示总人数的字符数组
    Mat show = frame.clone();
    vector<vector< Point> > contours;
    vector<Vec4i > hierarchy;
    findContours(back,contours,hierarchy,
   RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));//查找轮廓
    int area[10000];
    vector<vector<Point> > contours_poly(contours.size());
    vector<Rect> boundRect(contours.size());
     int people = 0;//总人数


//    cout<<"contours.size is "<<contours.size()<<endl;
    for(unsigned int i = 0; i < contours.size(); i++)
    {

        int WID = 0;    //人数检测高度标志
        int HEI = 0;    //人数检测宽度识别
        int SUM = 0;   //结算时 人数统计标志变量
        int count =0;
   //     cout<<i<<".the count is"<<count<<endl;
        area[i] = contourArea(contours[i]);
        if(area[i]>1200)
        {
            approxPolyDP(Mat (contours[i]),contours_poly[i],3,true);
            boundRect[i] = boundingRect(Mat(contours_poly[i]));//找出外接矩形
            Scalar color = Scalar(0,255,0);
      /*
            //    输出显示 框的个数标号 框的面积 框的长度 框的宽度  框的起点的坐标 框的中心坐标
            cout<<"  "<<"  The width is "<<boundRect[i].width<<endl
               <<". And the height is "<<boundRect[i].height<<endl;
            cout<<"And the area is  "<<area[i]<<endl;
            cout<<"the x = "<<boundRect[i].x<<endl
               <<" And the Y  = "<<boundRect[i].y<<endl;
            cout<<" The point  is ("
                <<boundRect[i].x<<","
               <<boundRect[i].y<<")"<<endl;
      */
            if(boundRect[i].width<=70)//区域宽度标志为1
            {
                WID = WID+1;
                boundRect[i].width = 40;
            }
            else if(boundRect[i].width<=120)//区域宽度标志为2
            {
                WID = WID + 2;
                boundRect[i].width = 90;
            }
            else if(boundRect[i].width<=170)//区域宽度标志为3
            {
                WID = WID + 3;
                boundRect[i].width = 140;
            }
            else
            {
                WID = WID+4;
                boundRect[i].width = 190;

            }
  //          cout<<"The count WID is "<<WID<<endl;
            if(boundRect[i].height<=130)//区域长度标志为1
            {
                HEI = HEI+1;
                boundRect[i].height = 100;
            }
            else if(boundRect[i].height<=180)//区域长度标志为2
            {
                HEI = HEI+2;
                boundRect[i].height = 150;
            }
            else if(boundRect[i].height<=230)//区域长度标志为3
            {
                HEI = HEI+3;
                boundRect[i].height = 200;
            }
            else
            {
                HEI = HEI+4;
                 boundRect[i].height = 250;
            }
   //         cout<<"the countHEI is "<<HEI<<endl;




     //判断区域内人数
            SUM = HEI+WID;
     //      cout<<"the SUM is  "<<SUM<<endl;
            switch(SUM)
            {
            case 2:
                count++;
                break;
            case 3:
                count = count + 2;
                break;
            case 4:
                if(HEI==2||WID==2)
                    count = count + 4;
                else
                    count = count + 3;
                break;
            case 5:
                if(HEI==1||HEI == 4)
                    count = count + 4;
                else
                    count = count + 6;
                break;
            case 6:
                if(HEI == 2||HEI == 4)
                    count = count + 8;
                else
                    count = count + 9;
                break;
            case 7:
                if(HEI==6)
                    count+=6;
                else if(HEI==2)
                    count +=8;
                else if(HEI==3)
                    count+=9;
                break;
            case 8:
                count = count + 16;
                break;
            default:
                count = count + 0;
                break;
            }
              people+= count;



            if(boundRect[i].y>3){
            rectangle(show,boundRect[i].tl(),boundRect[i].br(),color,2,8,0);
            rectangle(back,boundRect[i].tl(),boundRect[i].br(),color,-1,8,0);
        }



  //           cout<<"the count is"<<count<<endl;
     //区域内人数显示
            sprintf(C,"%d",count);
            putText(show,C,Point(boundRect[i].x+20,boundRect[i].y+20),
                CV_FONT_HERSHEY_COMPLEX,1,Scalar(0,0,122));


       }//区域面积是否合格判断结束
   }//区域个数循环结束
 //总人数显示
    sprintf(People,"%d",people);
    putText(show,People,Point(120,330),CV_FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255));
    putText(show,"People:",Point(0,330),2,1,Scalar(0,0,255));
    imshow("draw",show);
}//函数结束

