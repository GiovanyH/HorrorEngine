/*
	This is finally an entity system for my game engine
*/

#include "Entity.h"

// function to go through components and return the component with the id
Component* get_component(unsigned int component_id)
{
	// loop through the components to find the component with the id
	// component is defined inside of "entity.h" as std::vector<Component*> components; // vector of components

	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->get_id() == component_id)
		{
			return components[i];
		}
	}

	return nullptr;
}

void Component::set_id(unsigned int id)
{
	this->id = id;
}

unsigned int Component::get_id()
{
	return id;
}

// function to go through entities and return the entity with the id
Entity* get_entity(unsigned int entity_id)
{
	// loop through the entities to find the entity with the id
	// entities is defined inside of "entity.h" as std::vector<Entity*> entities; // vector of entities

	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->get_id() == entity_id)
		{
			return entities[i];
		}
	}

	return nullptr;
}

/*
	A component is going to be a class that is going to be attached to an entity
	Each component is going to have a unique id, and a pointer to the entity that it is attached to
*/
void Entity::add_component(unsigned int component_id)
{
	// component is defined inside of "entity.h" as std::vector<Component*> components; // vector of components

	Component* component = get_component(component_id);

	if (component != nullptr)
	{
		// add component
		components.push_back(component);
	}
	else
	{
		// error
		// TODO: return an error to engine log once the engine logs done
	}
}

void Entity::remove_component(unsigned int component_id)
{
	// component is defined inside of "entity.h" as std::vector<Component*> components; // vector of components

	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->get_id() == component_id)
		{
			components.erase(components.begin() + i);
			return;
		}
	}

	// error
	// TODO: return an error to engine log once the engine logs done
}

void Entity::add_child(unsigned int child_id)
{
	// child is just another entity
	// so we loop through entities to find the one with the id, and then set the parent id to the id of the entity

	Entity* child = get_entity(child_id);

	if (child != nullptr) {
		child->set_parent_id(id);
		children_id->at(++children_count) = child_id;
	}
}

void Entity::remove_child(unsigned int child_id)
{
	// child is just another entity
	// so we loop through entities to find the one with the id, and then set the parent id to NULL

	Entity* child = get_entity(child_id);

	if (child != nullptr) {
		child->set_parent_id(0);
		children_id->erase(children_id->begin() + child_id);
	}

	// remove child
}

unsigned int Entity::get_id()
{
	return id;
}

unsigned int Entity::get_parent_id()
{
	return parent_id;
}

unsigned int Entity::get_children_id(unsigned int index)
{
	return children_id->at(index);
}

unsigned int Entity::get_children_count()
{
	return children_id->size();
}

unsigned int Entity::get_component_id(unsigned int index)
{
	return components[index]->get_id();
}

unsigned int Entity::get_component_count()
{
	return components.size();
}

unsigned int Entity::get_layer()
{
	return layer;
}

unsigned int Entity::get_tag()
{
	return tag;
}

void Entity::set_global_position(gioVec2 position)
{
	global_position = position;
}

void Entity::set_local_position(gioVec2 position)
{
	local_position = position;
}

void Entity::set_size(gioVec2 size)
{
	this->size = size;
}

// TODO: calculations here
void Entity::set_rotation_degrees(gioVec2 rotation)
{
	this->rotation_degrees = rotation;
}

void Entity::set_rotation_radians(gioVec2 rotation)
{
	this->rotation_degrees = rotation;
}

void Entity::set_id(unsigned int id)
{
	this->id = id;
}

void Entity::set_parent_id(unsigned int parent_id)
{
	this->parent_id = parent_id;
}

void Entity::set_layer(unsigned int layer)
{
	this->layer = layer;
}

void Entity::set_tag(unsigned int tag)
{
	this->tag = tag;
}

gioVec2 Entity::get_global_position()
{
	return global_position;
}

gioVec2 Entity::get_local_position()
{
	return local_position;
}

gioVec2 Entity::get_size()
{
	return size;
}

gioVec2 Entity::get_rotation_degrees()
{
	return rotation_degrees;
}

// TODO: deg to rad
gioVec2 Entity::get_rotation_radians()
{
	return rotation_degrees;
}