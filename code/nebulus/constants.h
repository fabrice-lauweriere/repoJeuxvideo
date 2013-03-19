//------- constants.h --------

/* Ce fichier contient toutes les constantes et les variables globales qui seront utilis�es dans
	le jeu */

#include "common.h"
#include "drawimage.h"
#include "shader_sh.h"

#define NUMBER_MESH 10

// constantes de taille d'�cran

const int   c_ScreenW;
const int   c_ScreenH;

// variables globales

bool  g_keys[256]; // clavier
TriangleMesh *g_Mesh[10]; // tableau des mesh des tiles �l�mentaires
int g_order[12]={9,8,7,3,6,2,5,1,4,0,0,0}; // map 
v3f g_Eye; // eye
std::map<std::string,Tex2DRGBA*> g_Textures; // textures

AutoBindShader::shader_sh g_Shader; // shader utilis�

float angle1=0, angle2;

int altitude;
unsigned int zoom;