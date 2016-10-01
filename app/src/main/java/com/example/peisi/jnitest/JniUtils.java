package com.example.peisi.jnitest;

/**
 * Created by peisi on 16/9/13.
 */
public class JniUtils {
    static {
        System.loadLibrary("JniLibName"); //和生成so文件的名字对应。
    }
    public static native String getStringFormC();
}
