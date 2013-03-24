// ----------------- main.cpp -----------------------


#include "controls.h"
//#include "graphics.h"
//#include "common.h"


void initConstants() {
	angle1    = 0;
	angle2    = 0;
	altitude  = 0;
	zoom      = 0;
    c_ScreenH = 800;
	c_ScreenW = 800;
}

// 'main' is the starting point of the application
int main(int argc,const char **argv)
{
	initConstants();
	std::cout << c_ScreenW  <<std::endl;
	/*try { // error handling

		// opens a window
		SimpleUI::init(c_ScreenW,c_ScreenH,"Basic framework");
		// set the render function to be 'mainRender' defined above
		SimpleUI::onRender       = mainRender;
		// set the keyboard function
		SimpleUI::onKeyPressed   = mainKeyPressed;
		SimpleUI::onKeyUnpressed = mainKeyUnpressed;

		// init 
		// -> drawimage
		drawimage_init(c_ScreenW,c_ScreenH);
		g_Shader.init();
		std::stringstream texturePath;
	
	
		
		loadMeshes();
		for(int u = 0;u<NUMBER_MESH;u++) {
		//int u = 0;	
		//std::cerr << "u = " << u <<std::endl;
			ForIndex(s,g_Mesh[u]->numSurfaces()) {
			//	std::cerr << "s = "<<s <<std::endl;
				
				if(g_Textures.find(g_Mesh[u]->surfaceTextureName(s))==g_Textures.end()) {
					//std::cerr << g_Mesh[u]->surfaceTextureName(s) ;
					//std::cerr << "!!! loading !!!"<< std::endl;
					texturePath.str("");
					texturePath << sourcePath() << "/tiles/" << g_Mesh[u]->surfaceTextureName(s);
					//std::cerr << texturePath.str() <<std::endl;
					ImageRGBA *img = loadImageRGBA(texturePath.str().c_str());
					g_Textures[g_Mesh[u]->surfaceTextureName(s)]= new Tex2DRGBA(img->pixels());
					delete(img);
				
			}
		}
		}
		//for(int i = 0 ;i < g_Mesh->numVertices();i++) {
			//g_Mesh->posAt(i) = g_Mesh->posAt(i)*25.4f;
		//}


		// enter the main loop
		SimpleUI::loop();

		// terminate
		// -> drawimage
		drawimage_terminate();
		g_Shader.terminate();
		// -> close the window
		SimpleUI::shutdown();

	} catch (Fatal& f) { // error handling
		std::cerr << Console::red << f.message() << Console::gray << std::endl;
	}*/
	return 0;
}

// ------------------------------------------------------------------
