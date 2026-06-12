#include "..\inc\zw3d_serverPr.h"

static int HelloZW3DApi(void);
static int PrintString(char* string);

int RegisterCustomCommand(void)
/*
DESCRIPTION:
   Register custom command.
*/
   {
   /* Start the command by entering command string "~HelloZW3DApi" */
   cvxCmdFunc("HelloZW3DApi", (void*)HelloZW3DApi, VX_CODE_GENERAL);

   /* Start the command by entering command string "~PrintString(Hello ZW3D API)" */
   cvxCmdFunc("PrintString", (void*)PrintString, VX_CODE_GENERAL);
   return 0;
   }

int UnloadCustomCommand(void)
/*
DESCRIPTION:
   Unload custom command.
*/
   {
   cvxCmdFuncUnload("HelloZW3DApi");
   cvxCmdFuncUnload("PrintString");
   return 0;
   }

int HelloZW3DApi(void)
/*
DESCRIPTION:
   Custom command.
*/
   {
   // TODO: Do something

   cvxMsgDisp("Hello ZW3D API");
   return 0;
   }

int PrintString
(
   char* string    /* I: input string */
)
/*
DESCRIPTION:
   Custom command.
*/
   {
   // TODO: Do something

   cvxMsgDisp(string);
   return 0;
   }

