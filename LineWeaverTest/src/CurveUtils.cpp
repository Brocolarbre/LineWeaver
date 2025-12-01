#include "CurveUtils.hpp"

#include <fstream>
#include <iostream>

void CurveUtils::printPoint(const lw::Point& point)
{
	std::cout << point.x << ' ' << point.y << ' ' << point.z << '\n';
}

void CurveUtils::printCurve(const lw::Curve& curve)
{
	for (const lw::Point& point : curve)
		printPoint(point);

	std::cout << std::flush;
}

lw::Curve CurveUtils::readCurveCsv(const std::string& path)
{
	std::ifstream file(path);

	if (!file.is_open())
	{
		std::cerr << "Failed to read file at " << path << std::endl;
		return {};
	}

	std::string line;
	lw::Curve curve;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		lw::Point point(0.0f);

		for (unsigned int i = 0; i < 3; ++i)
		{
			size_t separatorPosition = line.find(',');
			point[i] = std::stof(line.substr(0, separatorPosition));
			line.erase(0, separatorPosition + 1);
		}

		curve.push_back(point);
	}

	file.close();

	return curve;
}

void CurveUtils::writeCurveCsv(const std::string& path, const lw::Curve& curve)
{
	std::ofstream file(path);

	file << "x,y,z" << std::endl;

	if (!file.is_open())
	{
		std::cerr << "Failed to write file at " << path << std::endl;
		return;
	}

	for (const lw::Point& point : curve)
		file << point.x << ',' << point.y << ',' << point.z << std::endl;

	file.close();
}