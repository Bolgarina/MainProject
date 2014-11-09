uniform mat4 transformationMatrix;
attribute vec3 coord;

void main()
{
	gl_Position = transformationMatrix * vec4(coord, 1.0);
}