#include <spine/Extension.h>
#include <spine/TextureLoader.h>

spine::SpineExtension* spine::getDefaultExtension() {
	return new spine::DefaultSpineExtension();
}

class MyTextureLoader : public spine::TextureLoader
{
	virtual void load(spine::AtlasPage& page, const spine::String& path) {
		//void* texture = ... load the texture based on path ...
		//	page->setRendererObject(texture); // use the texture later in your rendering code
	}

	virtual void unload(void* texture) { // TODO }
	};
};