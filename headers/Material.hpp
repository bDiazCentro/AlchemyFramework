#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

class Material
{
private:
	std::string vertShaderpath, fragShaderpath;
public:
	Material();
	Material(std::string vertPath, std::string fragPath);
	std::string VertShaderPath();
	void VertShaderPath(std::string path);
	std::string FragShaderPath();
	void FragShaderPath(std::string path);
};

#endif // !MATERIAL_H