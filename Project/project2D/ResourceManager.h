#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include "string.h"


template<typename T>
class ResourceManager
{
public:
	ResourceManager(){}
	~ResourceManager()
	{
		UnloadAllResources();
	}

	T* LoadResource(char* szFilename)
	{
		//Check if resource is already loaded
		//If it is, return it
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResourceList[i]->m_szFilename, szFilename) == 0)
			{
				return m_ResourceList[i]->m_pData;
			}
		}

		//Resource is not loaded, so load it
		Resource<T>* pResource = new Resource<T>(szFilename);
		m_ResourceList.PushBack(pResource);
		return pResource->m_pData;
	}

	// Delete everything
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}
		m_ResourceList.Clear();
	}

	DynamicArray<Resource<T>*> m_ResourceList;
};

