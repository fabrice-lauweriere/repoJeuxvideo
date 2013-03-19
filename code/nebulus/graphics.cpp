// ----------------- graphics.cpp -----------------------

#include "common.h"
#include "drawimage.h"
#include "constants.h"




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

void drawTower(int etages) {
	for(int i = 0 ; i<12;i++) {
		for(int j = 0 ; j<etages;j++) {
			angle1 = i*M_PI/6;
			g_Shader.Model.set( translationMatrix(V3F(0,0,j*98.0f))*rotationMatrix(agl,V3F(0,0,1))/*rotationMatrix(agl2,V3F(0,0,1))*/);
			drawTexturedMesh( g_Mesh[g_order[i]] );
		}
	}
}


// La fonction suivante est à modifier pour utiliser un ifstream et récupérer les noms des
// tiles dans un fichier texte.

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


void mainRender()
{
	glClearColor(0.5f,0.5f,0.5f,0);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	g_Shader.begin();
	g_Shader.Proj.set( perspectiveMatrixGL((float)M_PI/4.0f, 1.0f, 5.0f, 10000.0f) );
	if(g_keys['q']) {
		angle2=angle2+M_PI/100;
	} else if(g_keys['d']) {
		angle2=angle2-M_PI/100;	
	} else if(g_keys['z']) {
		altitude+=10;
	} else if(g_keys['s']) {
		altitude-=10;
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