#ifndef GLK_TRAJECTORY_HPP
#define GLK_TRAJECTORY_HPP

#include <functional>

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <glk/drawable.hpp>
#include <glk/api_export.hpp>
namespace glk {

class ThinLines;

class GLK_API Trajectory : public glk::Drawable {
public:
  Trajectory(const std::vector<Eigen::Isometry3f, Eigen::aligned_allocator<Eigen::Isometry3f>>& trajectory);
  Trajectory(int num_frames, const std::function<Eigen::Isometry3f(int)>& adapter);

  virtual ~Trajectory();

  virtual void draw(glk::GLSLShader& shader) const override;

private:
  std::unique_ptr<glk::ThinLines> lines;
  std::vector<Eigen::Isometry3f, Eigen::aligned_allocator<Eigen::Isometry3f>> trajectory;
};
}


#endif