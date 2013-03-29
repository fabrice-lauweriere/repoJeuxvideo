//------- constants.h --------

/* Ce fichier contient toutes les constantes et les variables globales qui seront utilis�es dans
le jeu */
#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "drawimage.h"
#include "shader_sh.h"
#endif

#define NUMBER_MESH 10

	// constantes de taille d'écran

	extern int   c_ScreenW;
	extern int   c_ScreenH;

	// variables globales
	
	extern bool  g_keys[256]; // clavier

	extern int g_order[12]; // map 
	
	extern TriangleMesh *g_Mesh[10]; // tableau des mesh des tiles élémentaires

	extern v3f g_Eye; // eye
	extern std::map<std::string,Tex2DRGBA*> g_Textures; // textures

	extern AutoBindShader::shader_sh g_Shader; // shader utilisé
	
	extern float angle1;
	extern float angle2;

	extern int altitude;
	extern unsigned int zoom;

