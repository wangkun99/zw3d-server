#include "pch.h"
#include "entry.h"
#include "StringUtil.h"

// 假设已知：装配体句柄 hAssembly，零件文件路径 partFilePath
void insertZwComponent(const char* partFilePath)
{
	// 1. 初始化插入数据结构
	szwComponentInsertData data = { 0 };
	ZF_CALL(ZwComponentInsertInit(&data));
	WriteMessage("初始化插入数据结构完成");

	// 3. 设置插入的零件来源（文件路径）
	strcpy_s(data.pathFile, "D:\\WorkStation\\resources\\sancengzhuangpei.stp");
	WriteMessage("插入组件的文件路径成功:[%s]", data.pathFile);

	// 4. 设置组件的矩阵
	//strcpy_s(data.root, "sancengzhuangpei"); //待插入的根对象，对于单根文件，root就是文件名去后缀
	szwMatrix componentLocation = {};
	ZwMatrixInitByTranslation(200, 200, 0, &componentLocation); //设置组件的矩阵，决定了组件摆放位置
	data.frame = &componentLocation;
	//data.instanceData;对应插入组件功能面板中的“实例”，可选输入
	//data.settingsData; 对应插入组件功能面板中的“设置”，可选输入
	//data.alignFaceDatumHandle;设置对齐对象，如对齐面
	//data.anchor;设置是否固定组件
	//data.configName;设置组件使用的配置表

	// 4. 调用函数插入组件
	szwEntityHandle componentHandle = {};
	ZF_CALL(ZwComponentInsert(data, NULL, &componentHandle));
	ZF_CALL(ZwEntityHandleFree(&componentHandle));
}

void importStep(const char* filePath, int importTo)
{
	svxImportSTEPData stepData = { 0 };
	svxImportData importData{};
	ZF_CALL(cvxFileImportInit(&importData, evxImportType::VX_IMPORT_TYPE_STEP, &stepData));
	stepData.isAutoSew = 1; // 自动缝合几何体
	stepData.isActivatePart = 1; // 自动激活零件
	stepData.isSubPart = 0; // 不自动创建子零件
	stepData.isTrimEdges = 1; // 打断修建边
	stepData.isForceClose = 0; // 不强制闭合
	stepData.isSewParts = 0; // 不缝合每个零件
	stepData.isKeepDire = 0; // 不保持原始面方向
	stepData.isHiddenEnts = 0; // 不读取隐藏实体

	//strcpy_s(importData.filePath, filePath); // 设置stp文件路径
	strcpy_s(importData.filePath, "D:\\WorkStation\\resources\\z3Files\\sancengzhuangpei\\sancengzhuangpei.stp"); // 设置stp文件路径
	importData.type = evxImportType::VX_IMPORT_TYPE_STEP;
	importData.importTo = importTo; // 0-当前对象, 1-新对象, 2-新文件
	ZF_CALL(cvxFileImport(&importData));
}

// 导出文件
int FileSaveAs(const vxLongPath outDir, const vxLongPath outBaseName) {
	/*** 保存文件。 */
	//int iRet = cvxFileSave3(1, 1, 1);
	WriteMessage("导出路径为:");
	WriteMessage(outDir);
	int count = 0;
	vxLongPath* fileList = NULL;
	cvxFileOpenListByLongPath(&count, &fileList);
	int iRet = cvxFilesSaveToByLongPath(count, fileList, outDir);
	//int iRet = cvxFileSaveAs(outDir);
	if (iRet)
	{
		cvxMsgDisp("保存失败。");
		return iRet;
	}
	//cvxFileClose();
}

void transStepToZ3(const char* filePath)
{
	importStep(filePath, 2);
	//vxLongPath result;
	//removeStepSuffix(filePath, result);
	vxLongPath outDir;
	vxLongPath outBaseName;
	getDirAndBaseName("D:\\WorkStation\\resources\\z3Files\\sancengzhuangpei\\sancengzhuangpei.stp", outDir, outBaseName);
	//removeStepSuffix("D:\\WorkStation\\resources\\z3Files\\sancengzhuangpei\\sancengzhuangpei.z3asm", result);
	FileSaveAs(outDir, outBaseName);
}

