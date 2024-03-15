/*
	This is finally an entity system for my game engine
*/

// including vector
#include <vector>
#include "types/vec2.h"

class Entity
{
	private:
	// transformation
	gioVec2 global_position;
	gioVec2 local_position;
	gioVec2 size;
	gioVec2 rotation_degrees;

	unsigned int id;
	unsigned int parent_id;
	std::vector<unsigned int> children_id[100];
	unsigned int children_count;
	unsigned int components_id[100];
	unsigned int components_count;
	unsigned int layer;
	unsigned int tag;

	public:
	// ready
	virtual void ready();

	// update
	virtual void update();

	// render
	virtual void render();

	// add component
	void add_component(unsigned int component_id);

	// remove component
	void remove_component(unsigned int component_id);

	// add child
	void add_child(unsigned int child_id);

	// remove child
	void remove_child(unsigned int child_id);

	// get id
	unsigned int get_id();

	// get parent id
	unsigned int get_parent_id();

	// get children id
	unsigned int get_children_id(unsigned int index);

	// get children count
	unsigned int get_children_count();

	// get component id
	unsigned int get_component_id(unsigned int index);

	// get component count
	unsigned int get_component_count();

	// get layer
	unsigned int get_layer();

	// get tag
	unsigned int get_tag();

	// set global position
	void set_global_position(gioVec2 position);

	// set local position
	void set_local_position(gioVec2 position);

	// set size
	void set_size(gioVec2 size);

	// set rotation degrees
	void set_rotation_degrees(gioVec2 rotation);

	// set rotation radians
	void set_rotation_radians(gioVec2 rotation);

	// set id
	void set_id(unsigned int id);

	// set parent id
	void set_parent_id(unsigned int parent_id);

	// set layer
	void set_layer(unsigned int layer);

	// set tag
	void set_tag(unsigned int tag);

	// get global position
	gioVec2 get_global_position();

	// get local position
	gioVec2 get_local_position();

	// get size
	gioVec2 get_size();

	// get rotation degrees
	gioVec2 get_rotation_degrees();

	// get rotation radians
	gioVec2 get_rotation_radians();

	// constructor
	Entity();

	// destructor
	~Entity();

};

// Component class
class Component
{
	private:
	unsigned int id;
	unsigned int entity_id;

	public:
	// ready
	virtual void ready();

	// update
	virtual void update();

	// render
	virtual void render();

	// get id
	unsigned int get_id();

	// get entity id
	unsigned int get_entity_id();

	// set id
	void set_id(unsigned int id);

	// set entity id
	void set_entity_id(unsigned int entity_id);

	// constructor
	Component();

	// destructor
	~Component();

};

std::vector<Component*> components; // vector of components
std::vector<Entity*> entities; // vector of entities