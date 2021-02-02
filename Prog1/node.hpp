#ifndef NODE_HPP
#define NODE_HPP

/** node.hpp
 * 
 * Justin Greever
 * CS202 - Program 1
 * 01/09/2021
 * 
 *
 *    // Product Inventory Class and ADT (class inventory) (class inv_node) //
 * 1. You will need one data structure to handle the products at a distribution
 *    center by category. 
 *    An array of categories which each element has a linear linked list of the
 *    products of that category.
 *
 *    // Product Priority Class and ADT (class priority) (class pri_node) //
 * 2. You will need a data structure to help with the prioritization of
 *    products that need to be 
 *    ordered to avoid over traversal. This data structure can be of your
 *    choice. 
 *    Pick what you think is best for run time efficiency.
 *
 *    // Product Tracking Class and ADT (class tracking) (class tra_node) //
 * 3. Lastly, you will want a linear linked list for each product to map its
 *    path through the system (so you can trace where it started and where it
 *    is today). You will need one of these for every product!
 *
 * 4. Nodes must be implemented as a class (not a struct); no public data is
 *    allowed
 *
 * Data structures used: ARR, Queue/Stack, LLL
 *
 */

#include "warehouse.hpp"

//Priority class node, this helps us to arrange items in an order
//so we can retrieve them from the facility without doing a bunch
//of traversal in the end.
class priority : public product
{
	public:
		priority();
		~priority();

		bool add_to_list(product &to_add);
		bool remove_from_list(char *product_name);
		bool clear_list();

	protected:
		product *an_item;
		priority *next;
};

//This is our node for tracking where the package has been
//and where it currently is at
class tracking
{
	public:

	protected:
		int tracking_stage;
		tracking *next;
};


#endif

