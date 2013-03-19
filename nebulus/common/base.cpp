// Sylvain.Lefebvre@inria.fr  2012-04-10
// ------------------------------------------------------------------

#include "base.h"

// ------------------------------------------------------------------

ImageRGBA *loadImageRGBA(const char *fname)
{
  ImageRGBA *img = NULL;

  try {
    img = loadImage<ImageRGBA>( fname );
  } catch (Fatal& ) {
    try {
      img = loadImage<ImageRGB>( fname )->cast<ImageRGBA>();
    } catch (Fatal& f) {
      std::cerr << Console::red << f.message() << Console::gray << std::endl;
      exit (-1);
    }
  }
  return img;

}

// ------------------------------------------------------------------

m4x4f      rotationMatrix(float angle,const v3f& axis)
{
  return quatf(axis,angle).toMatrix();
}

// ------------------------------------------------------------------

std::string executablePath()
{
  return std::string(System::Application::executablePath());
}

// ------------------------------------------------------------------

std::string sourcePath()
{
  return std::string(DATA_PATH);
}

// ------------------------------------------------------------------

