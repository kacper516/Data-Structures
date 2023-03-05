#include "bstree.hpp"

bstree::bstree()
{
	this->root = nullptr;
}

node *bstree::getRoot()
{
	return root;
}

bool bstree::empty(node *p)
{
	if (p == nullptr)
		return true;

	return false;
}

bool bstree::leaf(node *n)
{
	// node is leaf only when node doesn't have left and right descendant
	if (n->getLeft() == nullptr && n->getRight() == nullptr)
		return true;

	return false;
}

void bstree::preorder(node *p)
{
	if (p != nullptr)
	{
		std::cout << p->getValue() << " ";
		preorder(p->getLeft());
		preorder(p->getRight());
	}
}

void bstree::inorder(node *p)
{
	if (p != nullptr)
	{
		inorder(p->getLeft());
		std::cout << p->getValue() << " ";
		inorder(p->getRight());
	}
}

void bstree::postorder(node *p)
{
	if (p != nullptr)
	{
		postorder(p->getLeft());
		postorder(p->getRight());
		std::cout << p->getValue() << " ";
	}
}

int bstree::size(node *p)
{
	if (p == nullptr)
		return 0;

	return 1 + size(p->getLeft()) + size(p->getRight());
}

int bstree::hight(node *p)
{
	if (p == nullptr)
		return -1;

	return 1 + std::max(hight(p->getLeft()), hight(p->getRight()));
}

void bstree::clear(node *p)
{
	if (p != nullptr)
	{
		if (p == root)
			root = nullptr; // set root to nullptr instead of delete it
		else
		{
			clear(p->getLeft());
			clear(p->getRight());
			delete p;
		}
	}
}

void bstree::insert(int x)
{
	if (root == nullptr)
	{
		root = new node(x, nullptr, nullptr, nullptr);
		return; // to end the function earlier
	}
	else
	{
		node *temp = root;
		while (true)
		{
			// check condition to choose path
			if (temp->getValue() > x) // left path
			{
				if (temp->getLeft() != nullptr) // if we can go to left side
				{
					temp = temp->getLeft();
					continue;
				}
				else
				{
					node *new_el = new node(x, nullptr, nullptr, temp);
					temp->setLeft(new_el);
					break; // to end function earlier
				}
			}
			else // right path
			{
				if (temp->getRight() != nullptr)
				{
					temp = temp->getRight();
					continue;
				}
				else
				{
					node *new_el = new node(x, nullptr, nullptr, temp);
					temp->setRight(new_el);
					break; // to end function earlier
				}
			}
		}
	}
}

node *bstree::search(int x)
{
	if (root == nullptr)
	{
		std::cout << "Drzewo puste " << std::endl;
		return nullptr;
	}

	node *temp = root;
	while (temp != nullptr && temp->getValue() != x)
	{
		if (temp->getValue() > x) // we choose left path
			temp = temp->getLeft();
		else
			temp = temp->getRight();
	}
	return temp; // it will be nullptr or node with value we search for
}

node *bstree::minimum(node *p)
{
	node *temp = p;
	while (temp->getLeft() != nullptr)
		temp = temp->getLeft();

	return temp;
}

node *bstree::maximum(node *p)
{
	node *temp = p;
	while (temp->getRight() != nullptr)
		temp = temp->getRight();

	return temp;
}

node *bstree::successor(node *p)
{
	if (p == nullptr)
		return nullptr; // if p node doesn't exist there is no way to find successor

	// there is 2 ways
	node *temp = p;
	// it's the lowest value of bigger value than p (only if right path exist)
	if (temp->getRight() != nullptr)
	{
		// we search for minimum value
		return minimum(temp->getRight());
	}
	// first parent which will have p value on his left side
	else
	{
		node *parent = temp->getParent();
		while (parent != nullptr && parent->getLeft() != temp)
		{
			temp = parent;
			parent = temp->getParent();
		}
		return parent;
	}
}

node *bstree::predecessor(node *p)
{
	if (p == nullptr)
		return nullptr; // if p node doesn't exist there is no way to find predecessor

	// there is 2 ways
	node *temp = p;
	// it's the biggest value of lower value than p (only if left path exist)
	if (temp->getLeft() != nullptr)
	{
		return maximum(temp->getLeft());
	}
	// first parent which will have p value on his right side
	else
	{
		node *parent = temp->getParent();
		while (parent != nullptr && parent->getRight() != temp)
		{
			temp = parent;
			parent = temp->getParent();
		}
		return parent;
	}
}

void bstree::del(node *p)
{
	// if root is empty or p is nullptr
	if (root == nullptr || p == nullptr)
	{
		if (root == nullptr)
			std::cout << "Tree is empty, there is nothing to delete" << std::endl;
		else
			std::cout << "p is nullptr, there is nothing to delete" << std::endl;
		return; // to end function earlier
	}
	// if p is leaf
	else if (leaf(p))
	{
		node *parent = p->getParent();
		if (parent == nullptr) // it means that we want to delete root
		{
			root = nullptr;
			return; // to end function earlier
		}

		// p is not root
		if (parent->getLeft() == p) // p is left son of his parent
			parent->setLeft(nullptr);
		else // p is right son
			parent->setRight(nullptr);

		delete p; // delete node p

		return; // to end function earlier
	}
	// p has got left or right subtree
	else if (p->getLeft() == nullptr && p->getRight() != nullptr || p->getLeft() != nullptr && p->getRight() == nullptr)
	{
		if (p->getLeft() != nullptr) // p has got left subtree
		{
			node *parent = p->getParent();
			node *son = p->getLeft();

			// p is root
			if (parent == nullptr)
			{
				// we delete root then replace it by left son of p
				root = son;
				son->setParent(nullptr);
				return; // to end function earlier
			}

			// p is not root, we connect p parent with left son of p, but we must check on which path is currently p
			son->setParent(parent);
			if (parent->getLeft() == p) // p is on left side
				parent->setLeft(son);
			else
				parent->setRight(son); // p is on right side

			delete p; // delete node p

			return; // to end function earlier
		}
		else // p has got right subtree
		{
			node *parent = p->getParent();
			node *son = p->getRight();

			// p is root
			if (parent == nullptr)
			{
				// we delete root then replace it by right son of p
				root = son;
				son->setParent(nullptr);
				return; // to end function earlier
			}

			// p is not root, we connect p parent with right son of p, but we must check on which path is currently p
			son->setParent(parent);
			if (parent->getLeft() == p)
				parent->setLeft(son);
			else
				parent->setRight(son);

			delete p; // delete node p

			return; // to end function earlier
		}
	}
	else // p has got 2 sons
	{
		// we can find successor or predecessor, with which we replace p value, then delete this successor or predecessor
		node *succ = successor(p);
		p->setValue(succ->getValue());

		del(succ); // we are using the function now on node succ
	}
}
