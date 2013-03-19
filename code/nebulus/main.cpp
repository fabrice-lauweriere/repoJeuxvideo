// ----------------- main.cpp -----------------------

// ------------------------------------------------------------------

#include "common.h"
#include "drawimage.h"


#define NUMBER_MESH 10
// ------------------------------------------------------------------

// Constants
const int   c_ScreenW      = 800;
const int   c_ScreenH      = 800;


bool  g_keys[256];
TriangleMesh *g_Mesh[10];
int g_order[12]={9,8,7,3,6,2,5,1,4,0,0,0};
v3f g_Eye;
std::map<std::string,Tex2DRGBA*> g_Textures;
// ------------------------------------------------------------------

#include "shader_sh.h"
AutoBindShader::shader_sh g_Shader;

// ------------------------------------------------------------------

// 'mainKeyPressed' is called everytime a key is pressed
void mainKeyPressed(uchar key)
{
	g_keys[key]=1;
}

// ------------------------------------------------------------------

// 'mainKeyUnpressed' is called everytime a key is released
void mainKeyUnpressed(uchar key)
{
	g_keys[key]=0;
}

// ------------------------------------------------------------------

void drawMesh(TriangleMesh *mesh)
{
	glBegin(GL_TRIANGLES);
	ForIndex(t,mesh->numTriangles()) {
		v3u tri = mesh->triangleAt(t);
		ForIndex(v,3) {
			VertexData *vertex = (VertexData*)mesh->vertexDataAt(tri[v]);
			glNormal3fv( &vertex->nrm[0] );
			glVertex3fv( &vertex->pos[0] );
		}
	}
	glEnd();
}

// ------------------------------------------------------------------

void drawTexturedMesh(TriangleMesh *mesh)
{
  ForIndex(s,mesh->numSurfaces()) {
    glBindTexture(GL_TEXTURE_2D, g_Textures[mesh->surfaceTextureName(s)]->handle());
    glBegin(GL_TRIANGLES);
    ForIndex(i,mesh->surfaceNumTriangles(s)) {
      int t   = mesh->surfaceTriangleIdAt(s,i);
      v3u tri = mesh->triangleAt(t);
      ForIndex(v,3) {
        VertexData *vertex = (VertexData*)mesh->vertexDataAt(tri[v]);
        glTexCoord2fv( &vertex->uv[0]  );
        glNormal3fv  ( &vertex->nrm[0] );
        glVertex3fv  ( &vertex->pos[0] );
      }
    }
    glEnd();
  }
}


// ------------------------------------------------------------------

void loadMeshes() {
	std::stringstream filename;
	
	for(int i=0;i<NUMBER_MESH;i++) {
		if(i==9) {
			filename.str("");
			filename << sourcePath() << "/data/tile"<<9<<".dae";
			g_Mesh[i] = loadTriangleMesh( filename.str().c_str() );
		} else {
			filename.str("");
			filename << sourcePath() << "/data/tile"<<i<<".dae";
			g_Mesh[i] = loadTriangleMesh( filename.str().c_str() );
		}
	}
}

float agl = 0;
float agl2 = 0;

void drawTower(int etages) {
	for(int i = 0 ; i<12;i++) {
		for(int j = 0 ; j<etages;j++) {
			agl = i*M_PI/6;
			g_Shader.Model.set( translationMatrix(V3F(0,0,j*98.0f))*rotationMatrix(agl,V3F(0,0,1))/*rotationMatrix(agl2,V3F(0,0,1))*/);
			drawTexturedMesh( g_Mesh[g_order[i]] );
		}
	}
}



// ------------------------------------------------------------------

int var = 0;
unsigned int zoom = 500;

// 'mainRender' is called everytime the screen is drawn
void mainRender()
{
	glClearColor(0.5f,0.5f,0.5f,0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	g_Shader.begin();
	g_Shader.Proj.set( perspectiveMatrixGL((float)M_PI/4.0f, 1.0f, 5.0f, 10000.0f) );
	if(g_keys['q']) {
		agl2=agl2+M_PI/100;
	} else if(g_keys['d']) {
		agl2=agl2-M_PI/100;	
	} else if(g_keys['z']) {
		var+=10;
	} else if(g_keys['s']) {
		var-=10;
	} else if(g_keys['+']) {
		zoom += 10;
	} else if(g_keys['-']) {
		if(zoom - 10 >0)  {
			zoom-=10;
		}
	}
	g_Eye = V3F(zoom*cos(agl2),zoom*sin(agl2),var);
	g_Shader.View.set( lookatMatrix(V3F(zoom*cos(agl2),zoom*sin(agl2),var),V3F(0,0,var), V3F(0,0,1) ));
	g_Shader.u_Eye.set(g_Eye);
	g_Shader.u_LightPos.set(V3F(zoom*cos(agl2+M_PI/3),zoom*sin(agl2+M_PI/3),var));


	drawTower(10);
	g_Shader.end();
}

// ------------------------------------------------------------------

// 'main' is the starting point of the application
int main(int argc,const char **argv)
{
	try { // error handling

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
					texturePath << sourcePath() << "/data/" << g_Mesh[u]->surfaceTextureName(s);
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
	}

	return 0;
}

// ------------------------------------------------------------------
