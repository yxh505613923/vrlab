#ifndef QTFUNCTIONWIDGET1_H
#define QTFUNCTIONWIDGET1_H
#include <glad/glad.h>
#include <learnopengl/model.h>//注意glad.h必须在qt关于opengl的头文件之前
//#include <learnopengl/shader.h>在model有 
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
//#include <QOpenGLFunctions>
//#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QDebug>
#include <QTimer>
#include <string>
#include "Camera.h"
#include "ArcBall.h"
#include "mass-spring.h"
#include "MassSpringCuda.cuh"
#include "Obj2MassSpring.h"
#include "UnProjectUtilities.h"
class QtFunctionWidget1 : public QOpenGLWidget//, protected QOpenGLFunctions
{
public:
	QtFunctionWidget1(std::string MP, std::string vSP, std::string fSP,QWidget* parent = nullptr);
	~QtFunctionWidget1() Q_DECL_OVERRIDE;

protected:
	virtual void initializeGL() Q_DECL_OVERRIDE;
	virtual void resizeGL(int w, int h) Q_DECL_OVERRIDE;
	virtual void paintGL() Q_DECL_OVERRIDE;
	void rendermodel();//导入的obj等格式模型的显示

	void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;
	void keyReleaseEvent(QKeyEvent* event) Q_DECL_OVERRIDE;
	void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
	void wheelEvent(QWheelEvent* event) Q_DECL_OVERRIDE;
private:
	//QOpenGLShaderProgram shaderProgram;
	//QOpenGLBuffer vbo;
	//QOpenGLVertexArrayObject vao;
	//QOpenGLTexture* texture1 = nullptr;
	//QOpenGLTexture* texture2 = nullptr;
	std::string ModelPath, vShaderPath, fShaderPath;
	Model *ourModel; 
	Shader *ourShader;
	Obj2MassSpring* ms;

	QTimer* m_pTimer = nullptr;
	int     m_nTimeValue = 0;

	// camera
	std::unique_ptr<Camera> camera;
	bool m_bLeftPressed;
	bool m_bRightPressed;
	bool m_CtrlPressed;
	bool m_CtrlMove;
	QPoint m_lastPos;
	CArcBall arcball;
	//matrix
	QMatrix4x4 curprojection,curmodel, curview;
	QVector3D curposition;
	//massspring system
	GLMmodel* ObjModel;
	MassSpring *m;
	MassSpringCuda* cm;
	int initpoint;
};

#endif // QTFUNCTIONWIDGET_H#pragma once