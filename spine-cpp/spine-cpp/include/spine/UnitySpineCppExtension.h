#pragma  once
#include <spine/spine.h>

namespace spine {
	class UnitySpineCppTextureLoader : spine::TextureLoader {
	public:
		UnitySpineCppTextureLoader() {}

		virtual ~UnitySpineCppTextureLoader() {}

		void setLoadFuncPtr(void* ptr);

		void setUnloadFuncPtr(void* ptr);

		void load(spine::AtlasPage& page, const spine::String& path) override;

		void unload(void* texture) override;

		void* loadFuncPtr = nullptr;

		void* unloadFuncPtr = nullptr;
	};
}
