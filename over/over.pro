TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    before.cpp \
    draw.cpp \
    people.cpp \
    shadow.cpp

HEADERS += \
    ABS.h
INCLUDEPATH+=I:\opencv\opencv\build\include\opencv\
I:\opencv\opencv\build\include\opencv2\
I:\opencv\opencv\build\include\

LIBS+=c:\opencv\MinGW\lib\libopencv_calib3d249.dll.a\
  c:\opencv\MinGW\lib\libopencv_contrib249.dll.a\
  c:\opencv\MinGW\lib\libopencv_core249.dll.a\
  c:\opencv\MinGW\lib\libopencv_features2d249.dll.a\
  c:\opencv\MinGW\lib\libopencv_flann249.dll.a\
  c:\opencv\MinGW\lib\libopencv_gpu249.dll.a\
  c:\opencv\MinGW\lib\libopencv_highgui249.dll.a\
  c:\opencv\MinGW\lib\libopencv_imgproc249.dll.a\
  c:\opencv\MinGW\lib\libopencv_legacy249.dll.a\
  c:\opencv\MinGW\lib\libopencv_ml249.dll.a\
  c:\opencv\MinGW\lib\libopencv_objdetect249.dll.a\
  c:\opencv\MinGW\lib\libopencv_video249.dll.a

OTHER_FILES +=

