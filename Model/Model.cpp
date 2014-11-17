#include "./Model.h"
#include "./Point.h"

Model::Model(ShapesReader::ShList &i_shapes) : transformationMatrix(Math::Matrix4f::createIdentity()), shapes(std::move(i_shapes))
{
	
}

Model::~Model()
{

}

const ShapesReader::ShList& Model::getData() const
{
	return shapes;
}

void Model::addTransformation(const Math::Matrix4f& i_transform)
{
	transformationMatrix *= i_transform;
}

const Math::Matrix4f& Model::getTransformationMatrix() const
{
	return transformationMatrix;
}