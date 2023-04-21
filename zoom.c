#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	int i, j, r;

	/*
		Moral disso aqui,
		o método read_ppm retorna 0 caso a leitura da foto tinha sido feita com sucesso,
		caso contrário ele retorna -1.
		Por isso ele faz aquele if (r == 0) logo abaixo
	*/ 
	r = read_ppm("lena.ppm", image);

	/*
		tipo, todos os dados da imagem lida ficarão nesse "Objeto" / Struct image,
		ai temos:

		image->width = valor inteiro
		image->height = valor inteiro

		image->pix[POS].r = retorna o valor R do código RGB do pixel na posição "POS"
		image->pix[POS].g = retorna o valor G do código RGB do pixel na posição "POS"
		image->pix[POS].b = retorna o valor B do código RGB do pixel na posição "POS"

		Sor cantou a pedra para ler e percorrer todos os pixeis da imagem,

		assumindo que essa linha esteja dentro de dois "for()" para ler a matriz
		image->[j * image->width + i].r

		outro exemplo, sabemos q a imagem do sor tem 512px por 512px,
		se quisermos acessar o código rgb do exato último pixel, temos:

		printf("RGB (%hu , %hu , %hu)\n",image->pix[511 *image->width + 511].r , image->pix[511 * image->width +511].g , image->pix[511 * image->width +511].b);

		OBS: o jeito de 'printar' esses valores RGB no console é usando '%hu', pq não são inteiros, são uma espécie de 'char'

	*/


	if (r == 0)
	{
		printf("width: %d, height: %d\n", image->width, image->height);

		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
				printf("(%d %d) %02x %02x %02x\n", i, j,
					   image->pix[j * image->width + i].r,
					   image->pix[j * image->width + i].g,
					   image->pix[j * image->width + i].b);
			}
		}
		// No fucking ideia do q isso faz
		image->pix[50 * image->width + 20].r = 255 ;
		image->pix[50 * image->width + 20].g = 255 ;
		image->pix[50 * image->width + 20].b = 255 ;


		printf("COR DO ULTIMO PIXEL \n");
		printf("RGB (%hu , %hu , %hu)\n",image->pix[511 *image->width + 511].r , image->pix[511 * image->width +511].g , image->pix[511 * image->width +511].b);
		write_ppm("lena_copy.ppm", image);

		free_ppm(image);
	}

	// Exemplo da criação de uma nova imagem ppm.
	// Totalmente preta com apenas alguns pontos coloridos
	r = new_ppm(image, 675, 428);

	if (r == 0)
	{
		image->pix[100 * image->width + 125].r = 255;
		image->pix[27 * image->width + 440].g = 255;

		image->pix[371 * image->width + 10].r = 192;
		image->pix[371 * image->width + 10].g = 192;
		image->pix[371 * image->width + 10].b = 192;

		write_ppm("test.ppm", image);
		free_ppm(image);
	}

	return 0;
}
