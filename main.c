#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMTATION
#include "stb_image/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMTATION
#include "stb_image/stb_image_resize.h"

//Task: Resize, then grayscale!!
//  gcc -std=c17 -Wall foo.c -o bar -lm

int main(int argc, char **argv)
{
   char Chars[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";

   int charslen = strlen(Chars);

   int width, height;//, channels;
   unsigned char *ImageData = stbi_load(argv[1], &width, &height, NULL, STBI_grey); // load the image and store to pointer
                                                                               // pxSize = channels
   // Standard parameters, from the stbi_load funtion:
   //    int *x       -- outputs image width in pixels
   //    int *y       -- outputs image height in pixels
   //    int *comp    -- outputs # of image components in image file
   //    int req_comp -- if non-zero, # of image components requested in result


   // argv will be used to parse the input file to load function



   char resize_image;
   printf("resize the image?: ");
   scanf("%c", &resize_image);
   int new_width;
   int new_height;




   new_width = width / 2;
   new_height = height / (width / (float)new_width);
   stbir_resize_uint8(ImageData, width, height, width, ImageData, new_width, new_height, new_width, STBI_grey);

   if (ImageData != NULL) // if we have image content
   {
      //se tiver mal escrever o printf aq.
      printf("Width: %d, Height: %d, pixels: %dpx\n", width, height); //print out the contents of file 

      unsigned char *Pixels = ImageData;//store data into an aux pointer called "Pixels"

      // initializing the rezise process.
      // int new_width; 
      // int new_height;
      // int new_channels;
      // unsigned char *Rezise_data;

      // stbir_resize_uint8(ImageData, width, height, channels, Rezise_data, new_width, new_height, new_channels, 4);
      // //stride as i struggle to get what it is is the number of bytes from one row of pixels in mem. to next row of pixels in memory lul

      // stbi_write_png("furina_resize.png", new_width, new_height, new_channels, Rezise_data, channels);

      // doing a resize process
      // if (resize_image == 'y')
      // {
      // new_width = width / 2;
      // new_height = height / (width / (float)new_width);
      // stbir_resize_uint8(ImageData, width, height, width, ImageData, new_width, new_height, new_width, STBI_grey);
      // }
      // else
      // {
      //    new_width = width;
      //    new_height = height;
      // }

      // o loop pode parecer diferente um bcd do de quando temos para fazer a arvore,
      //  contudo o modo a que corre sera diferente sendo que j nao é menor que i

      for (int i = 0; i < height; i++) //height = comprimento, ou coluna
      {
         for (int j = 0; j < width; j++) //width = largura, ou linha
         { // Se tiver dentro dos canais RGB, os pixeis irao excrever entre as cores RGB
         //como observado na net os pixeis RGB têm três canais onde vão escrever: https://medium.com/featurepreneur/understanding-the-concept-of-channels-in-an-image-6d59d4dafaa9
            unsigned char R = *Pixels++;
            unsigned char G = *Pixels++;
            unsigned char B = *Pixels++;
            // if (channels >= 4) // se houver tamanho dos canais maior que 4.
            // {
            //    unsigned char A = *Pixels++; //adicionar valor no prox canal 
            // }

            // write to console and place accordingly all charaters
            float avg = (R + G + B) / 3.0f;
            int CharIndex = (int)(charslen * (avg / 255.0f));
            putchar(Chars[CharIndex]);//write ascii charaters to console
         }
         printf("\n");
      }
   }
   else
      printf("Image not found, or error loading it");
   stbi_image_free(ImageData);
   return 0;
}