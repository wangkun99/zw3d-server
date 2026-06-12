#include "..\inc\zw3d_serverPr.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int zw3d_serverInit()
   {
   RegisterCustomCommand();
   RegisterTemplateCommand();
   RegisterFormCommand();
   return 0;
   }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int zw3d_serverExit()
   {
   UnloadCustomCommand();
   UnloadTemplateCommand();
   UnloadFormCommand();
   return 0;
   }