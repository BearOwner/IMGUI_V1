#ifndef META_SPACE_IMGUI_IMAGE_H
#define META_SPACE_IMGUI_IMAGE_H

#include "imgui.h"

struct TextureInfo {
    ImTextureID textureId;
    int width;
    int height;
    int x;
    int y;
    int w;
    int h;
};
TextureInfo createTexture(char *ImagePath);
TextureInfo ImAgeHeadFile(const unsigned char *buf, int len);
TextureInfo createTexturePNGFromMem(const unsigned char *buf,int len);
ImTextureID ImAgeHeadFile2(const unsigned char *buf, int len);


#endif //META_SPACE_IMGUI_IMAGE_H
