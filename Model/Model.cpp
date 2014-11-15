#include "./Model.h"
#include "./Point.h"



Model::Model(ShapesReader::ShList &i_shapes) : transformationMatrix(4), shapes(std::move(i_shapes))
{
	
}

Model::~Model()
{

}

const ShapesReader::ShList& Model::getData() const
{
	return shapes;
}

void Model::addTransformation(const Math::BaseMatrix& i_transform)
{
	transformationMatrix *= i_transform;
}

const Math::BaseMatrix& Model::getTransformationMatrix() const
{
	return transformationMatrix;
}