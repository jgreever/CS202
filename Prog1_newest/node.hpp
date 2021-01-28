#ifndef NODE_HPP
#define NODE_HPP

/** node.hpp
 * 
 *
 *    // Product Inventory Class and ADT (class inventory) (class inv_node) //
 * 1. You will need one data structure to handle the products at a distribution center by category. 
 *    An array of categories which each element has a linear linked list of the products of that category.
 *
 *    // Product Priority Class and ADT (class priority) (class pri_node) //
 * 2. You will need a data structure to help with the prioritization of products that need to be 
 *    ordered to avoid over traversal. This data structure can be of your choice. 
 *    Pick what you think is best for run time efficiency.
 *
 *    // Product Tracking Class and ADT (class tracking) (class tra_node) //
 * 3. Lastly, you will want a linear linked list for each product to map its path through the 
 *    system (so you can trace where it started and where it is today). 
 *    You will need one of these for every product!
 *
 * 4. Nodes must be implemented as a class (not a struct); no public data is allowed
 *
 * Data structures used: ARR, Queue/Stack, LLL
 *
 */

#include "product.hpp"


class inv_node : public category
{
	public:
		inv_node(const char *product, int location);
		inv_node(const category &);
		~inv_node();

		inv_node *&go_next();
		void set_next(inv_node *to_set);

	protected:
		inv_node *next;
};

class priority
{
	public:

	protected:

};

class pri_node : public priority
{

};

class tracking
{

};

class tra_node : public tracking
{

};


#endif