# JniDemo
Jni demo
  A simple jni demo created by Android Studio 2.2
  
  It contains 2 Android Jni implementation
    - Specific function name. such as Java_com_example..., the function name can auto produced by javah.
    - RegisterNatives. this kind of implementation does not need a long function name, it will create mapping from Java function to Native function.
    
  From the demo, we can also find that if contains 2 implementations, RegisterNatives has a higher priority.
  
  -------------------------------------------------
  How to create JNI Project with Android Studio 2.2
  
    - Create jni folder under src folder
    - Write jni header and its c implementation
    - Add the following info to app/build.gradle under 'defaultConfig' angle brackets
      ndk {
        moduleName "JniLibName"         //so module name
        abiFilters "armeabi", "armeabi-v7a", "x86"  //abi
        //cFlags "-DANDROID_NDK -D_DEBUG DNULL=0"
        //ldLibs "EGL", "GLESv3", "dl", "log"
        //stl "stlport_shared"

        // All supported ndk config in HERE: https://android.googlesource.com/platform/tools/build/+/c4f572d8dd9664c63a04f48a99b79acfb9513de9/gradle/src/main/groovy/com/android/build/gradle/internal/dsl/NdkConfigDsl.java
      }
    - Add the following info to gradle.properties 
      android.useDeprecatedNdk=true
