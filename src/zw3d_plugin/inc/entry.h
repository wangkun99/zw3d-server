#pragma once

#include "zwapi_cmd.h"
#include "zwapi_memory.h"
#include "zwapi_message.h"

extern "C" __declspec(dllexport) int zw3d_pluginInit(); //入口，注册时调用，需导出
extern "C" __declspec(dllexport) int zw3d_pluginExit(); //出口，卸载时调用，需导出

/* Function declaration */
int RegisterCustomCommand(void);
int UnloadCustomCommand(void);
int RegisterTemplateCommand(void);
int UnloadTemplateCommand(void);
int RegisterFormCommand(void);
int UnloadFormCommand(void);

