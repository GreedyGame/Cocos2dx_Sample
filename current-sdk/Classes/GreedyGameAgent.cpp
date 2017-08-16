
/****************************************************************************
 Copyright (c) 2014      GreedyGame
 
 http://www.greedygame.com
 
 ****************************************************************************/

#include "GreedyGameAgent.h"
#include "cocos2d.h"
#include <iostream>
#include <vector>
#include <map>
#include <iostream>
#include <string>

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#endif

USING_NS_CC;

	#define  GreedyGame_CLASS_NAME "com/greedygame/android/agent/GreedyGameAgent"
	#define GG_INIT "init"
    #define GG_GET_CAMPAIGN_PATH "getCampaignPath"
    #define GG_SHOW_FLOAT "showFloat"
    #define GG_REMOVE_ALL_FLOAT "removeAllFloat"
    #define GG_REMOVE_FLOAT_UNIT "removeFloat"
    #define GG_FORCED_EXIT "forcedExit"
    #define GG_SHOW_UII "showUII"
    #define GG_GET_NATIVE_PATH "getNativeUnitPath"
    #define GG_GET_FLOAT_PATH "getFloatUnitPath"
	#define GG_REFRESH "startEventRefresh"

	#define  CocosActivity_CLASS_NAME "org/cocos2dx/cpp/AppActivity"	
	#define COCOS_GETCONTEXT "myActivity"

namespace greedygame {

    IAgentListener* listener;
    // char* customActivityClass = "org/cocos2dx/cpp/AppActivity";
    // char* customActivityMethod = "myActivity";

    extern "C" {
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

	        JNIEXPORT void JNICALL Java_com_greedygame_android_platforms_cocos2dx_GreedyGame_onAvailable(JNIEnv* env, jobject thiz) {
	            listener->onAvailable();
	        }
	        
	        JNIEXPORT void JNICALL Java_com_greedygame_android_platforms_cocos2dx_GreedyGame_onUnavailable(JNIEnv* env, jobject thiz)
	        {
	            listener->onUnavailable();
	        }

	        JNIEXPORT void JNICALL Java_com_greedygame_android_platforms_cocos2dx_GreedyGame_onFound(JNIEnv* env, jobject thiz)
	        {
	            listener->onFound();
	        }

	        JNIEXPORT void JNICALL Java_com_greedygame_android_platforms_cocos2dx_GreedyGame_onError(JNIEnv* env, jobject thiz, jstring msg)
	        {
	            const char *nativeString = env->GetStringUTFChars(msg, 0);
	            listener->onError(nativeString);
				env->ReleaseStringUTFChars(msg, nativeString);
	        }

	        JNIEXPORT void JNICALL Java_com_greedygame_android_platforms_cocos2dx_GreedyGame_onProgress(JNIEnv* env, jobject thiz, jint ret)
	        {
	            listener->onProgress(ret);
	        }

	        // JNIEXPORT void JNICALL Java_com_greedygame_android_agent_JavaProxy_setClassAndMethod(JNIEnv* env, jobject thiz,jstring classname,jstring methodname) {
	        //    //  CCLOG("DEBUGGG JNI setClassAndMethod");
	        //   	// const char *classString = env->GetStringUTFChars(classname, 0);
	        //   	// const char *methodString = env->GetStringUTFChars(methodname, 0);

	        //    //  customActivityClass = classString;
	        //    //  customActivityMethod = methodString;


	        // }

	        JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_setActivity(JNIEnv* env, jobject thiz, jobject activity)
	        {
	        	CCLOG("DEBUGGG inside setup activity COCOS2dx");
	            GreedyGameAgent::initWithActivity(activity);
	        }

	        
		#endif
    }

    void GreedyGameAgent::initialize() {
		// #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	 //        cocos2d::JniMethodInfo t;
	 //        CCLOG("DEBUGGG CPP INITIALIZE");

	 //        if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
	 //                                                    ,COCOS_GETCONTEXT
	 //                                                    ,"()Landroid/app/Activity;"))
	 //        {
	 //           activity = (jobject) t.env->CallStaticObjectMethod(t.classID,t.methodID);
	 //           if(activity == NULL) {
	 //        	CCLOG("DEBUGGG ACTVIITY IS NULL");

	 //        } else {
	 //        	CCLOG("DEBUGGG ACTIVITY IS NOT NULL");

	 //        }
	 //        }

	        

		// #endif
    }

