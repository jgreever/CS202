#include "node.hpp"


class bst
{
    public:
		bst();
		bst(const node &);
		~bst();

		int insert(node &to_add);
		int remove(node *&to_remove);
		bool search(node *to_search);
		void display() const;
    private:

    protected:
        node *root;
};
