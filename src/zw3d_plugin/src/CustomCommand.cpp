#include "entry.h"
#include "Importer.h"

static int PrintString(char* string);

int RegisterCustomCommand(void)
/*
DESCRIPTION:
   Register custom command.
*/
   {
   /* Start the command by entering command string "~PrintString(Hello ZW3D API)" */
   //cvxCmdFunc("PrintString", (void*)PrintString, VX_CODE_GENERAL);
	ZwCommandFunctionLoad("PrintString", (void*)PrintString, ZW_LICENSE_CODE_GENERAL);

	ZwCommandFunctionLoad("import", (void*)insertZwComponent, ZW_LICENSE_CODE_GENERAL);

	ZwCommandFunctionLoad("trans", (void*)transStepToZ3, ZW_LICENSE_CODE_GENERAL);
   return 0;
   }

int UnloadCustomCommand(void)
/*
DESCRIPTION:
   Unload custom command.
*/
   {
	ZwCommandFunctionUnload("PrintString");
	ZwCommandFunctionUnload("import");
	ZwCommandFunctionUnload("trans");
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

