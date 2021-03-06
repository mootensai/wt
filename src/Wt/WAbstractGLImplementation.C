#include "Wt/WAbstractGLImplementation"

namespace Wt {

WAbstractGLImplementation::WAbstractGLImplementation(WGLWidget *glInterface)
  : glInterface_(glInterface),
    updateGL_(false),
    updateResizeGL_(false),
    updatePaintGL_(false),
    renderWidth_(0),
    renderHeight_(0),
    debugging_(false),
    webglNotAvailable_(this, "webglNotAvailable")
{
  webglNotAvailable_.connect(glInterface_, &WGLWidget::webglNotAvailable);
}

void WAbstractGLImplementation::repaintGL(WFlags<WGLWidget::ClientSideRenderer> which)
{
  if (which & WGLWidget::PAINT_GL)
    updatePaintGL_ = true;
  if (which & WGLWidget::RESIZE_GL)
    updateResizeGL_ = true;
  if (which & WGLWidget::UPDATE_GL)
    updateGL_ = true;
}

void WAbstractGLImplementation::layoutSizeChanged(int width, int height)
{
  renderWidth_ = width;
  renderHeight_ = height;
  sizeChanged_ = true;
}

}
