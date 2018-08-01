
LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)


LOCAL_MODULE    := ui


LOCAL_CFLAGS :=  $(JK3_BASE_CFLAGS) -D_UI -DNDEBUG -D_USRDL -DUI_EXPORTS -DMISSIONPACK -D_JK2 -DFINAL_BUILD
LOCAL_CPPFLAGS := $(JK3_BASE_CPPFLAGS) 

LOCAL_LDLIBS := $(JK3_BASE_LDLIBS)


#LOCAL_LDLIBS +=  -llog -lz
LOCAL_STATIC_LIBRARIES :=# s-setup  lz 
LOCAL_SHARED_LIBRARIES :=

LOCAL_C_INCLUDES :=  $(JK3_BASE_C_INCLUDES)

JK3_SRC = \
	../../${MPDir}/game/bg_misc.c \
	../../${MPDir}/game/bg_saga.c \
	../../${MPDir}/game/bg_vehicleLoad.c \
	../../${MPDir}/game/bg_weapons.c \
	../../${MPDir}/qcommon/q_math.c \
	../../${MPDir}/qcommon/q_shared.c \
	../../${MPDir}/ui/ui_atoms.c \
	../../${MPDir}/ui/ui_force.c \
	../../${MPDir}/ui/ui_gameinfo.c \
	../../${MPDir}/ui/ui_main.c \
	../../${MPDir}/ui/ui_saber.c \
	../../${MPDir}/ui/ui_shared.c \
	../../${MPDir}/ui/ui_syscalls.c \
	
	
	
LOCAL_SRC_FILES += $(JK3_SRC) 


include $(BUILD_SHARED_LIBRARY)








