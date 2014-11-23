#include "./Model.h"
#include "./Point.h"

using namespace Math;

Model::Model(ShapesReader::ShList &i_shapes) :
	TranslationMatrix(Matrix4f::createIdentity()), ScaleMatrix(Matrix4f::createIdentity()), RotationMatrix(Matrix4f::createIdentity()),
	shapes(std::move(i_shapes))
{
	
}

Model::~Model()
{

}

const ShapesReader::ShList& Model::getData() const
{
	return shapes;
}

const Matrix4f Model::getModelMatrix()
{
	return TranslationMatrix * RotationMatrix * ScaleMatrix;
}

void Model::updateTranslation(const float dx, const float dy, const float dz)
{
	TranslationMatrix = Matrix4f::createTranslation(dx, dy, dz);
}

void Model::updateScale(const float sx, const float sy, const float sz)
{
	ScaleMatrix = Matrix4f::createScale(sx, sy, sz);
}

void Model::updateRotation(const float angleX, const float angleY, const float angleZ)
{
	RotationMatrix  = Matrix4f::createRotation(angleX, 1.0f, 0.0f, 0.0f);
	RotationMatrix *= Matrix4f::createRotation(angleY, 0.0f, 1.0f, 0.0f);
	RotationMatrix *= Matrix4f::createRotation(angleZ, 0.0f, 0.0f, 1.0f);
}