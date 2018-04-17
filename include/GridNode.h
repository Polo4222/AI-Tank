#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "node.h"

class GridNode : public sf::Drawable
{
private:

	std::vector<Node> m_pathList;

public:
	GridNode();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void GetPath(std::vector<Node> pathList);

};