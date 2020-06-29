#include "DirectoryWatchViewModel.h"

void DirectoryWatchViewModel::SetWatchingDirectory(const s3d::FilePath& fullDirectoryName)
{
	m_directorWathcer = s3d::DirectoryWatcher(fullDirectoryName);
}

void DirectoryWatchViewModel::OnUpdate() 
{
	for (const auto& change : m_directorWathcer.retrieveChanges()) 
	{
		switch (change.second)
		{
		case s3d::FileAction::Added:
			OnAdded(change.first);
			break;
		case s3d::FileAction::Modified:
			break;
		}
	}
}

void DirectoryWatchViewModel::AddOnModified(const s3d::FilePath& fullFileName, std::function<void()> handler)
{
	m_onModified[fullFileName].push_back(handler);
}

void DirectoryWatchViewModel::OnModified(const s3d::FilePath& fullFileName)
{
	for (auto f : m_onModified[fullFileName])
	{
		f();
	}
}

void DirectoryWatchViewModel::AddOnAdded(const s3d::FilePath& fullFileName, std::function<void()> handler)
{
	m_onAdd[fullFileName].push_back(handler);
}

void DirectoryWatchViewModel::OnAdded(const s3d::FilePath& fullFileName)
{
	for (auto f : m_onAdd[fullFileName]) 
	{
		f();
	}
}