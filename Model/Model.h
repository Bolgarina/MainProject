#pragma once

#include "./DllApi.h"
#include <Controller/ShapesReader.h>
#include <Mathematics/BaseMatrix.h>

class MODEL_API Model
{
public:
	Model(ShapesReader::ShList &i_shapes);
	~Model();

	const ShapesReader::ShList& getData() const;
	void addTransformation(const Math::BaseMatrix& i_transform);
	const Math::BaseMatrix& getTransformationMatrix() const;

private:
	Math::BaseMatrix transformationMatrix;
#pragma warning (push)
#pragma warning(disable:4251)
	ShapesReader::ShList shapes;
#pragma warning (pop)
};