    void GreedyGameAgent::init() {
		// #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		//         cocos2d::JniMethodInfo t;
		      
		//         CCLOG("DEBUGGG CPP INIT");
		//         // if (cocos2d::JniHelper::getMethodId(t, GreedyGame_CLASS_NAME
		//         //                                             ,GG_INIT
		//         //                                             ,"(Landroid/app/Activity;)V"))
		//         // { 
		//         	if(activity == NULL) {
	 //        			CCLOG("DEBUGGG ACTVIITY IS NULL");

	 //        		} else {
	 //        			CCLOG("DEBUGGG ACTIVITY IS NOT NULL");

	 //        		}

	 //        JavaVM* vm = JniHelper::getJavaVM();
		// 	JNIEnv* env;
		// 	vm->GetEnv((void**)&env,JNI_VERSION_1_4);

	 //    //     		jclass cls = t.env->GetObjectClass(GreedyGame_CLASS_NAME);
		// 			// jmethodID method = t.env->GetMethodID(cls, "init", "(Landroid/app/Activity;)V");
		// 			// t.env->CallVoidMethod(GreedyGame_CLASS_NAME, method);
		// 			// CCLOG("DEBUGGG after method call");


	 //        jclass cls = env->FindClass(GreedyGame_CLASS_NAME);
	 //        if (NULL == cls) {
  //       		CCLOG("DEBUGGG Agent find class is null");
  //       		return;
  //   		} else {
  //        		CCLOG("DEBUGGG Agent find class is not null");
  //   		}

  //   jmethodID agentConstructor = env->GetMethodID(cls, "<init>", "()V");
  //   if (NULL == agentConstructor) {
  //       CCLOG("DEBUGGG Agent constructor is null");
  //       return;
  //   } else {
  //        CCLOG("DEBUGGG Agent constructor is not null");
  //   }

  //   jobject agentObject = env->NewObject(cls, agentConstructor);

  //   if (NULL == agentObject) {
  //       CCLOG("DEBUGGG Agent object is null");
  //       return;
  //   } else {
  //       CCLOG("DEBUGGG Agent object is not null");
  //   }

  //   jmethodID run = env->GetMethodID(cls, "init", "(Landroid/app/Activity;)V");
  //   if (NULL == run) {
  //       return;
  //   }

  //   env->CallVoidMethod(agentObject, run,activity);





		//             //t.env->CallVoidMethod(t.classID, t.methodID, activity);   
		//         //}
		// #endif
    }


    void GreedyGameAgent::initWithActivity(jobject activity2) {

    		CCLOG("DEBUGGG inside overloaded init");
			JavaVM* vm = JniHelper::getJavaVM();
			JNIEnv* env;
			vm->GetEnv((void**)&env,JNI_VERSION_1_4);

	    //     		jclass cls = t.env->GetObjectClass(GreedyGame_CLASS_NAME);
					// jmethodID method = t.env->GetMethodID(cls, "init", "(Landroid/app/Activity;)V");
					// t.env->CallVoidMethod(GreedyGame_CLASS_NAME, method);
					// CCLOG("DEBUGGG after method call");


	        jclass cls = env->FindClass(GreedyGame_CLASS_NAME);
	        if (NULL == cls) {
        		CCLOG("DEBUGGG Agent find class is null");
        		return;
    		} else {
         		CCLOG("DEBUGGG Agent find class is not null");
    		}

    jmethodID agentConstructor = env->GetMethodID(cls, "<init>", "()V");
    if (NULL == agentConstructor) {
        CCLOG("DEBUGGG Agent constructor is null");
        return;
    } else {
         CCLOG("DEBUGGG Agent constructor is not null");
    }

    jobject agentObject = env->NewObject(cls, agentConstructor);

    if (NULL == agentObject) {
        CCLOG("DEBUGGG Agent object is null");
        return;
    } else {
        CCLOG("DEBUGGG Agent object is not null");
    }

    jmethodID run = env->GetMethodID(cls, "init", "(Landroid/app/Activity;)V");
    if (NULL == run) {
        return;
    }

    env->CallVoidMethod(agentObject, run,activity2);
    }


