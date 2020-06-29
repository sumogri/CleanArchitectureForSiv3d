#pragma once

#include "IViewModel.h"

#include <functional>

#include <Siv3D/Array.hpp>
#include <Siv3D/HashTable.hpp>
#include <Siv3D/DirectoryWatcher.hpp>
#include <Siv3D/FileSystem.hpp>

class DirectoryWatchViewModel : public IViewModel {
public:
	void SetWatchingDirectory(const s3d::FilePath& fullDirectoryName);
	void OnUpdate();
	void AddOnModified(const s3d::FilePath& fullFileName, std::function<void()> handler);
	void AddOnAdded(const s3d::FilePath& fullFileName, std::function<void()> handler);
private:
	void OnModified(const s3d::FilePath& fullFileName);
	void OnAdded(const s3d::FilePath& fullFileName);
	s3d::DirectoryWatcher m_directorWathcer;
	s3d::HashTable<s3d::FilePath, s3d::Array<std::function<void()>>> m_onModified;
	s3d::HashTable<s3d::FilePath, s3d::Array<std::function<void()>>> m_onAdd;
};