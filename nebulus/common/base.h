#pragma once

#include "base.h"

#include <LibSL/LibSL.h>
#include <LibSL/LibSL_gl.h>

typedef MeshFormat_dae::t_VertexFormat                            VertexFormat;
typedef MeshFormat_dae::t_VertexData                              VertexData;

typedef GPUMesh::GPUMesh_VertexBuffer<VertexFormat>               VertexBuffer;
typedef GPUMesh::GPUMesh_Indexed_VertexBuffer<VertexFormat,uint>  IndexedVertexBuffer;

ImageRGBA  *loadImageRGBA(const char *fname);
m4x4f       rotationMatrix(float angle,const v3f& axis);

std::string executablePath();
std::string sourcePath();