    void GreedyGameAgent::fetchFloatUnit(const char *unit_id){
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	        cocos2d::JniMethodInfo t;
	        if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
	                                                    ,GG_SHOW_FLOAT
	                                                    ,"(Ljava/lang/String;)V"))
	        {
	            jstring StringArg1 = t.env->NewStringUTF(unit_id);
	            t.env->CallStaticVoidMethod(t.classID,t.methodID, StringArg1);
	        }
		#endif
    }

    void GreedyGameAgent::removeAllFloatUnits(){
        CCLOG("removeAllFloatUnits");
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		    cocos2d::JniMethodInfo t;
		    if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
		                                                ,GG_REMOVE_ALL_FLOAT
		                                                ,"()V"))
		    {
		        t.env->CallStaticVoidMethod(t.classID,t.methodID);
		    }
		#endif
    }

    void GreedyGameAgent::removeFloatUnit(const char *unit_id){
        CCLOG("removeFloatUnit");
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		    cocos2d::JniMethodInfo t;
		    if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
		                                                ,GG_REMOVE_FLOAT_UNIT
		                                                ,"(Ljava/lang/String;)V"))
		    {
		        jstring StringArg1 = t.env->NewStringUTF(unit_id);
		        t.env->CallStaticVoidMethod(t.classID,t.methodID,StringArg1);
		    }
		#endif
    }

    void GreedyGameAgent::forcedExit(){
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		    cocos2d::JniMethodInfo t;
		    if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
		                                                ,GG_FORCED_EXIT
		                                                ,"()V"))
		    {
		        
		        t.env->CallStaticVoidMethod(t.classID,t.methodID);
		    }
		#endif
    }

     void GreedyGameAgent::showEngagementWindow(const char *unit_id){
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		    cocos2d::JniMethodInfo t;
		    if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
		                                                ,GG_SHOW_UII
		                                                ,"(Ljava/lang/String;)V"))
		    {
		        jstring StringArg1 = t.env->NewStringUTF(unit_id);
		        t.env->CallStaticVoidMethod(t.classID,t.methodID, StringArg1);
		    }
		#endif        
    }

	std::string GreedyGameAgent::getNativeUnitPathById(const char *unit_id){
		std::string path("");
		        
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		    cocos2d::JniMethodInfo t;
		    if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
		                                                ,GG_GET_NATIVE_PATH
		                                                ,"(Ljava/lang/String;)Ljava/lang/String;"))
		    {
		        jstring StringArg1 = t.env->NewStringUTF(unit_id);
		        jstring str = (jstring) t.env->CallStaticObjectMethod(t.classID,t.methodID,StringArg1);
		        path = JniHelper::jstring2string(str);
		    }
			#endif      
		return path;  
	}

	std::string GreedyGameAgent::getFloatUnitPathById(const char *unit_id){
		std::string path("");
		        
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		    cocos2d::JniMethodInfo t;
		    if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
		                                                ,GG_GET_FLOAT_PATH
		                                                ,"(Ljava/lang/String;)Ljava/lang/String;"))
		    {
		        jstring StringArg1 = t.env->NewStringUTF(unit_id);
		        jstring str = (jstring) t.env->CallStaticObjectMethod(t.classID,t.methodID,StringArg1);
		        path = JniHelper::jstring2string(str);
		    }
		#endif      
		return path;  
    }

    void GreedyGameAgent::startEventRefresh(){
		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		    cocos2d::JniMethodInfo t;
		    if (cocos2d::JniHelper::getStaticMethodInfo(t, GreedyGame_CLASS_NAME
		                                                ,GG_REFRESH
		                                                ,"()V"))
		    {
		        
		        t.env->CallStaticVoidMethod(t.classID,t.methodID);
		    }
		#endif
    }

}
