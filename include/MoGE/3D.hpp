#pragma once
#include <MoGE/Vec.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

namespace momo {

// verts has the position
// v has the texCoords and color
struct Mesh {
  std::vector<Vec3> verts;
  sf::VertexArray v;

  void init(sf::PrimitiveType type = sf::TriangleStrip);
  void update();
  void texturizeVerts(sf::Texture &tex);
  void project3D(float thetaX, float thetaY, float thetaZ, float sw, float sh);
};

struct Mat4x4 {
  float m[4][4] = {0};

  static Mat4x4 proj(float aspectRatio, float near = 0.1f, float far = 1000.f,
                     float fov = 90.f);
  static void rotX(Mat4x4 &mat, float theta);
  static void rotY(Mat4x4 &mat, float theta);
  static void rotZ(Mat4x4 &mat, float theta);
};

void multiplyMatrixVectorW(Vec3 &i, Vec3 &o, Mat4x4 &m);

static Mesh mesh;
static Mat4x4 matProj;
static Mat4x4 matRotZ, matRotX;
static float aspectRatio = 1.777f;

}; // namespace momo
