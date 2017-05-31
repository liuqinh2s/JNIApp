//
// Created by liuqinh2s on 31/05/2017.
//

#include <jni.h>

#ifndef JNIAPP_NATIVE_LIB_H
#define JNIAPP_NATIVE_LIB_H

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT jstring JNICALL
Java_com_example_liuqinh2s_jniapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */);

static jstring native_dynamic_key(JNIEnv *env, jobject /* this */);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);


#ifdef __cplusplus
}
#endif
#endif //JNIAPP_NATIVE_LIB_H
