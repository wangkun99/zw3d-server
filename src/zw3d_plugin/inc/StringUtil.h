#pragma once

#include "entry.h"

void getDirAndBaseName(
	const char* filePath,
	vxLongPath& outDir,
	vxLongPath& outBaseName);
bool createDirectory(const char* path);