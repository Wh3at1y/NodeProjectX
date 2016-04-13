/*
 * CTECBinaryTree.h
 *
 *  Created on: Apr 11, 2016
 *      Author: smon7958
 */

#ifndef MODEL_CTECBINARYTREE_H_
#define MODEL_CTECBINARYTREE_H_
#include "TreeNode.h"
namespace CTECData
{
	template<class Type>
	class CTECBinaryTree
	{
		private:
			int size;
			TreeNode<Type> * root;
			int height;
			bool balanced;
			bool contains(Type value, CTECBinaryTree<Type> * currentTree);

		public:
			CTECBinaryTree();
			~CTECBinaryTree();
			bool insert(const Type& value);
			Type remove(const Type& value);
			bool contains(Type value);

			int getSize();
			int getHeight();
			bool isBalanced();
			TreeNode<Type> * getRoot();
            void preorderTraversal(CTECBinaryTree<Type> * currentTree);
            void inorderTraversal(CTECBinaryTree<Type> * currentTree);
            void postorderTraversal(CTECBinaryTree<Type> * currentTree);
	};

}

#endif /* MODEL_CTECBINARYTREE_H_ */
