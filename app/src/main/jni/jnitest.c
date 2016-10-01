
#include "com_example_peisi_jnitest_JniUtils.h"
//
// Created by ChuPeisi on 16/9/13.
//

#include <string.h>
#include <assert.h>


JNIEXPORT jstring JNICALL Java_com_example_peisi_jnitest_JniUtils_getStringFormC
  (JNIEnv *env, jclass obj) {
        return (*env)->NewStringUTF(env,"这里是来自c的string");
  }

JNIEXPORT jstring JNICALL getCLanguageString
        (JNIEnv *env, jobject obj) {
    return (*env)->NewStringUTF(env, "This is Jni test!!!");
}

//参数映射表
static JNINativeMethod methods[] = {
        {"getStringFormC", "()Ljava/lang/String;", (void *) getCLanguageString},
};

//自定义函数，为某一个类注册本地方法，调运JNI注册方法
static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *gMethods,
                                 int numMethods) {
    jclass clazz;
    clazz = (*env)->FindClass(env, className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }

    if ((*env)->RegisterNatives(env, clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

static int registerNatives(JNIEnv* env)
{
    const char* kClassName = "com/example/peisi/jnitest/JniUtils";//指定要注册的类
    return registerNativeMethods(env, kClassName, methods,  sizeof(methods) / sizeof(methods[0]));
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    jint result = -1;

    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);

    //动态注册，自定义函数
    if (!registerNatives(env)) {
        return -1;
    }

    return JNI_VERSION_1_4;
}
