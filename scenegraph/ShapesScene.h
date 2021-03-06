#ifndef SHAPESSCENE_H
#define SHAPESSCENE_H

#include "OpenGLScene.h"

#include <memory>

#include <GL/glew.h>

#include "gl/datatype/FBO.h"
#include "Settings.h"
#include "shapes/Shape.h"
//#include "uniforms/uniformvariable.h"
#include "shapes/Bbox.h"

namespace CS123 { namespace GL {

    class Shader;
    class CS123Shader;
    class FullScreenQuad;

}}

class OpenGLShape;

/**
 *
 * @class ShapesScene
 *
 * A scene that is used to render a single shape.
 *
 * This scene has no notion of the scene graph, so it will not be useful to you in
 * assignments requiring the display of multiple shapes. Luckily, the first time you
 * will need that kind of functionality is in the Sceneview assignment... and we've
 * left that task up to you in the SceneviewScene class.
 *
 * By default, the ShapesScene displays only a single triangle. You'll need to do
 * a little work here to render your shapes. You could render the shapes directly
 * in this class, or you could pass the work on to one or more subclasses. Think
 * carefully about your design here - you'll be reusing your shapes multiple times
 * during this course!
 */
class ShapesScene : public OpenGLScene {
public:
    ShapesScene(int width, int height);
    virtual ~ShapesScene();

    virtual void render(SupportCanvas3D *context) override;
    virtual void settingsChanged() override;
    virtual void tick(float current) override;


protected:
    // Set the light uniforms for the lights in the scene. (The view matrix is used so that the
    // light can follows the camera.)
    virtual void setLights(const glm::mat4 viewMatrix);

    // Render geometry for Shapes and Sceneview.
    virtual void renderGeometry();

private:
    // Storage for private copies of the scene's light and material data. Note that these don't
    // need to be freed because they are VALUE types (not pointers) and the memory for them is
    // freed when the class itself is freed.

    // Added by Marc
    std::unique_ptr<CS123::GL::Shader> m_skyboxShader;
    std::unique_ptr<OpenGLShape> m_skyboxCube;
    void loadSkyboxShader();
    void renderSkybox(SupportCanvas3D *context);
    unsigned int setSkyboxUniforms(CS123::GL::Shader *shader);
    unsigned int m_cubeMapTexture;
    void loadJelloShader();
    std::unique_ptr<CS123::GL::CS123Shader> m_jelloShader;
    void renderJelloPass(SupportCanvas3D *context);
    bool m_usePhong;

    std::unique_ptr<CS123::GL::CS123Shader> m_phongShader;
    std::unique_ptr<CS123::GL::Shader> m_wireframeShader;
    std::unique_ptr<CS123::GL::Shader> m_normalsShader;
    std::unique_ptr<CS123::GL::Shader> m_normalsArrowShader;
    std::unique_ptr<CS123::GL::Shader> m_fsqShader;
    std::unique_ptr<CS123::GL::CS123Shader> m_testShader;
    CS123SceneLightData  m_light;
    CS123SceneMaterial   m_material;

    glm::vec4 m_lightDirection = glm::normalize(glm::vec4(1.f, -1.f, -1.f, 0.f));

    std::unique_ptr<OpenGLShape> m_shape;
    std::unique_ptr<Bbox> m_bbox;
    int m_shapeParameter1;
    int m_shapeParameter2;

    int m_width;
    int m_height;

    int m_simType;
    int m_shapeType;

    void clearLights();
    void loadPhongShader();
    void loadWireframeShader();
    void loadNormalsShader();
    void loadNormalsArrowShader();
    void loadTestShader();

    void renderPhongPass(SupportCanvas3D *context);
    void renderGeometryAsFilledPolygons();
    void renderWireframePass(SupportCanvas3D *context);
    void renderGeometryAsWireframe();
    void renderNormalsPass(SupportCanvas3D *context);
    void initializeSceneMaterial();
    void initializeSceneLight();
    void setPhongSceneUniforms();
    void setMatrixUniforms(CS123::GL::Shader *shader, SupportCanvas3D *context);
    void renderFilledPolygons();
    void renderNormals();
    void renderWireframe();
    void setSceneUniforms(SupportCanvas3D *context); 
};

#endif // SHAPESSCENE_H
