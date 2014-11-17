#pragma once

#include "./DllApi.h"
#include <Controller/ShapesReader.h>
#include <Mathematics/Matrix4f.h>

class MODEL_API Model
{
public:
	Model(ShapesReader::ShList &i_shapes);
	~Model();

	const ShapesReader::ShList& getData() const;
	void addTransformation(const Math::Matrix4f& i_transform);
	const Math::Matrix4f& getTransformationMatrix() const;

private:
	Math::Matrix4f transformationMatrix;
#pragma warning (push)
#pragma warning(disable:4251)
	ShapesReader::ShList shapes;
#pragma warning (pop)
};
