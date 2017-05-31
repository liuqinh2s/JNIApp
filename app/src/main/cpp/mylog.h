//
// Created by liuqinh2s on 31/05/2017.
//

#ifndef JNIAPP_MYLOG_H
#define JNIAPP_MYLOG_H

#include <android/log.h>

#define LOG_TAG "native-lib.cpp"

#ifndef LOG_TAG
#error You should define LOG_TAG
#endif

#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#endif //JNIAPP_MYLOG_H
