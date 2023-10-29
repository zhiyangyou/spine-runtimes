#include <spine/UnitySpineCppExtension.h>

namespace spine {
	typedef void (*loadFuncType)(void*, void*);
	typedef void (*unloadFuncType)(void*);
	void UnitySpineCppTextureLoader::setLoadFuncPtr(void* ptr)
	{
		this->loadFuncPtr = ptr;
	}

	void UnitySpineCppTextureLoader::setUnloadFuncPtr(void* ptr)
	{
		this->unloadFuncPtr = ptr;
	}

	void UnitySpineCppTextureLoader::load(spine::AtlasPage& page, const spine::String& path)
	{
		spine::AtlasPage* pPage = &page;
		spine::String* pPath = &const_cast<spine::String&>(path);
		((loadFuncType)(loadFuncPtr))(pPage, pPath);
	}

	void UnitySpineCppTextureLoader::unload(void* texture)
	{
		((unloadFuncType)(unloadFuncPtr))(texture);
	}
}


