QT += core
QT -= gui

CONFIG += c++11

TARGET = ImagePro
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
INCLUDEPATH += /usr/local/include/opencv \
        /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_features2d.so \
/usr/local/lib/libopencv_imgproc.so \
/usr/local/lib/libopencv_core.so \
/usr/local/lib/libopencv_highgui.so \
/usr/local/lib/libopencv_ml.so \
/usr/local/lib/libopencv_imgcodecs.so \
/usr/local/lib/libopencv_calib3d.so \
/usr/local/lib/libopencv_dnn.so \
/usr/local/lib/libopencv_flann.so \
/usr/local/lib/libopencv_imgproc.so \
/usr/local/lib/libopencv_objdetect.so \
/usr/local/lib/libopencv_photo.so \
/usr/local/lib/libopencv_shape.so \
/usr/local/lib/libopencv_stitching.so \
/usr/local/lib/libopencv_superres.so \
/usr/local/lib/libopencv_video.so \
/usr/local/lib/libopencv_videoio.so \
/usr/local/lib/libopencv_videostab.so \
/usr/local/lib/libopencv_viz.so

HEADERS  +=
