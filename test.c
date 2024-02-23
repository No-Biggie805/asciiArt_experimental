#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
int main(int argc, char **argv)
{
    const char *inputFile = argv[1];
    // const char *outputFile = argv[2];
    int x, y, n_components;
    unsigned char *data = stbi_load(inputFile, &x, &y, &n_components, 0); // This should force just one (gray) component per pixel.

    // note:
    // If req_comp is non-zero!!!, *comp has the number of COMPONENTS that would
    // have been output otherwise. E.g. if you set req_comp to 4, you will always
    // get RGBA output, but you can check *comp to easily see if it's opaque.

    if (!data)
    {
        fprintf(stderr, "Couldn't load image.\n");
        return (-1);
    }

    printf("%d\n", n_components); // this image has an RGBA channeling by default, so it will allways print 4, if more than 4 it fails to load.

    stbi_image_free(data);
    return 0;
}
