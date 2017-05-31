LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := native-lib.cpp

LOCAL_LDFLAGS := -L$(SYSROOT)/usr/lib/ -llog

LOCAL_MODULE = native-lib

include $(BUILD_SHARED_LIBRARY)