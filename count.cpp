#include"people.h"
void Count(int &count,int sum,int hei)
{

    vector<int> Hei;

    for(int i =1;i<=sum;i++)
    {

        if(sum%i == 0)
        {
            Hei.push_back(i);
        }
    }

   /* cout<<"-------------------------"<<endl;
    cout<<"2.Count..."<<endl;
    for(int i = 0;i<Hei.size();i++)
    {
        cout<<"The Hei["<<i<<"] is "<<Hei[i]<<endl;
    }
    cout<<"The hei is "<<hei<<endl;
    cout<<"---------------------------"<<endl;*/
    for(unsigned int i = 0;i<Hei.size();i++)
    {
        if(hei == Hei[i])
        {
           count = hei*(sum-hei);
        }

    }


}
