#include"people.h"
void frameDiff(int frameNum,Mat &backFrame,Mat gray,Mat &frame_0)
{
    if(frameNum == 1)
    {
        backFrame = gray.clone();
        frame_0 = backFrame;
    }
    else
    {
        backFrame = frame_0;
    }
}
