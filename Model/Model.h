#pragma once

#include <Controller/ShapesReader.h>
#include <Mathematics/Matrix4f.h>

class Model
{
public:
	Model(ShapesReader::ShList &i_shapes);
	~Model();

	const ShapesReader::ShList& getData() const;
	const Math::Matrix4f getModelMatrix();

	void updateTranslation(const float dx, const float dy, const float dz);
	void updateScale(const float sx, const float sy, const float sz);
	void updateRotation(const float angleX, const float angleY, const float angleZ);

private:
	Math::Matrix4f TranslationMatrix;
	Math::Matrix4f ScaleMatrix;
	Math::Matrix4f RotationMatrix;

	ShapesReader::ShList shapes;
};
