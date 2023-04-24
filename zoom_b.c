#include <stdio.h>
#include "lib_ppm.h"

// All black = 1
// Middle the same, rest black = 2
// Middle black, rest the same = 3
// all respective color = 4

int check_padrao(int cor)
{
  if (cor <= 74)
    return 1;
  if (cor <= 134)
    return 2;
  if (cor <= 179)
    return 3;
  return 4;
}

int main()
{
  struct image_s data;
  struct image_s *image = &data;
  struct image_s data_new_image;
  struct image_s *new_image = &data_new_image;
  int i, j, r;

  r = read_ppm("lena.ppm", image);
  int is_new_ok = new_ppm(new_image, image->width * 3, image->height * 3);

  if (r == 0 && is_new_ok == 0)
  {
    printf("width: %d, height: %d\n", image->width, image->height);
    for (j = 0; j < image->height; j++)
    {
      // Para j 0
      //
      // Criar j0, j0+1, j0+2
      for (i = 0; i < image->width; i++)
      {
        // All black = 1
        // Middle the same, rest black = 2
        // Middle black, rest the same = 3
        // all respective color = 4

        int padrao_r = check_padrao(image->pix[j * image->width + i].r);
        int padrao_g = check_padrao(image->pix[j * image->width + i].g);
        int padrao_b = check_padrao(image->pix[j * image->width + i].b);
        if (padrao_r == 1)
        {
          // All black = 1
          // Middle the same, rest black = 2
          // Middle black, rest the same = 3
          // all respective color = 4

          // PRIMEIRA COLUNA
          new_image->pix[j * 3 * new_image->width + (3 * i)].r = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i)].g = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i)].b = 0;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].r = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].g = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].b = 0;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].r = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].g = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].b = 0;
        }
        else if (padrao_r == 2)
        {
          // PRIMEIRA COLUNA
          new_image->pix[j * 3 * new_image->width + (3 * i)].r = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i)].g = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i)].b = 0;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].r = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].g = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].b = 0;
        }
        else if (padrao_r == 3)
        {
          // PRIMEIRA COLUNA
          new_image->pix[j * 3 * new_image->width + (3 * i)].r = image->pix[j * image->width + i].r;
          new_image->pix[j * 3 * new_image->width + (3 * i)].g = image->pix[j * image->width + i].g;
          new_image->pix[j * 3 * new_image->width + (3 * i)].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].r = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].g = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].b = 0;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].b = image->pix[j * image->width + i].b;
        }
        else if (padrao_r == 4)
        {
          // PRIMEIRA COLUNA
          new_image->pix[j * 3 * new_image->width + (3 * i)].r = image->pix[j * image->width + i].r;
          new_image->pix[j * 3 * new_image->width + (3 * i)].g = image->pix[j * image->width + i].g;
          new_image->pix[j * 3 * new_image->width + (3 * i)].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i)].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i)].b = image->pix[j * image->width + i].b;
        }
        if (padrao_g == 1)
        {
          // SEGUNDA COLUNA
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].r = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].g = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].b = 0;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].r = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].g = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].b = 0;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].r = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].g = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].b = 0;
        }
        else if (padrao_g == 2)
        {
          // SEGUNDA COLUNA
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].r = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].g = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].b = 0;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].r = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].g = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].b = 0;
        }
        else if (padrao_g == 3)
        {
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].r = image->pix[j * image->width + i].r;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].g = image->pix[j * image->width + i].g;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].r = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].g = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].b = 0;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].b = image->pix[j * image->width + i].b;
        }
        else if (padrao_g == 4)
        {
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].r = image->pix[j * image->width + i].r;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].g = image->pix[j * image->width + i].g;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 1].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 1].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 1].b = image->pix[j * image->width + i].b;
        }
        if (padrao_b == 1)
        {
          // TERCEIRA COLUNA

          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].r = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].g = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].b = 0;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].r = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].g = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].b = 0;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].r = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].g = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].b = 0;
        }
        else if (padrao_b == 2)
        {
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].r = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].g = 0;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].b = 0;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].r = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].g = 0;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].b = 0;
        }
        else if (padrao_b == 3)
        {
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].r = image->pix[j * image->width + i].r;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].g = image->pix[j * image->width + i].g;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].r = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].g = 0;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].b = 0;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].b = image->pix[j * image->width + i].b;
        }
        else if (padrao_b == 4)
        {
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].r = image->pix[j * image->width + i].r;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].g = image->pix[j * image->width + i].g;
          new_image->pix[j * 3 * new_image->width + (3 * i) + 2].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 1) * new_image->width + (3 * i) + 2].b = image->pix[j * image->width + i].b;

          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].r = image->pix[j * image->width + i].r;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].g = image->pix[j * image->width + i].g;
          new_image->pix[(j * 3 + 2) * new_image->width + (3 * i) + 2].b = image->pix[j * image->width + i].b;
        }
      }
    }

    free_ppm(image);

    write_ppm("nicolodi.ppm", new_image);
    free_ppm(new_image);
  }

  return 0;
}
