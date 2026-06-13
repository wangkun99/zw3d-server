#include "entry.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int zw3d_pluginInit()
   {
   RegisterCustomCommand();
   RegisterTemplateCommand();
   RegisterFormCommand();
   return 0;
   }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int zw3d_pluginExit()
   {
   UnloadCustomCommand();
   UnloadTemplateCommand();
   UnloadFormCommand();
   return 0;
   }