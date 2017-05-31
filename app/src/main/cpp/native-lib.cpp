#include "native-lib.h"
#include "mylog.h"
#include <string>
#include <assert.h>

//静态注册
JNIEXPORT jstring JNICALL
Java_com_example_liuqinh2s_jniapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    LOGE("static register log ");
    return env->NewStringUTF(hello.c_str());
}


//动态注册

static jstring native_dynamic_key(JNIEnv *env, jobject /* this */){
    LOGE("hello native-lib");
    std::string s = "hello native-lib";
    return env->NewStringUTF(s.c_str());
}

//函数映射表
static JNINativeMethod methods[] = {
        {"dynamicGenerateKey", "(Ljava/lang/String;)Ljava/lang/String;", (jstring *)native_dynamic_key},
        //这里可以有很多其他映射函数
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
    LOGD("--------- JNI_Onload into. -----------\n");
    JNIEnv* env = NULL;
    if (vm->GetEnv((void** ) &env, JNI_VERSION_1_4) != JNI_OK)
    {
        return -1;
    }
    assert(env != NULL);
    LOGE("JNI_OnLoad comming");
    jclass clz = env->FindClass("com/example/liuqinh2s/jniapp/MainActivity");
    LOGE("JNI_OnLoad commingXXXX");
    env->RegisterNatives(clz, methods, sizeof(methods)/sizeof(methods[0]));
    LOGE("nihao");
    return JNI_VERSION_1_4;
}


