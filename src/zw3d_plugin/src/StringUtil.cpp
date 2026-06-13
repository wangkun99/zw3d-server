#define _CRT_SECURE_NO_WARNINGS

#include "stringutil.h"
#include <string>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#include <unistd.h>
#define MKDIR(path) mkdir(path, 0755)
#endif
#ifndef S_ISDIR
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif

void getDirAndBaseName(
	const char* filePath,
	vxLongPath& outDir,
	vxLongPath& outBaseName)
{
	outDir[0] = '\0';
	outBaseName[0] = '\0';

	if (!filePath || !*filePath)
		return;

	std::string path(filePath);
	auto pos = path.find_last_of("/\\");

	std::string dir;
	std::string file;

	if (pos != std::string::npos) {
		dir = path.substr(0, pos + 1);
		file = path.substr(pos + 1);
	}
	else {
		dir = "./";
		file = path;
	}

	// È¥µô .step ºó×º
	if (file.size() > 5 && file.substr(file.size() - 5) == ".step") {
		file.erase(file.size() - 5);
	}

	snprintf(outDir, sizeof(vxLongPath), "%s", dir.c_str());
	snprintf(outBaseName, sizeof(vxLongPath), "%s", file.c_str());
}

bool createDirectory(const char* path)
{
	if (!path || !*path)
		return false;

	struct stat st {};
	if (stat(path, &st) == 0)
		return S_ISDIR(st.st_mode);

#ifdef _WIN32
	return _mkdir(path) == 0;
#else
	return mkdir(path, 0755) == 0;
#endif
}
