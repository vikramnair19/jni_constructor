#include "Sample1.h"
#include <string.h>

int mynum=0;
JNIEXPORT jint JNICALL Java_Sample1_intMethod
  (JNIEnv *env, jobject obj, jint num) {
  //num=mynum;
  return ++mynum;
}

JNIEXPORT jboolean JNICALL Java_Sample1_booleanMethod
  (JNIEnv *env, jobject obj, jboolean boolean) {
  return !boolean;
}

JNIEXPORT jstring JNICALL Java_Sample1_stringMethod
  (JNIEnv *env, jobject obj, jstring string) {
    const char *str = (*env)->GetStringUTFChars(env, string, 0);
    char cap[128];
    strcpy(cap, str);
    (*env)->ReleaseStringUTFChars(env, string, str);
    return (*env)->NewStringUTF(env, cap);
}

JNIEXPORT jint JNICALL Java_Sample1_intArrayMethod
  (JNIEnv *env, jobject obj, jintArray array) {
    int i, sum = 0;
    jsize len = (*env)->GetArrayLength(env, array);
    jint *body = (*env)->GetIntArrayElements(env, array, 0);
    for (i=0; i<len; i++)
    {	sum += body[i];
    }
    (*env)->ReleaseIntArrayElements(env, array, body, 0);
    return sum;
}

JNIEXPORT jobject JNICALL Java_Sample1_simeventGetNextEvent
  (JNIEnv *env, jobject obj){
  
  jclass stringClass;
  jclass simeventClass;
  jmethodID cid; 
  jobject result;

  stringClass = (*env)->FindClass(env, "SimEvent");
  if (stringClass == NULL) {
    return NULL; /* exception thrown */
  }
  /* Get the method ID for the String(char[]) constructor */
  cid = (*env)->GetMethodID(env, stringClass,
			    "<init>", "()V");
  if (cid == NULL) {
    return NULL; /* exception thrown */
  }
  result = (*env)->NewObject(env, stringClass, cid);
  (*env)->DeleteLocalRef(env, stringClass);
  return result;
}


void main(){}
