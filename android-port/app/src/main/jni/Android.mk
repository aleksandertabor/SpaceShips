LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sfml-spaceships

FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES := main.cpp

LOCAL_SHARED_LIBRARIES := sfml-system-d
LOCAL_SHARED_LIBRARIES += sfml-window-d
LOCAL_SHARED_LIBRARIES += sfml-graphics-d
LOCAL_SHARED_LIBRARIES += sfml-audio-d
LOCAL_SHARED_LIBRARIES += sfml-network-d
LOCAL_SHARED_LIBRARIES += sfml-activity-d
LOCAL_SHARED_LIBRARIES += openal
LOCAL_WHOLE_STATIC_LIBRARIES := sfml-main-d
LOCAL_CFLAGS := -std=c++17
LOCAL_CFLAGS += -lstdc++fs

include $(BUILD_SHARED_LIBRARY)

$(call import-module,third_party/sfml)
