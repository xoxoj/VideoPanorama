#ifndef VIDEO_PANORAMA_MATCHER_PAINTER_HPP
#define VIDEO_PANORAMA_MATCHER_PAINTER_HPP

#include <mutex>

#include <opencv2/core/core.hpp>

#if TARGET_DACUDAS_LINUX_BUILD_SERVER_PLEASE_RENAME
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#else
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>
#endif

class Painter {

public:
  Painter();
  ~Painter();

  // Set new images
  void updateImage1(cv::Mat image);
  void updateImage2(cv::Mat image);
  void updateHomography1(cv::Mat H);
  void updateHomography2(cv::Mat H);

  // Set OpenGL images
  void setupOpenGL(int width, int height);
  void draw();
  void cleanupOpenGL();

private:
  std::mutex m_mutex;

  cv::Mat convert(cv::Mat input, int width, int height);

  cv::Mat m_image1, m_image2;
  cv::Mat m_H1;
  cv::Mat m_H2;

  bool m_texture1Created = false;
  bool m_texture2Created = false;

  GLuint m_shaderProgram;
  GLuint m_textures[2];

};


#endif // VIDEO_PANORAMA_MATCHER_PAINTER_HPP
