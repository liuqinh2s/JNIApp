#include "native-lib.h"
#include "mylog.h"
#include <string>
#include <assert.h>

typedef struct{
    float m_FOV;
    int m_InterpolateType;
    int m_MediaType;
}CBaseInitPara;

//静态注册
JNIEXPORT jstring JNICALL
Java_com_example_liuqinh2s_jniapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject obj) {
    LOGE("static register log XXX");
    jclass clz = env->FindClass("com/example/liuqinh2s/jniapp/MainActivity");
    jfieldID m_FOV = env->GetFieldID(clz, "m_FOV", "F");
    jfieldID m_InterpolateType = env->GetFieldID(clz, "m_InterpolateType", "I");
    jfieldID m_MediaType = env->GetFieldID(clz, "m_MediaType", "I");
//    jobject obj;
    env->SetFloatField(obj,m_FOV,5.6);
    env->SetIntField(obj,m_InterpolateType,2);
    env->SetIntField(obj,m_MediaType,7);
    LOGE("static register log XXX");
    std::string s = "hello native-lib";
    return env->NewStringUTF(s.c_str());
}

//动态注册

static jstring native_dynamic_key(JNIEnv *env, jobject obj){
    LOGE("static register log XXX");
    jclass clz = env->FindClass("com/example/liuqinh2s/jniapp/MainActivity");
    jfieldID m_FOV = env->GetFieldID(clz, "m_FOV", "F");
    jfieldID m_InterpolateType = env->GetFieldID(clz, "m_InterpolateType", "I");
    jfieldID m_MediaType = env->GetFieldID(clz, "m_MediaType", "I");
//    jobject obj;
    env->SetFloatField(obj,m_FOV,57.7);
    env->SetIntField(obj,m_InterpolateType,200);
    env->SetIntField(obj,m_MediaType,99);
    LOGE("static register log XXX");
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


