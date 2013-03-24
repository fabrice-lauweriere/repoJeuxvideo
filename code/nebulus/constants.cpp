//--------------- constants.cpp ------------------

#include "common.h"
#include "drawimage.h"
#include "shader_sh.h"
#include "constants.h"



	// constantes de taille d'écran

	int   c_ScreenW;
	int   c_ScreenH;

	// variables globales

	bool  g_keys[256]; // clavier

	int g_order[12]={9,8,7,3,6,2,5,1,4,0,0,0}; // map 

	TriangleMesh *g_Mesh[10]; // tableau des mesh des tiles élémentaires

	v3f g_Eye; // eye
	std::map<std::string,Tex2DRGBA*> g_Textures; // textures

	AutoBindShader::shader_sh g_Shader; // shader utilisé
	
	float angle1;
	float angle2;

	int altitude;
	unsigned int zoom;
